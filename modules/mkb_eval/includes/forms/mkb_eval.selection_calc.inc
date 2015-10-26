<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Application selection form submit.
 *
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state.
 * @return $???
 *   ???.
 */
function mkb_eval_selection_calc_form_submit($form, $form_state){
  // Save funder_page field_eu_funding fields
  $options = $form_state['values']['table'][2];
  foreach ($options as $nid => $option){
    if($option){
      $node = node_load($nid);
      if($node){
        $wrapper = entity_metadata_wrapper('node', $node);
        $wrapper->field_extra_funding->set($option);
        $wrapper->save();
      }
    }
  }
}

function mkb_eval_selection_calc_form_validate($form, $form_state){
}

/**
 * Generates form for selection calculation.
 *
 * @param $cid
 *   Call-main-page nid.
 * @return form
 *   Application selection form.
 */
function mkb_eval_selection_calc_form($form, &$form_state, $cid){
  // Get quality_evaluation
  $eval_conf = mkb_eval_get_eval_conf_by_term_name('Quality');

  // Get groups
  $group_ids = mkb_eval_get_group_ids($cid);
  $groups = mkb_eval_build_aids($group_ids);

  // Determine stage
  $call = node_load($cid);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  $current_stage = $call_wrapper->field_current_stage->value();

  // Unset groups according to stage
  if($current_stage == 2){
    foreach ($groups as $gid => $group){
      $project_info_node = node_load($group['application_project_info']);
      $wrapper = entity_metadata_wrapper('node', $project_info_node);
      $selected = $wrapper->field_app_selected_2->value();
      if($selected!=1){
        unset($groups[$gid]);
      }
    }
  }

  // Get funding agencies
  $funding_agencies = mkb_eval_get_all_funding_agencies($cid);

  // Approved in formality evaluations
  mkb_eval_filter_applications($groups, 'Formality');
//   foreach ($groups as $gid => $group){
//     $form_eval_ids = mkb_eval_get_evaluation_ids($gid, 'form_eval');
//     $unset = TRUE;
//     if($form_eval_ids){
//       foreach ($form_eval_ids as $form_eval_id){
//         $evaluation = evaluation_load($form_eval_id->evaluation_id);
//         if($evaluation->recommendation() == 'Approved'){
//           $unset = FALSE;
//         }
//       }
//     }
//     if($unset){
//       unset($groups[$gid]);
//     }
//   }

  $requested_arr = array();
  foreach ($groups as $gid => $group){
    // Add funder_pages and requested to each group
    $groups[$gid]['funder_pages'] = array();
    if(isset($group['application_partner_budget'])){
      foreach ($group['application_partner_budget'] as $budget_id){
      // Check if partner_budget authors are project coordinator or project partner
	  $author_og_roles = mkb_eval_get_author_og_roles($gid,$budget_id);
        if (isset($author_og_roles) && (in_array("project coordinator", $author_og_roles) || in_array("project partner", $author_og_roles))) {
			// Get budget requested for each application_partner_budget and add it to the funding agency col (fid)
			$fid = mkb_eval_get_funder_page($budget_id);
			$budget = mkb_application_get_budget_table($budget_id);

			$num_col = count($budget[10]);
			$requested = intval(round($budget[10][$num_col-1]));
			if(array_key_exists($fid, $funding_agencies)){
			  $content[$gid][$fid] = $content[$gid][$fid] + $requested;
			  // Add requested from each application to requested_arr for table header requested
			  if(!isset($requested_arr[$fid])) $requested_arr[$fid] = 0;
			  if($selected==1){
				$requested_arr[$fid] += $requested;
			  }
			}
        }

        // Set groups funder_page
        if(!in_array($fid, $groups[$gid]['funder_pages'])) {
          $groups[$gid]['funder_pages'][] = $fid;
        }
      }
    }
  }

  // Calculate and add row totals
  foreach ($content as $gid => $row){
    $row_total = 0;
    foreach ($funding_agencies as $nid => $funding_agency){
        $row_total += $row[$nid];
    }
    $content[$gid]['total'] = $row_total;
  }

  // Initiate header and rows
  $header = array('');
  $rows = array(
      0 => array(0 => '<nobr>FA contribution</nobr>'),
      1 => array(0 => '<nobr>FA extra contribution</nobr>'),
      2 => array(0 => '<nobr>FA share of EU funds</nobr>'),
      3 => array(0 => '<nobr>Free EU funds</nobr>'),
      4 => array(0 => '<nobr>Requested by proposals</nobr>'),
      5 => array(0 => '<nobr>FA contribution deficit</nobr>'),
      6 => array(0 => '<nobr>FA EU share not used</nobr>'),
      7 => array(0 => '<nobr>Free EU funds used</nobr>'),
      8 => array(0 => '<nobr>Balance</nobr>'),
      );

  // Calculate and add data to rows
  $avaliabel_total = 0;
  $requested_total = 0;
  $deficit_total = 0;
  foreach ($funding_agencies as $nid => $funding_agency){
    // Name of funding agency
    $header[0][$nid] = $funding_agency;

    // Funding, EU funding and Extra funding
    $fundings = mkb_eval_get_fa_fundings($nid);

    $funding = (int)$fundings['funding'];
    $extra_funding = (int)$fundings['extra_funding'];
    $eu_funding = (int)$fundings['eu_funding'];

    $rows[0][$nid] = $funding;
    $rows[1][$nid] = $extra_funding;
    $rows[2][$nid] = $eu_funding;
    $rows[3][$nid] = '';

    // Requested by proposals
    if(isset($requested_arr[$nid])){
       $requested = (int)$requested_arr[$nid];
    }
    else{
      $requested = 0;
    }
    $rows[4][$nid] = $requested;

    // Contribution deficit
    $deficit = $requested-($funding+$extra_funding);
    $rows[5][$nid] = ($deficit>0) ? $deficit : 0;

    // EU share not used
    $fa_eu_share_not_used = $eu_funding-$deficit;
    $rows[6][$nid] = ($fa_eu_share_not_used>0) ? $fa_eu_share_not_used : 0;

    // Free EU funds used
    $free_eu_funds_used = $deficit-$eu_funding;
    $rows[7][$nid] = ($free_eu_funds_used>0) ? $free_eu_funds_used : 0;

    // Totals
    $funding_total += $funding;
    $extra_funding_total += $extra_funding;
    $eu_funding_total += $eu_funding;
    $requested_total += $requested;
    $deficit_total += $deficit;
    $fa_eu_share_not_used_total += $fa_eu_share_not_used;
    $free_eu_funds_used_total += $free_eu_funds_used;
  }

  // Add total label (right top)
  $header[0]['total'] = 'Total';

  // Add totals to rows
  $rows[0]['total'] = $funding_total;
  $rows[1]['total'] = $extra_funding_total;
  $rows[2]['total'] = $eu_funding_total;
  $free_eu_funds = $call_wrapper->field_eu_funding->value();
  $rows[3]['total'] = $free_eu_funds;
  $rows[4]['total'] = $requested_total;
  $rows[5]['total'] = $deficit_total;
  $rows[6]['total'] = $fa_eu_share_not_used_total;
  $rows[7]['total'] = $free_eu_funds_used_total;

  // Calculate balance and balance total
  foreach ($rows as $i => $row){
    foreach ($row as $key => $cell){
      if($key!==0){
        $rows[8][$key] += $cell;
      }
    }
  }

  // Table container
  $form['table'] = array(
      '#tree' => TRUE,
      '#type' => 'container',
      '#prefix' => '<table class="selection_calc_tbl">',
      '#suffix' => '</table>',
      );

  // Add header to form
  $form['table'][0][0] = array(
      '#markup' => '',
      '#prefix' => '<tr><th>',
      '#suffix' => '</th>',
      );
  foreach ($header[0] as $key => $cell){
    $form['table'][0][$key] = array(
        '#markup' => isset($cell) ? $cell : '',
        '#prefix' => '<th>',
        '#suffix' => ($key === 'total') ? '</th></tr>' : '</th>',
        );
  }

  // Add rows to form
  foreach ($rows as $i => $row){
    // Row styling
    $row_class = ($i%2==0) ? 'even' : 'odd';

    foreach ($row as $key => $cell){
      // Cell styling
      $cell_class = 'align_right';
      if($key===0) $cell_class = 'align_left';
      if($cell<0) $cell_class .= ' negative';

      // Cell form
      if($i==1 && ($key!==0 && $key!=='total')){
        $funding_agency_node = node_load($key);
        $wrapper = entity_metadata_wrapper('node', $funding_agency_node);

        $form['table'][$i+1][$key] = array(
            '#type' => 'textfield',
            '#title' => '',
            '#default_value' => $wrapper->field_extra_funding->value(),
            '#size' => 3,
            '#maxlength' => 3,
            '#prefix' => '<td class="' . $cell_class . '">',
            '#suffix' => '</td>',
            '#element_validate' => array('element_validate_number'),
            );
      }
      else{
        $form['table'][$i+1][$key] = array(
            '#markup' => isset($cell) ? $cell : '',
            '#prefix' => ($key === 0) ? '<tr class="' . $row_class . '"><td class="' . $cell_class . '">' :
              '<td class="' . $cell_class . '">',
            '#suffix' => ($key === 'total') ? '</td></tr>' : '</td>',
            );
      }
    }
  }

  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Save',
      );

  return $form;
}