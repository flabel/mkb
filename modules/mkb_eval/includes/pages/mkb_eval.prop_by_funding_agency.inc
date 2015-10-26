<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for prop_by_funding_agency template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Filter node id
 * @return template
 *   The template prop_by_funding_agency is called with $variables.
 */
function mkb_eval_prop_by_funding_agency($cid, $fid){
  $variables = array();
  $header = array('Funding agency', '#Proposals', 'Requested (€1000)', 'Total (€1000)');
  $rows = array();

  // Set description according to filter
  $filter = node_load($fid);
  $description = isset($filter->title) ? 'Filter: ' . $filter->title : '';

  // Get groups
  $groups = mkb_eval_get_filtered_groups($cid, $fid);

  // Determine stage
  $call = node_load($cid);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  $current_stage = $call_wrapper->field_current_stage->value();

  // Get funding agencies
  $funding_agencies = mkb_eval_get_all_funding_agency_names($cid);
  foreach ($funding_agencies as $funder_page_id => $funding_agency){
    $rows[$funder_page_id] = array(
        0 => $funding_agency,
        1 => 0,
        2 => 0,
        3 => 0,
    );
  }

  // Add row for totals
  $rows['total'] = array(
      0 => 'Total',
      1 => '',
      2 => 0,
      3 => 0,
      );

  // Run through funding agencies and add requested, total and +1 to proposal count if application is requesting
  // funds from funding agency
  foreach ($groups as $gid => $group){
    // Get applications
    $applications = $group->applications;

    // Add budget requested and total
    if(isset($applications['application_partner_budget'])){
      $count_funding_agencies = array();
      foreach ($applications['application_partner_budget'] as $budget_id){
        // Get budget requested for each application_partner_budget and add it to the funding agency col (fid)
        $funder_page_id = mkb_eval_get_funder_page($budget_id);
        $budget = mkb_application_get_budget_table($budget_id);

        $num_col = count($budget[10]);
        $requested = intval(round($budget[10][$num_col-1]));
        $total = intval(round($budget[10][$num_col-2]));

        if(array_key_exists($funder_page_id, $funding_agencies)){
          // Add requested and total from each application to rows
          $rows[$funder_page_id][2] = $rows[$funder_page_id][2] + $requested;
          $rows[$funder_page_id][3] = $rows[$funder_page_id][3] + $total;

          // Add requested and total from each application to rows total
          $rows['total'][2] = $rows['total'][2] + $requested;
          $rows['total'][3] = $rows['total'][3] + $total;

          $count_funding_agencies[$funder_page_id] = 1;
        }
      }

      // Add countings
      foreach ($count_funding_agencies as $funder_page_id => $count_funding_agency){
        $rows[$funder_page_id][1] = $rows[$funder_page_id][1] + $count_funding_agency;
      }
    }
  }

  $variables['header'] = $header;
  $variables['rows'] = $rows;
  $variables['description'] = $description;
  return theme('prop_by_funding_agency', $variables);
}


