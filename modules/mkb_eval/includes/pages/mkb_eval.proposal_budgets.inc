<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for proposal_budgets template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Filter node nid.
 * @return template
 *   The template list_evaluations_template is called with $content.
 */
function mkb_eval_proposal_budgets($cid, $fid){
  $rows = array();

  // Countries from funding agencies
  $funding_countries = mkb_eval_get_all_funding_agency_countries($cid);

  // Header
  $header_1 = array('id' => 'ID', 'proposal' => 'Proposal');
  $header_2 = array('total' => 'Total', 'countries' => 'Participating countries');
  $header = array_merge($header_1, $funding_countries, $header_2);

  // Get filtered groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid);

  // Get filter title for page description
  $filter = node_load($fid);
  $description = $filter->title;

  // zero row
  $zero_row = array();
  foreach ($funding_countries as $iso2){
    $zero_row[$iso2] = 0;
  }

  foreach ($groups as $gid => $group){
    // Get applications
    $applications = $group->applications;

    // Initiate row with id and acronym
    $project_info = node_load($applications['application_project_info']);
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
    $acronym = $project_info_wrapper->field_app_acronym->value();
    $row_1 = array('id' => $gid, 'proposal' => $acronym);
    $row_2 = array('total' => 0, 'countries' => '');
    $rows[$gid] = array_merge($row_1, $zero_row, $row_2);

    // Participating countries
    $countries = array();

    // Partner budget
    foreach ($applications['application_partner_budget'] as $partner_budget_nid){
      $partner_budget = node_load($partner_budget_nid);
      $iso2 = mkb_eval_get_budget_funder_page_iso2($partner_budget_nid);

      if(!array_key_exists($iso2, $countries)) $countries[$iso2] = $iso2;

      $budget = mkb_application_get_budget_table($partner_budget_nid);
      $sum_index = count($budget)-1;
      $requested_total = $budget[$sum_index][count($budget[$sum_index])-1];
      $rows[$gid][$iso2] += $requested_total;
      $rows[$gid]['total'] += $requested_total;
    }

    sort($countries);
    $countries_str = '';
    $first = TRUE;
    foreach ($countries as $country){
      if($first){
        $countries_str = $country;
        $first = FALSE;
      }
      else{
        $countries_str .= ' ' . $country;
      }
    }
    $rows[$gid]['countries'] = $countries_str;
  }

  $variables['description'] = $description;
  $variables['countries_count'] = count($funding_countries);
  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('proposal_budgets', $variables);
}