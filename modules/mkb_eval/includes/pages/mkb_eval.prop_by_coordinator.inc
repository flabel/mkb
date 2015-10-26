<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Generates content for prop_by_coordinator template.
 *
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Filter node id
 * @return template
 *   The template prop_by_coordinator is called with $variables.
 */
function mkb_eval_prop_by_coordinator($cid, $fid){
  $variables = array();
  $header = array('Country', '#Proposals', 'Requested (€1000)', 'Total (€1000)');
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

  // Get proposal coordinator countries
  foreach ($groups as $gid => $group){
    // Get applications
    $applications = $group->applications;

    $project_info_node = node_load($applications['application_project_info']);
    $coordinator = user_load($project_info_node->uid);
    $coordinator_wrapper = entity_metadata_wrapper('user', $coordinator);
    $country = $coordinator_wrapper->field_country->name->value();

    if(!array_key_exists($country, $rows)){
      $rows[$country] = array(
          0 => $country,
          1 => 0,
          2 => 0,
          3 => 0,
          );
    }
  }

  // Add row for totals
  $rows['total'] = array(
      0 => 'Total',
      1 => 0,
      2 => 0,
      3 => 0,
      );

  // Run through groups and add project-info coordinator country, budgets requested and total, and number of
  // proposals +1
  foreach ($groups as $gid => $group){
    // Get applications
    $applications = $group->applications;

    // Find project-info coordinator country
    $project_info_node = node_load($applications['application_project_info']);
    $coordinator = user_load($project_info_node->uid);
    $coordinator_wrapper = entity_metadata_wrapper('user', $coordinator);
    $country = $coordinator_wrapper->field_country->name->value();

    // Count +1
    $rows[$country][1] = $rows[$country][1] + 1;
    $rows['total'][1] = $rows['total'][1] + 1;

    if(isset($applications['application_partner_budget'])){
      foreach ($applications['application_partner_budget'] as $budget_id){

		// Get budget requested for each application_partner_budget and add it to coordinator country row
		$budget = mkb_application_get_budget_table($budget_id);

		$num_col = count($budget[10]);
		$requested = intval(round($budget[10][$num_col-1]));
		$total = intval(round($budget[10][$num_col-2]));

        $rows[$country][2] = $rows[$country][2] + $requested;
        $rows[$country][3] = $rows[$country][3] + $total;

        // Add requested and total from each application to rows total
        $rows['total'][2] = $rows['total'][2] + $requested;
        $rows['total'][3] = $rows['total'][3] + $total;
      }
    }
  }

  $variables['header'] = $header;
  $variables['rows'] = $rows;
  $variables['description'] = $description;
  return theme('prop_by_coordinator', $variables);
}


