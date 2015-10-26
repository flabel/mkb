<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for evaluation_status_page template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $eid
 *   Evaluation configuration node id.
 * @return template
 *   The template evaluation_status_page_template is called with $variables.
 */
function evaluation_status_page_function($cid, $fid, $eid){
  $account = $GLOBALS['user'];  
  
  // Load Evaluation configuration
  $eval_conf = node_load($eid);
  $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
  $eval_conf_type = $eval_conf_wrapper->field_eval_conf_type->name->value();

  // Load filtered groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid, $eid, NULL);

  // Build header (All funding agencies)
  $funding_agencies = mkb_eval_get_all_funding_agencies($cid);

  // Build content
  $content = array();
  foreach ($groups as $gid => $group){
    // Get applications
    $applications = $group->applications;

    $content[$gid] = array(
        'gid' => $gid,
        'acronym' => mkb_eval_get_acronym($applications['application_project_info']),
        );

    $groups[$gid]->funder_pages = array();
    if(isset($applications['application_partner_budget'])){
      foreach ($applications['application_partner_budget'] as $budget_id){
        $funder_page = mkb_eval_get_funder_page($budget_id);
        if(!in_array($funder_page, $groups[$gid]->funder_pages)) {
          $groups[$gid]->funder_pages[] = $funder_page;
        }
      }
    }
    
    if($eval_conf_type == 'Quality'){
      foreach ($funding_agencies as $fid => $funding_agency){
        $content[$gid][$fid] = "Pending";

        $funder_page_uids = array_merge(mkb_eval_get_uids_manager_funder_pages($fid),
            mkb_eval_get_uids_evaluator_funder_pages($fid));
            
        $evaluation = mkb_eval_get_evaluation($funder_page_uids, $eid, $gid);
        if(isset($evaluation->nid)){
          $recommendation = mkb_eval_get_recommendation_value($evaluation);
          $content[$gid][$fid] = $recommendation;
          $groups[$gid]->eval_id = $evaluation->nid;
        }
      }
    }
    else{
      foreach ($funding_agencies as $fid => $funding_agency){
        $content[$gid][$fid] = "Nothing";
        if(in_array($fid, $groups[$gid]->funder_pages)){
          $content[$gid][$fid] = "Pending";
          $funder_page_uids = array_merge(mkb_eval_get_uids_manager_funder_pages($fid),
              mkb_eval_get_uids_evaluator_funder_pages($fid));

          $evaluation = mkb_eval_get_evaluation($funder_page_uids, $eid, $gid);
          if(isset($evaluation->nid)){
            $recommendation = mkb_eval_get_recommendation_value($evaluation);
            $content[$gid][$fid] = $recommendation;
            $groups[$gid]->eval_id = $evaluation->nid;
          }
        }
      }   
    } 
  }

//   $variables['cid'] = $cid;
  $variables['header'] = array_merge(array("", ""), $funding_agencies);
  $variables['groups'] = $groups;
  $variables['content'] = $content;
  return theme('evaluation_status_page_template', $variables);
}
