<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Generates content for application_page template.
 *
 * @param $gid
 *   Group node id
 * @return $template
 *   Application page template.
 * @todo Refacter code and use field_get_items and node_view instead of custom arrays.
 */
function application_page_function($gid){
  //Group users and nodes
  $variables = mkb_application_get_group_user_and_roles($gid);

  //Group
  $group = node_load($gid);
  $variables = $variables + array("group" => $group);

  //Build applications array with all data related to partners
  //applications = array(
  //  "uid" => array(
  //        "user" => array(),
  //        "partner_info" => array(),
  //        "partner_budget" => array(),
  //        "budget" => "budget_table" => array(),
  //      ),
  //    );
  $applications = array();
  $pri = false;
  $pai = false;
  $pab = false;
  foreach ($variables['rows'] as $row){
    if($row->entity_type == "user" && ($row->role == "project coordinator" || $row->role == "project partner")){
      $user_my_org = mkb_application_get_my_org($row->uid);
      $applications[$row->uid] = array(
          "pri" => FALSE,
          "pai" => FALSE,
          "pab" => FALSE,
          "user" => array(
            "realname" => $row->realname,
            "country" => $row->country,
            "my_org" => $user_my_org,
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
    //dpm($project_info);

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
				// COFASP CUSTOMIZATION - VIEW BUDGET TOTALT BECAUSE PARTNERS ARE USING OTHER PARTNERS BUDGET - DUH!
//        // All partners must have a budget or we will generate a message saying one or more is missing.
//        else{
//          $total_budget_valid = FALSE;
//        }
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

  return theme('application_page_template', $variables);
}