<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.custom_views');
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.custom_filters');

/**
 * Generates content for evaluation_page template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $vid
 *   View id: Determines which fields are in content
 * @param $arg3 (optional)
 *   Evaluation configuration node id OR Filter id
 * @param $arg4 (optional)
 *   Filter id: Determines which groups are in the content
 * @return template
 *   The template evaluation_page_template is called with $content.
 */
function mkb_pm_evaluation_overview($cid, $vid, $arg3 = NULL, $arg4 = NULL){
  // GLOBALS
  global $user;
  $base_url = $GLOBALS['base_url'];

  // Determine optional arguments
  $eid = NULL;
  $fid = NULL;
  if($arg3 !== NULL){
    $arg3_strings = explode("=", $arg3);
    if($arg3_strings[0] == "eid"){
      $eid = $arg3_strings[1];
    }
    elseif($arg3_strings[0] == "fid"){
      $fid = $arg3_strings[1];
    }
    else{
      drupal_set_message(t('Invalid third argument. Valid argument example: base_url/eval/cid/vid/eid=x'));
    }
  }
  if($arg4 !== NULL){
    $arg4_strings = explode("=", $arg4);
    if($arg4_strings[0] == "fid"){
      $fid = $arg4_strings[1];
    }
    else{
      drupal_set_message(t('Invalid fourth argument. Valid argument example: base_url/eval/cid/vid/eid=x/fid=y'));
    }
  }

  // Config evaluation node
  if($eid !== NULL){
    $eval_conf = node_load($eid);
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
    $eval_conf_type_term = $eval_conf_wrapper->field_eval_conf_type->value();
  }

  // Get Predefined views from mkb_eval.custom_views.inc
  $view_types = mkb_eval_get_custom_views();

  // Set the current view
  $view_node = node_load($vid);
  $view = array();
  $labels = array();
  $call = node_load($cid);
  $page_title = $call->title;
  $page_description = '';
  if($view_node){
    //$page_title = $view_node->title;
    $fields_info = field_info_instances('node', $view_node->type);

    // Sort view fields according to default diaplay weights
    uasort($fields_info, function($a, $b) {
      $a_weight = (is_array($a) && isset($a['display']['default']['weight'])) ? $a['display']['default']['weight'] : 0;
      $b_weight = (is_array($b) && isset($b['display']['default']['weight'])) ? $b['display']['default']['weight'] : 0;

      if ($a_weight == $b_weight) {
        return 0;
      }

      return ($a_weight < $b_weight) ? -1 : 1;
    });

    foreach ($fields_info as $field_name => $field_info){
      $field_items = field_get_items('node', $view_node, $field_name);
      if($field_name == 'field_view_description'){
        $page_description = isset($field_items[0]['value']) ? $field_items[0]['value'] : '';
      }
      else{
        // Remove field_view_ from key
        $view_key = substr($field_name, 11);
        $view[$view_key] = isset($field_items[0]['value']) ? $field_items[0]['value'] : 0;
        $labels[$view_key] = isset($fields_info[$field_name]['label']) ? $fields_info[$field_name]['label'] : '';
      }
    }
  }
  else{
    $variables['content'] = FALSE;
    return theme('evaluation_page_template', $variables);
  }

  // Build headers for fields that are true in current view (view_keys)
  $view_keys = array_keys($view, 1, FALSE);
  $header = array();
  foreach ($view_keys as $key){
    $header[] = $labels[$key];
  }

  // Get groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid, $eid);

  // Initialize content with empty values from view_keys
  $content = mkb_eval_build_content($groups, $view, $view_keys);
  
  // Determine which kind of access current user has
  $access = 'authenticated';
  if(evaluation_page_access($cid)) $access = 'eval';
  if(mkb_eval_experts_page_access($cid)) $access = 'expert';
  
  // Run through groups and add fields to content
  foreach ($groups as $gid => $group){
    // Get applications array from group
    $applications = $group->applications;
    $project_info = node_load($applications['application_project_info']);
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);

    // Get evaluation and configuration
    $evaluation = isset($group->evaluation) ? $group->evaluation : NULL;
    if(isset($evaluation)) $evaluation_wrapper = entity_metadata_wrapper('node', $evaluation);

    // ADD FIELDS ACCORDING TO VIEW
    // Acronym
    if($view['acronym']){
      $acronym_text = mkb_eval_get_acronym($applications['application_project_info']);
      if($access == 'authenticated') $acronym = $acronym_text;
      else $acronym = l($acronym_text, $base_url . '/groups/workspace/application_page/' . $gid);
      $content[$gid]['acronym'] = $acronym;
    }

    // Title
    if($view['title']){
      $title = mkb_eval_get_title($applications['application_project_info']);
      $content[$gid]['title'] = $title;
    }

    // Submitted
    if($view['submitted']){
      $is_submitted = mkb_eval_get_submitted($applications['application_project_info']);
      if($is_submitted == 0) $submitted = "No";
      if($is_submitted == 1) $submitted = "Yes";
      $content[$gid]['submitted'] = $submitted;
    }

    // Coordinator (The project-coordinator is the only role who can create a application-project-info).
    if($view['coordinator']){
      $this_group = node_load($gid);
      $coordinator = user_load($this_group->uid);
      if(isset($coordinator)){
        $content[$gid]['coordinator'] = l($coordinator->realname, $base_url . '/user-profile/' . $coordinator->uid);
      }
      else{
        $content[$gid]['coordinator'] = '';
      }
    }

    // DOW
    if($view['dow']){
      $dow = mkb_eval_get_dow($applications['application_project_info']);
      $content[$gid]['dow'] = $dow;
    }

    // Topics
    if($view['topics']){
      $topics = mkb_eval_get_topics($applications['application_project_info']);
      $content[$gid]['topics'] = $topics;
    }

    // Country
    if($view['country']){
      $country = '';
      if(!empty($applications['application_partner_info'])){
        $country = mkb_eval_get_country($gid);
      }
      $content[$gid]['country'] = $country;
    }

    // Total budget && Total requested
    if($view['total_budget'] && $view['total_requested']){
      $total_budget = 0;
      $total_requested = 0;
      if(isset($applications['application_partner_budget'])){
        foreach ($applications['application_partner_budget'] as $nid){
          $budget_table = mkb_application_get_budget_table($nid);
          $sum_index = count($budget_table)-1;
          $total_budget += $budget_table[$sum_index][count($budget_table[$sum_index])-2];
          $total_requested += $budget_table[$sum_index][count($budget_table[$sum_index])-1];
        }
      }
      else{
        $total_budget = '';
        $total_requested = '';
      }
      if($total_budget == 0) $total_budget = '';
      if($total_requested == 0) $total_requested = '';
      $content[$gid]['total_budget'] = $total_budget;
      $content[$gid]['total_requested'] = $total_requested;
    }

    // Status
    if($view['status']){
      $status = 'Incomplete';
      if(isset($evaluation)){
        $field_items = field_get_items('node', $evaluation, 'field_eval_submit');
        if(isset($field_items[0])){
          $status = ($field_items[0]['value'] == 1) ? 'Complete' : 'Incomplete';
        }
      }
      else{
        $status = 'Pending';
      }
      $content[$gid]['status'] = $status;
    }

    // Recommendation
    if($view['recommendation']){
      $recommendation = 'Pending';
      if(isset($evaluation)){
        $field_items = field_get_items('node', $evaluation, 'field_eval_recommendation');
        $field_value = field_view_value('node', $evaluation, 'field_eval_recommendation', $field_items[0]);
        $recommendation = $field_value['#markup'];
      }
      $content[$gid]['recommendation'] = $recommendation;
    }

    // Link
    if($view['link']){
      $link = '';
      if(isset($evaluation)){
        $link = l(t('Edit'), $base_url . '/node/' . $evaluation->nid . '/edit',
            array('query' => drupal_get_destination()));
      }
      else{
        if($eval_conf_type_term->name == 'Expert' || $eval_conf_type_term->name == 'Rapporteur'){
            if($view['conflict']){
              $conflict_nid  = mkb_eval_get_eval_conflict($gid, $user->uid);
              // Conflict node exist
              if($conflict_nid){
                $conflict_node = node_load($conflict_nid);
                $is_conflict = isset($conflict_node->field_con_conflict[LANGUAGE_NONE][0]['value']) ?
                  $conflict_node->field_con_conflict[LANGUAGE_NONE][0]['value'] : 0;

                // There is a conflict
                if($is_conflict == 0){
                   $link = l('Create', $base_url . '/node/add/evaluation/'. $gid . '/' . $eid,
                    array('query' => drupal_get_destination()));
                }
                // There is no conflict
                else{
                  $link = '';
                }
                $conflict = '';
              }
              // Conflict node does not exist
              else{
                $link = '';
                $conflict = l('Create', $base_url . '/node/add/evaluation-conflict/' . $gid,
                  array('query' => drupal_get_destination()));
              }
              $content[$gid]['conflict'] = $conflict;
            }
        }
        // All other Evalation types than Expert and Rapporteur
        else{
          $link = l('Create', $base_url . '/node/add/evaluation/'. $gid . '/' . $eid,
                    array('query' => drupal_get_destination()));
        }
      }
      $content[$gid]['link'] = $link;
    }

    // Evaluations
    if($view['evaluations']){
      $evaluations = mkb_eval_get_evaluations($gid);
      if(!empty($evaluations)) $evaluations = l('evaluations', $base_url . '/eval/group/' . $cid . '/' . $gid);
      else $evaluations = "";
      $content[$gid]['evaluations'] = $evaluations;
    }

    // Score
    if($view['score']){
      $score = '';
      if(isset($evaluation) && isset($eval_conf)){
        $eval_conf_score = $eval_conf_wrapper->field_conf_score->value();
        if($eval_conf_score == 1){
          $eval_score = $evaluation_wrapper->field_eval_score->value();
          $content[$gid]['score'] = isset($eval_score) ? $eval_score : '';
        }
      }
    }
    
    // All PDF
    if($view['all_pdf']){
      $pdf_link = mkb_eval_get_stage_pdf_link($gid);
      $content[$gid]['all_pdf'] = $pdf_link;
    }    
    
    // Stage 1 PDF
    if($view['s1_pdf']){
      $pdf_link = mkb_eval_get_stage_pdf_link($gid, 1);
      $content[$gid]['s1_pdf'] = $pdf_link;
    }
    
    // Stage 1 PDF
    if($view['s2_pdf']){
      $pdf_link = mkb_eval_get_stage_pdf_link($gid, 2);
      $content[$gid]['s2_pdf'] = $pdf_link;
    }
    
    // Rapport link
    if($view['rapport']){
      // Get Application project publish      
      $query = new EntityFieldQuery();

      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'application_project_publish')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('og_group_ref', 'target_id', $gid)
        ->addMetaData('account', user_load(1)); // Run the query as user 1.

      $result = $query->execute();
      // If the group does not have a application_project_publish
      if (empty($result['node'])){
        unset($content[$gid]);
        continue;
      }
      
      $submitted_1 = $project_info_wrapper->field_app_submitted->value();
      $selected_1 = $project_info_wrapper->field_app_selected_1->value();
      $selected_2 = $project_info_wrapper->field_app_selected_2->value();
      
      // Get Application publish configurations
      $query = new EntityFieldQuery();

      $query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'application_publish_conf')
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldCondition('field_call_id', 'target_id', $cid)
        ->addMetaData('account', user_load(1)); // Run the query as user 1.

      $result = $query->execute();

      // Add rapport links to array
      $rapport_links = array();
      if (isset($result['node'])) {
        $nids = array_keys($result['node']);
        $nodes = entity_load('node', $nids);
        
        foreach($nodes as $nid => $node){
          $node_wrapper = entity_metadata_wrapper('node', $node);
          $is_open = $node_wrapper->field_apc_open_close->value();
          $is_webform = !empty($node->field_apc_webform_ids);
          if($is_open && !$is_webform){
            // Get status and check if application should have menu for this apc
            $status = $node_wrapper->field_apc_project_status->value();
            $status_ok = FALSE;
            $rappport_link_text = 'Read more';
            if($status == 0 && $submitted_1 == 1) $status_ok = TRUE;
            if($status == 1 && $selected_1 == 1) $status_ok = TRUE;
            if($status == 2 && $selected_2 == 1) $status_ok = TRUE;

            if($status_ok){
              $rapport_links[] = l($rappport_link_text,  'groups/workspace/rapport_comment/' . $gid . '/' . $nid, 
                array('query' => drupal_get_destination()));
            }
          }
        }
        
        // Theme links
        $rapport = theme("item_list", array(
           'items' => $rapport_links,
           'type' => 'ul',
           'title' => '',
        ));
      }        

      // Add links to content
      $content[$gid]['rapport'] = $rapport;
    }       
    
  } // END FOREACH GROUP


  // Set sessions
  $_SESSION["mkb_eval"] = array(
      'cid' => $cid,
      'vid' => $vid,
      'eid' => isset($eid) ? $eid : '',
      'fid' => isset($fid) ? $fid : '',
      );

  $variables['page_title'] = $page_title;
  $variables['page_description'] = $page_description;
  $variables['count'] = count($content);
  $variables['header'] = $header;
  $variables['content'] = $content;

  return theme('rapport_overview_template', $variables);
}
