<?php
drupal_add_js('misc/form.js');
drupal_add_js('misc/collapse.js');

// Group
$group = $variables['group'];
$group_wrapper = entity_metadata_wrapper('node', $group);

// Coordinator
$coordinator = user_load($group->uid);

// Call
$call = $variables['call'];
$call_wrapper = entity_metadata_wrapper('node', $call);
$call_view = node_view($call);

// Project-info
$project_info = $variables['project_info'];
if($project_info){
  $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
  $project_info_view = node_view($project_info);

  // Page title
  print '<h2 class="block-title">' . $group->title . '</h2>';

  // Application
  print '<h2>Application</h2>';
  print '<p><b>ID:</b> ' . $group->nid . '</p>';
  print '<p><b>Name:</b> ' . render($project_info_view['field_app_acronym'][0]) . '</p>';
  print '<p><b>Coordinator:</b> ' . $coordinator->realname . '</p>';
  print isset($project_info_view['field_app_dow']) ?
    render($project_info_view['field_app_dow']) : '<p><b>Description of work:</b> None';

  // Summary
  $summary = array(
    '#attributes' => array(
      'class' => array('collapsible', 'collapsed'),
    ),
    '#title' => '<strong>Summary</strong>',
    '#description' => '',
    '#children' => render($project_info_view['field_app_summary'][0]),
  );
  print theme('fieldset', array('element' => $summary));

  // Call
  print '<h2>Call and submission</h2>';
  print '<p><b>Call:</b> ' . $call->title . '</p>';

  // Submission
  $header = array();
  $rows = array();

  // 1 Stage
  if($call_wrapper->field_stages->value() == 0){
    $header = array('Stage', '1: Full proposals');

      // Call
    // Full proposal
	
	// OBS!
	// 1 stage calls use field_app_submitted, field_app_submit_time, field_app_selected_1
	
    $call_full_proposals_open = isset($call_view['field_date_full_proposals_open']) ?
      render($call_view['field_date_full_proposals_open'][0]) : '';
    $call_full_proposals_close = isset($call_view['field_date_full_proposals_close']) ?
      render($call_view['field_date_full_proposals_close'][0]) : '';

    $rows[0] = array(
        'realm' => 'Call',
        'full' => $call_full_proposals_open . ' - ' . $call_full_proposals_close,
        );

    // Full proposal submitted
    $full_submit = $project_info_wrapper->field_app_submitted->value();
    $full_submit_time = 'Not submitted';
    if($full_submit == 1){
      $timestamp = strtotime($project_info->field_app_submit_time['und'][0]['value']);
      $full_submit_time = format_date($timestamp, $type = 'short', $format = '', drupal_get_user_timezone(), $langcode = NULL);
    }

    $rows[1] = array(
        'realm' => 'Application',
        'full' => render($full_submit_time),
        );

    // Full proposal selected
    $full_selected = '';
    if($full_submit == 1){
      if($project_info_wrapper->field_app_selected_1->value() == 1){
        $full_selected = 'Selected to receive funding';
      }
      elseif($project_info_wrapper->field_app_selected_1->value() == 0 && $call_wrapper->field_current_stage->value() == 1){
        $full_selected = 'Not selected to receive funding';
      }
    }
/*
    $rows[2] = array(
        'realm' => 'Evaluation',
        'full' => $full_selected,
        );
*/
  }

  // 2 Stages
  if($call_wrapper->field_stages->value() == 1){
    $current_stage = $call_wrapper->field_current_stage->value();
    print '<p><b>Current stage:</b> ' . $current_stage . '</p>';

    $header = array('Stage', '1: Pre-proposals', '2: Full proposals');

      // Call
    // Pre-proposal
    $call_pre_proposals_open = isset($call_view['field_date_pre_preposals_open']) ?
      render($call_view['field_date_pre_preposals_open'][0]) : '';
    $call_pre_proposals_close = isset($call_view['field_date_pre_preposals_close']) ?
      render($call_view['field_date_pre_preposals_close'][0]) : '';

    // Full proposal
    $call_full_proposals_open = isset($call_view['field_date_full_proposals_open']) ?
      render($call_view['field_date_full_proposals_open'][0]) : '';
    $call_full_proposals_close = isset($call_view['field_date_full_proposals_close']) ?
      render($call_view['field_date_full_proposals_close'][0]) : '';

    $rows[0] = array(
        'realm' => 'Call time schedule',
        'pre' => $call_pre_proposals_open . ' - ' . $call_pre_proposals_close,
        'full' => $call_full_proposals_open . ' - ' . $call_full_proposals_close,
        );

      // Application
    // Pre-proposal submitted
    $pre_submit = $project_info_wrapper->field_app_submitted->value();
    $pre_submit_time = 'Not submitted';
    if($pre_submit == 1){
      $timestamp = strtotime($project_info->field_app_submit_time['und'][0]['value']);
      $pre_submit_time = format_date($timestamp, $type = 'short', $format = '', drupal_get_user_timezone(), $langcode = NULL);
    }

    // Full proposal submitted
    $full_submit = $project_info_wrapper->field_app_submitted_2->value();
    $full_submit_time = 'Not submitted';
    if($full_submit == 1) {
      $timestamp = strtotime($project_info->field_app_submit_time_2['und'][0]['value']);
      $full_submit_time = format_date($timestamp, $type = 'short', $format = '', drupal_get_user_timezone(), $langcode = NULL);
    }

    $rows[1] = array(
        'realm' => 'Application submission',
        'pre' => render($pre_submit_time),
        'full' => render($full_submit_time),
        );

      // Evaluation
    // Pre-proposal selected
    $pre_selected = '';
    if($pre_submit == 1){
      if($project_info_wrapper->field_app_selected_1->value() == 1){
        $pre_selected = 'Selected for stage 2';
      }
      elseif($project_info_wrapper->field_app_selected_1->value() == 0 && $current_stage == 1){
        $pre_selected = 'Selection in progress';
      }
      elseif($project_info_wrapper->field_app_selected_1->value() == 0 && $current_stage == 2){
        $pre_selected = 'Not selected for stage 2';
      }
    }

    // Full proposal selected
    $full_selected = '';
    if($full_submit == 1){
      if($project_info_wrapper->field_app_selected_2->value() == 1){
        $full_selected = 'Selected to receive funding';
      }
      elseif($project_info_wrapper->field_app_selected_2->value() == 0 && $current_stage == 2){
        $full_selected = 'Not selected to receive funding';
      }
    }

    $rows[2] = array(
        'realm' => 'Evaluation status',
        'pre' => $pre_selected,
        'full' => $full_selected,
        );
  }

  $table = array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(
          'class' => array('table_class'),
          'width' => '100%',
          ),
      'sticky' => FALSE,
      'empty' => 'No data.',
      'colgroups' => array(),
      'caption' => 'Submission',
      );
  print theme_table($table);
}
else{
  // No project info file

  // Page title
  print '<h2 class="block-title">' . $group->title . '</h2>';

  // Application
  print '<h2>Application</h2>';
  print '<p><b>ID:</b> ' . $group->nid . '</p>';
  print '<p><b>Coordinator:</b> ' . $coordinator->realname . '</p>';
  print '<p><b>Note:</b> Additional information about the application will apear once the coordinator has created the project-info
      file through the "edit application" page.';
}
?>

