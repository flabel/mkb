<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * application_submit_form submit
 *
 * @param $form
 * @param $form_state
 */
function mkb_application_application_submit_form_submit($form, &$form_state) {
  $gid = $form_state['build_info']['args'][0];
  $group_content_nids = mkb_application_get_group_content($gid, 'application_project_info');
  $project_info_node = node_load($group_content_nids[0]);

  $current_stage = mkb_application_current_stage($gid);
  $call_open = mkb_application_gid_call_open($gid);
  $app_selected_1 = isset($project_info_node->field_app_selected_1['und'][0]['value']) ? $project_info_node->field_app_selected_1['und'][0]['value'] : 0;
  $app_submit = $form_state['values']['app_submit'] == 1 ? 1 : 0;
  //$now = format_date(time(), $type = 'short', $format = '', $timezone = NULL, $langcode = NULL);
  $now = date('Y-m-d H:i:s', strtotime("now"));
  if($call_open){
    if($current_stage == 1){
      $project_info_node->field_app_submitted['und'][0]['value'] = $app_submit;
      if($app_submit == 1) {
        $project_info_node->field_app_submit_time['und'][0]['value'] = $now;
      }
      else{
        $project_info_node->field_app_submit_time['und'][0]['value'] = NULL;
      }
    }
    elseif($current_stage == 2 && $app_selected_1 == 1){
      $project_info_node->field_app_submitted_2['und'][0]['value'] = $app_submit;
      if($app_submit == 1){
        $project_info_node->field_app_submit_time_2['und'][0]['value'] = $now;
      }
      else{
        $project_info_node->field_app_submit_time_2['und'][0]['value'] = NULL;
      }
    }
    else{
      drupal_set_message('Submission is not saved.', 'warning');
    }
    node_save($project_info_node);
    // Send email notification to coordinator
    $project_info_node = node_load($group_content_nids[0]);
    $group = node_load($gid);
    $coordinator = user_load($group->uid);
    if($project_info_node->field_app_submitted['und'][0]['value'] == 1 && $current_stage == 1){
      drupal_set_message('Application is saved for stage 1', 'status');
      mkb_application_mail_coordinator($coordinator, $group, '1');
    }
    elseif($project_info_node->field_app_submitted_2['und'][0]['value'] == 1 && $current_stage == 2 && $app_selected_1 == 1){
      drupal_set_message('Application is saved for stage 2', 'status');
      mkb_application_mail_coordinator($coordinator, $group, '2');
    }
  }
  else{
    drupal_set_message('Call is closed.', 'warning');
  }
}

/**
 * application_submit_form
 *
 * @param $coordinator
 * @param $group
 * @param $stage
 */
function mkb_application_mail_coordinator($coordinator, $group, $stage){
  $account = $GLOBALS['user'];
  $module = 'mkb_application';
  $key = 'app_submit';
  $site_name = variable_get('site_name', '');

  $from = $site_name . '<' . $account->mail . '>';
  $to = $coordinator->mail;

  $message = '<p>Dear ' . $coordinator->realname . ',</p>';
  $message .= '<p>This is a confirmation that the following application has been submitted for stage' . $stage . '</p>';
  $message .= '<p>' . $group->title . '</p>';
  $message .= '<p>Best regards,</p>';
  $message .= '<p>Call adminstrators of ' . $site_name . '</p>';

  $params = array(
    'body' => $message,
    'subject' => $site_name . ': Application submitted confirmation',
  );
  $language = language_default();
  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);

  if ($result['result'] == TRUE) {
    drupal_set_message('An email confirming the submission has been sent to the coordinator.');
  }
  else {
    drupal_set_message('There was a problem sending email confirmation to the coordinator.
    Please contact the site administrator for further help.', 'error');
  }
}

/**
 * application_submit_form
 *
 * @param $form
 * @param $form_state
 * @return $form
 */
function mkb_application_application_submit_form($form, &$form_state, $gid){
  $current_stage = mkb_application_current_stage($gid);
  $checked = 0;
  if (!isset($form_state['values']['app_submit']) || !is_numeric($form_state['values']['app_submit'])) {
    $group_content_nids = mkb_application_get_group_content($gid, 'application_project_info');
    if(!empty($group_content_nids)){
      $project_info_node = node_load($group_content_nids[0]);
      if($current_stage == 1){
        if(isset($project_info_node->field_app_submitted['und'][0]['value'])){
          $checked = $project_info_node->field_app_submitted['und'][0]['value'];
        }
      }
      elseif($current_stage == 2){
        if(isset($project_info_node->field_app_submitted_2['und'][0]['value'])){
          $checked = $project_info_node->field_app_submitted_2['und'][0]['value'];
        }
      }
    }
  }
  else{
    $checked = $form_state['values']['app_submit'];
  }

  $form['my_title'] = array(
      '#markup' => '<h2 class="block-title">Submit application</h2>',
      );

  $form['app_submit'] = array(
      '#type' => 'checkbox',
      '#title' => 'Submit application.',
      '#default_value' => $checked == 1 ? TRUE : FALSE,
      );

  $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Submit',
      );
  return $form;
}
