<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');

/**
 * Application selection form submit.
 *
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state.
 */
function mkb_eval_expert_results_form_submit($form, $form_state){
  // Get selected field_name: Call stage 1 -> selected_1, Call stage 2 -> selected_2
  $call = node_load($form_state['build_info']['args'][0]);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  $current_stage = $call_wrapper->field_current_stage->value();
  $field_name = 'field_app_selected_' . $current_stage;

  // Set selected field for each checkbox in form and save project_info node.
  $values = $form_state['values'];
    foreach ($values[table] as $gid => $checkbox){
      $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
      $project_info_node = node_load($project_info_nids[0]);
      $project_info_node_wrapper = entity_metadata_wrapper('node', $project_info_node);
      if(isset($checkbox) && $gid == $checkbox) $project_info_node_wrapper->{$field_name}->set(1);
      else $project_info_node_wrapper->{$field_name}->set(0);
      $project_info_node_wrapper->save();
    }
}

function mkb_eval_expert_results_form_validate($form, $form_state){
}

/**
 * @param $form
 *   Form
 * @param $form_state
 *   Form state
 * @param $cid
 *   call-main node id.
 * @param $fid
 *   Evaluation filter nid.
 * @return template
 *   Rendered template expert_results.
 */
function mkb_eval_expert_results_form($form, &$form_state, $cid, $fid){
  $variables = array();

  // Get selected field_name: Call stage 1 -> selected_1, Call stage 2 -> selected_2
//   $call = node_load($form_state['build_info']['args'][0]);
  $call = node_load($cid);
  $call_wrapper = entity_metadata_wrapper('node', $call);
  $current_stage = $call_wrapper->field_current_stage->value();
  $field_name = 'field_app_selected_' . $current_stage;

  // Load groups
  $groups = mkb_eval_get_stage_applications($cid, $fid);

  // Filter groups: Approved in eligibility
  mkb_eval_filter_applications($groups, 'Formality');
  mkb_eval_filter_applications($groups, 'Eligibility');

  $eval_confs = mkb_eval_get_eval_confs_by_term_name('Expert');
  $eval_conf_nids = array_keys($eval_confs);

  // Header
  $header = array(
      'gid' => 'ID',
      'acronym' => 'Application',
      'countries' => 'Countries',
      'rank' => 'Rank',
      'total' => 'Total',
      );
  foreach ($eval_confs as $nid => $eval_conf){
    $eval_conf_wrapper = entity_metadata_wrapper('node', $eval_conf);
    $expertise_short = $eval_conf_wrapper->field_expertise_shortname->value();
    $header[$nid] = $expertise_short;
  }

  // Custom for ict-agri
  $header['fiware'] = 'FIWARE';
  $header['fispace'] = 'FISPACE';

  // Rows
  $empty_row = array_keys($header);
  $rows = array();
  $default_values = array();
  foreach ($groups as $gid => $group){
    $row = $empty_row;
    // GID with link to group evaluations
    $row['gid'] = l($gid, 'eval/group/' . $cid . '/' . $gid);

    // Get project-info
    $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
    $acronym = 'None';
    if($project_info_nids){
      $project_info_nid = $project_info_nids[0];
      $project_info_node = node_load($project_info_nid);
      $project_info_node_wrapper = entity_metadata_wrapper('node', $project_info_node);
      $acronym = $project_info_node_wrapper->field_app_acronym->value();
//       $acronym = $project_info_node->field_app_acronym['und'][0]['value'];
      $selected = $project_info_node_wrapper->{$field_name}->value();
      if($selected) $default_values[$gid] = 1;
    }
    $row['acronym'] = l($acronym, 'groups/workspace/application_page/' . $gid);

    // Countries
    $row['countries'] = mkb_eval_get_country($gid);

    // Get all evaluations and add scores to expert_scores
    $evaluations = NULL;
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'evaluation')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
      ->fieldCondition('field_eval_conf', 'target_id', $eval_conf_nids, 'IN');
    $result = $query->execute();

    $conf_scores = array();
    $expert_scores = '';
    $total_score = 0;
    $fiware = array();
    $fiware_score = 0;
    $fispace = array();
    $fispace_score = 0;
    if (isset($result['node'])) {
      $evaluation_nids = array_keys($result['node']);
      $evaluations = entity_load('node', $evaluation_nids);

      foreach ($evaluations as $eid => $evaluation){
        $evaluation_wrapper = entity_metadata_wrapper('node', $evaluation);

        // Evaluation type
        $field_eval_conf_nid = $evaluation_wrapper->field_eval_conf->raw();
        $eval_conf = $eval_confs[$field_eval_conf_nid];

        // Total and expert score
        $score = $evaluation_wrapper->field_eval_score->value();
        if($score) {
          $conf_scores[$eval_conf->nid][] = $score;
        }

        // Custom for ict-agri
          // fiware
        if(isset($evaluation->field_eval_answers[LANGUAGE_NONE][5]) && $eval_conf->nid == 15901){
          $answer_5 = $evaluation_wrapper->field_eval_answers[5]->value();
          if($answer_5) $fiware[] = $answer_5;
          else $fiware[] = 0;
        }

          // fispace
        if(isset($evaluation->field_eval_answers[LANGUAGE_NONE][6]) && $eval_conf->nid == 15901){
          $answer_6 = $evaluation_wrapper->field_eval_answers[6]->value();
          if($answer_6) $fispace[] = $answer_6;
          else $fispace[] = 0;
        }
      }

      // Total and expert scores
      foreach ($conf_scores as $eval_conf_nid => $conf_score){
        $conf_score_sum = 0;
        foreach ($conf_score as $x){
          $conf_score_sum += $x;
        }

        // Calculate average of scores if there is more than one evaluation of this eval type
        $average = (count($conf_score) == 0) ? $conf_score_sum : $conf_score_sum/count($conf_score);

        // Score of each evaluation type average
        $row[$eval_conf_nid] = ($expert_scores == '') ? $average : ' ' . $average;

        // Total score of all evaluation type averages
        $total_score += $average;
      }

      // Custom for ict-agri
        // FIWARE score (+1 because answer index starts at 0 but score starts at 1)
      $fiware_score_sum = 0;
      foreach ($fiware as $y){
        $fiware_score_sum += $y+1;
      }
      $number_of_fiware = count($fiware);
      $fiware_score = ($number_of_fiware == 0) ? $fiware_score_sum : $fiware_score_sum/$number_of_fiware;
      $fiware_score = round($fiware_score, 3);

        // FISPACE score (+1 because answer index starts at 0 but score starts at 1)
      $fispace_score_sum = 0;
      foreach ($fispace as $z){
        $fispace_score_sum += $z+1;
      }
      $number_of_fispace = count($fispace);
      $fispace_score = ($number_of_fispace == 0) ? $fispace_score_sum : $fispace_score_sum/$number_of_fispace;
      $fispace_score = round($fispace_score, 2);
    }
    $row['total'] = ($total_score == 0) ? '' : $total_score;
    $row['fiware'] = ($fiware_score == 0) ? '' : $fiware_score;
    $row['fispace'] = ($fispace_score == 0) ? '' : $fispace_score;;
    $rows[$gid] = $row;
  }

  // Sort by score
  field_sort($rows,'total',"desc");

  // Add rank
  $i=1;
  foreach ($rows as $id => $row){
    $rows[$id]['rank'] = $i++;
  }

  // Build form
  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $rows,
    '#default_value' => $default_values,
    '#empty' => t('No applications has been approved in Formality and Eligibility evaluation.'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}