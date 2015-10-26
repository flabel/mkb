<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for expert_summaries template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @return template
 *   The template list_evaluations_template is called with $content.
 */
function mkb_eval_expert_summaries($cid, $eid){
  $rows = array();

  // Header
  $header = array(
      'selected' => 'Selected',
      'id' => 'ID',
      'acronym' => 'Acronym',
      'title' => 'Title',
      'coordinator' => 'Coordinator',
      'company' => 'Company',
      'country' => 'Country',
      'summary' => 'Summary',
      );

  // Get all group ids to this call
  $group_ids = mkb_eval_get_group_ids($cid);

  // Build groups
  $groups = mkb_eval_build_groups($group_ids);

  // Approved in formality evaluations
  mkb_eval_filter_applications($groups, 'Formality');

  // Approved in all eligible evaluations
  mkb_eval_filter_applications($groups, 'Eligibility');

  $rows = array();
  foreach ($groups as $gid => $group){
    $project_info = node_load($group['application_project_info']);
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);

    // Selected
    $selected = $project_info_wrapper->field_app_selected_1->value();
    $row['selected'] = ($selected==1) ? 'Yes' : 'No';

    // ID
    $row['id'] = $gid;

    // Acronym
    $acronym = $project_info_wrapper->field_app_acronym->value();
    $row['acronym'] = isset($acronym) ? $acronym : '';

    // Title
    $row['title'] = $project_info_wrapper->label();

    // Coordinator and country
    $coordinator = $project_info_wrapper->author->value();
    $row['coordinator'] = $coordinator->realname;

    // Company (organisation)
    $company = $coordinator->realname;
    $country = $coordinator->realname;
    $profile = profile2_load_by_user($coordinator, 'main');
    if($profile){
      $profile_wrapper = entity_metadata_wrapper('profile2', $profile);
      $org = $profile_wrapper->field_my_organisation->value();
      $org_wrapper = entity_metadata_wrapper('node', $org);
      $company = $org_wrapper->label();
      if(!empty($org->field_country)) $country = $org_wrapper->field_country->name->value();
    }
    $row['company'] = $company;
    $row['country'] = $country;

    // Summary
    $summary = $project_info_wrapper->field_app_summary->value();
    $row['summary'] = isset($summary) ? $summary : '';

    // Add row
    $rows[] = $row;
  }

  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('expert_summaries', $variables);
}

