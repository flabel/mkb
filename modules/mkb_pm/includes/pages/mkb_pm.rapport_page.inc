<?php
module_load_include('inc', 'mkb_pm', 'includes/mkb_pm.helper');

/**
 * @param gid
 *  Group node id
 * @param apcid
 *  Application project configuration node id
 * @return template
 *  Rendered template rapport_template
 */
function mkb_pm_application_rapport($gid, $apcid){
  $apc = node_load($apcid);
  $apc_wrapper = entity_metadata_wrapper('node', $apc);
  
  //Group users and nodes
  $variables = mkb_application_get_group_user_and_roles($gid);

  //Group
  $group = node_load($gid);
  $variables = $variables + array("group" => $group);
  
  // Get call-main-page nid
  $cid = mkb_application_get_call_main_nid($gid);
  
  // Get all funding agencies org name
  $fa_org_names = mkb_pm_get_all_funding_agency_names($cid);
  
  //Build applications array with all data related to partners
  $applications = array();
  $pri = false;
  $pai = false;
  $pab = false;
  foreach ($variables['rows'] as $row){
    if($row->entity_type == "user" && ($row->role == "project coordinator" || $row->role == "project partner")){
      $row_profile = profile2_by_uid_load($row->uid, 'main');
      if($row_profile){
        $row_profile_wrapper = entity_metadata_wrapper('profile2', $row_profile);
        $row_org = $row_profile_wrapper->field_my_organisation->value();
        if(isset($row_org)){
          $row_org_wrapper = entity_metadata_wrapper('node', $row_org);
          $user_org_name = $row_org_wrapper->field_org_name->value->value(array('sanitize' => TRUE));
        }
        else $user_org_name = 'Organisation missing in profile';
      }
      else $user_org_name = 'Profile missing';

      //$user_my_org = mkb_application_get_my_org($row->uid);
      $applications[$row->uid] = array(
          "pri" => FALSE,
          "pai" => FALSE,
          "pab" => FALSE,
          "user" => array(
            "realname" => $row->realname,
            "country" => $row->country,
            "user_org_name" => $user_org_name,
              ),
          );
    }
    elseif($row->entity_type == "node"){
      if($row->type == "application_partner_info"){
        $partner_info = (array)node_load($row->nid);
        $applications[$row->author_uid]['partner_info'] = $partner_info;
        $applications[$row->author_uid]['pai'] = true;
        $pai = true;
      }
      elseif($row->type == "application_partner_budget"){
        $partner_budget = (array)node_load($row->nid);
        $funder_page_id = $partner_budget['field_funder_page']['und'][0]['target_id'];
        $funder_page = (array)node_load($funder_page_id);
        $fa_org_name = (array_key_exists($funder_page_id, $fa_org_names)) ? $fa_org_names[$funder_page_id] : 'None';
        $applications[$row->author_uid]['fa_org_name'] = $fa_org_name;
        
        $funding_page_title = $funder_page['title'];
        $funder_page = (array)node_load($funder_page_id);
        $budget_table = mkb_application_get_budget_table($row->nid);
        $applications[$row->author_uid]['partner_budget'] = $partner_budget;
        $applications[$row->author_uid]['budget_table'] = $budget_table;
        $applications[$row->author_uid]['funding_page_title'] = $funding_page_title;
        $applications[$row->author_uid]['pab'] = true;
        $pab = true;
      }
      elseif($row->type == "application_project_info"){
        $pri = true;
      }
    }
  }
  $variables = $variables + array("applications" => $applications);

  //Project info
  if($pri){
    //Project info - Nid
    $project_info_nid = 0;
    foreach ($variables['rows'] as $row){
      if($row->entity_type == "node" && $row->type == "application_project_info"){
        $project_info_nid = $row->nid;
      }
    }
    $project_info = (array)node_load($project_info_nid);

    //Project info - Topics
    $topics = array();
    if(isset($project_info['field_app_topics']['und'])){
      foreach ($project_info['field_app_topics']['und'] as $row){
        $topic = node_load($row['target_id']);
        $topics[] = array("value" => $topic->title);
      }
    }
    $project_info['field_app_topics']['und'] = $topics;

    //Project info - Fields and labels
    $project_info_fields = array(
        "topics",
        "summary",
        "expected",
        "additional_field_1",
        "additional_field_2",
        "additional_field_3",
        "additional_field_4",
        "additional_field_5",
        "duration",
        "supplementory",
        "keywords",
        "dow",
        "video",
        );
    $project_info['fields'] = $project_info_fields;
    $project_info['labels'] = mkb_application_get_content_type_labels("application_project_info");
    $variables = $variables + array("project_info" => $project_info);
  }

  if($pab){
    //Total budget
    $total_budget_valid = TRUE;
    if($applications){
      foreach ($applications as $key => $partner){
        // Check if partner has made a budget
        if(isset($partner['budget_table'])){
        // First partner budget
          if (!isset($total_budget)){
            $total_budget = $partner['budget_table'];
          }
          // Second and forth are added to the first partner budget
          else{
            for($i=2; $i<count($partner['budget_table']); $i++){
                for($j=1; $j<count($partner['budget_table'][$i]); $j++){
                  $total_budget[$i][$j] += $partner['budget_table'][$i][$j];
                  $total_budget[$i][$j] = floatval($total_budget[$i][$j]);
              }
            }
          }
        }
      }
      if (!$total_budget_valid) $total_budget = FALSE;
      $variables = $variables + array("total_budget" => $total_budget);
    }
  }

  if($pai){
    //Partner info - Fields and labels
    $partner_info_fields = array(
        "role",
        "publications",
        "business_plan",
        "additional_field_1",
        "additional_field_2",
        "additional_field_3",
        "additional_field_4",
        "additional_field_5",
        );
    $partner_info = array();
    $partner_info['fields'] = $partner_info_fields;
    $partner_info['labels'] = mkb_application_get_content_type_labels("application_partner_info");
    $sme = field_info_field('field_par_sme');
    if ($sme) $partner_info['sme_options'] = $sme['settings']['allowed_values'];
    $variables = $variables + array("partner_info" => $partner_info);
  }

  //Call main page
  $call_main_nid = mkb_application_get_call_main_nid($gid);
  $call_main = node_load($call_main_nid);
  $variables = $variables + array("call_main" => $call_main);  

  // Application project publish data
  $group_content = mkb_application_get_group_content($gid, 'application_project_publish');
  if(isset($group_content[0])){
     $app_pp = node_load($group_content[0]);
     $app_pp_view = node_view($app_pp);
     $variables = $variables + array("app_pp_view" => $app_pp_view);
   }
  
  return theme('rapport_template', $variables);
}
