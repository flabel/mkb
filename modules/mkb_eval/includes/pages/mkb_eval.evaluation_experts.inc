<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for evaluation_experts_page_template template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $eval_conf_nid
 *   Evaluation configuration nid.
 * @param $fid
 *   Evaluation filter nid.
 * @return template
 *   The template evaluation_experts_page_template is called with $variables.
 */
function mkb_eval_evaluation_experts($cid, $eval_conf_nid, $fid){

  // Load groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid, $eval_conf_nid);

  // Evaluation configuration
  $eval_conf = node_load($eval_conf_nid);
  $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);

  // Header
  $header = array('ID', 'Application', 'Expert/Rapporteur', 'Status');

  // Images - Conflict
  $con_yes_img = mkb_eval_get_img('con_yes.png', 'Conflict declared', 'Conflict declared');
  $con_no_img = mkb_eval_get_img('con_no.png', 'No conflict declared', 'No conflict declared');
  $con_missing_img = mkb_eval_get_img('con_missing.png', 'Conflict missing', 'Conflict missing');

  // Images - Evaluation
  $eval_missing_img = mkb_eval_get_img('eval_missing.png', 'Evaluation is missing', 'Evaluation is missing');
  $eval_created_img = mkb_eval_get_img('eval_approved.png', 'Evaluation is complete', 'Evaluation is complete');
  $eval_approved_img = mkb_eval_get_img('eval_approved.png', 'Evaluation is approved', 'Evaluation is approved');
  $eval_eval_approved_wc_img = mkb_eval_get_img('eval_approved_wc.png', 'Evaluation is approved with conditions', 'Evaluation is approved with conditions');
  $eval_not_approved_img = mkb_eval_get_img('eval_not_approved.png', 'Evaluation is incomplete', 'Evaluation is incomplete');

  // Rows
  $rows = array();
  foreach ($groups as $gid => $group){
    // Get project_info
    $project_info = $group->applications['application_project_info'];
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
    $acronym = $project_info_wrapper->field_app_acronym->value();

    // Get expert evaluators
    $expert_evaluators = NULL;
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'expert_evaluators')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
      ->fieldCondition('field_eval_conf', 'target_id', $eval_conf_nid, '=');
    $result = $query->execute();

    if (isset($result['node'])) {
      $expert_evaluators_nids = array_keys($result['node']);
      $expert_evaluators = node_load($expert_evaluators_nids[0]);
    }

    // Get all evaluations for this group and eval_conf
    $group_evaluations = NULL;
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'evaluation')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
      ->fieldCondition('field_eval_conf', 'target_id', $eval_conf_nid, '=');
    $result = $query->execute();

    if (isset($result['node'])) {
      $group_evaluation_nids = array_keys($result['node']);
      $group_evaluations = entity_load('node', $group_evaluation_nids);
    }

    // Get all Declaration of no conflict for this group
    $group_conflicts = NULL;
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'evaluation_conflict')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $gid, '=');
    $result = $query->execute();

    if (isset($result['node'])) {
      $group_conflict_nids = array_keys($result['node']);
      $group_conflicts = entity_load('node', $group_conflict_nids);
    }

    $evaluator_str = '<ul>';
    $status = '<b>Complete</b>';
    if(isset($expert_evaluators)){
      $expert_evaluators_wrapper = entity_metadata_wrapper('node', $expert_evaluators);

      $group_str = l($acronym, 'node/' . $expert_evaluators_wrapper->getIdentifier() . '/edit/' . $group->nid .
          '/' . $eval_conf_nid, array('query' => drupal_get_destination()));

      foreach ($expert_evaluators_wrapper->field_expert_application_id->getIterator() as $delta => $expert_application_wrapper) {
        // Expert application
        $expert_application = $expert_application_wrapper->value();

        // Filter expert applications by eval_conf and selected
        $expert_application_eval_conf_nids = $expert_application_wrapper->field_eval_conf_id->raw();
        $selected_list = $expert_application_wrapper->field_expert_selected->value();

        if(!$selected_list) $selected_list = array();
        if(in_array($eval_conf_nid, $expert_application_eval_conf_nids) && in_array($eval_conf_nid, $selected_list)){

          // Expert application user
          $evaluator = $expert_application_wrapper->field_expert_usr->value();
          $name = ($evaluator->realname != '') ? $evaluator->realname : $evaluator->name;
          $evaluator_str .= '<li>' . $name . ': ';

          // Add image to evaluator_str according to Declaration of no conflict
          $conflict_exist = FALSE;
          if(isset($group_conflicts)){
            foreach ($group_conflicts as $group_conflict){
              // Evaluator has created a Declaration of no conflict
              if($evaluator->uid == $group_conflict->uid){
                $conflict_exist = TRUE;
                $conflict_exist_conflict = $group_conflict;
              }

            }

            if($conflict_exist){
              $conflict_exist_conflict_wrapper = entity_metadata_wrapper('node', $conflict_exist_conflict);
              $conflict = $conflict_exist_conflict_wrapper->field_con_conflict->value();

              if($conflict == 'Yes'){
                // Conflict declared as yes: Add image conlict link
                $evaluator_str .= ' ' . mkb_eval_link_img($con_yes_img, $conflict_exist_conflict, $gid);
              }
              else{
                // Conflict declared as no: Add no conflict img
                $evaluator_str .= ' ' . mkb_eval_link_img($con_no_img, $conflict_exist_conflict, $gid);
              }
            }
            else{
                $evaluator_str .= $con_missing_img;
            }
          }
          else{
            $evaluator_str .= $con_missing_img;
          }

          if(isset($group_evaluations)){
            // Add image to evaluator_str according to evaluations
            $eval_exist = FALSE;
            foreach ($group_evaluations as $group_evaluation){
              if($evaluator->uid == $group_evaluation->uid){
                $eval_exist = TRUE;
                $eval_exist_evaluation = $group_evaluation;
              }
            }

            if($eval_exist){
              $eval_exist_evaluation_wrapper = entity_metadata_wrapper('node', $eval_exist_evaluation);
              $eval_submit = $eval_exist_evaluation_wrapper->field_eval_submit->value();

              if($eval_submit == 1) {
                $evaluator_str .= ' ' . mkb_eval_link_img($eval_created_img, $eval_exist_evaluation, $gid);
              }
              elseif($eval_submit == 0){
                $evaluator_str .= ' ' . mkb_eval_link_img($eval_not_approved_img, $eval_exist_evaluation, $gid);
                $status = '<b>Incomplete</b>';
              }
            }
            else{
              $evaluator_str .= ' ' . $eval_missing_img;
              $status = '<b>Incomplete</b>';
            }
          }
          else{
            $evaluator_str .= ' ' . $eval_missing_img;
            $status = '<b>Incomplete</b>';
          }
        }
        else{
          $status = '<b>Incomplete</b>';
        }
      }
      $evaluator_str .= '</ul>';
    }
    else{
      $group_str = l($acronym, 'node/add/expert-evaluators/' . $group->nid . '/' . $eval_conf_nid,
          array('query' => drupal_get_destination()));
      $status = '<b>Incomplete</b>';
    }

    // Link to proposal evalutions
    $group_evaluations = l($group->nid, 'eval/group/' . $gid,
          array('query' => drupal_get_destination()));

    // Add row
    $rows[$gid] = array($group_evaluations, $group_str, $evaluator_str, $status);
  }

  $variables['images'] = array(
      'con_yes_img' => $con_yes_img,
      'con_no_img' => $con_no_img,
      'con_missing_img' => $con_missing_img,
      'eval_missing_img' => $eval_missing_img,
      'eval_created_img' => $eval_created_img,
      'eval_approved_img' => $eval_approved_img,
      'eval_eval_approved_wc_img' => $eval_eval_approved_wc_img,
      'eval_not_approved_img' => $eval_not_approved_img,
      );
  $variables['header'] = $header;
  $variables['rows'] = $rows;
  $variables['count'] = count($rows);
  return theme('evaluation_experts_page_template', $variables);
}

function mkb_eval_get_img($filename, $title, $alt){
  $variables = array(
    'path' => drupal_get_path('module', 'mkb_eval') . '/img/' . $filename,
    'alt' => $alt,
    'title' => $title,
    'width' => '14px',
    'height' => '14px',
    'attributes' => array('class' => 'experts_img'),
  );
  return theme('image', $variables);
}

function mkb_eval_link_img($img, $node, $gid){
  $img = l($img, 'node/' . $node->nid . '/edit/' . $gid,
    array(
    'attributes' => array(
      'class' =>'link-image'),
      'html' => true,
      'query' => drupal_get_destination()
    )
  );
  return $img;
}
