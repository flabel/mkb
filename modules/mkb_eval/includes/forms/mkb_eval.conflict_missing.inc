<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper.inc');

/**
 * Generate a header which informs the user of which stage they're on.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function mkb_eval_conflict_missing_get_header($form, &$form_state) {

  $form_state['stage'] = isset($form_state['stage']) ? $form_state['stage'] : 1;

  $form_stages = array(
    'conflict_select_users' => 1,
    'conflict_mail_body' => 2,
  );

  if (isset($form_stages[$form_state['stage']])) {
   $current_step = $form_stages[$form_state['stage']];
  }
  else {
   $current_step = 1;
  }

  $stages = array(
    1 => array('data' => '1. Select evaluation experts to recieve reminder'),
    2 => array('data' => '2. Write and send email to all the selected evaluation experts'),
  );

  $stages[$current_step]['class'] = array('active');

  $stages_list = theme('item_list', array('items' => $stages));

  $form['header'] = array(
    '#type' => 'fieldset',
    '#title' => '',
    '#value' => $stages_list,
  );

  return $form;

}


/**
 * Given the current stage the user is on, calculate what the next step would be
 *
 * @param type $form_state
 * @return string
 */
function mkb_eval_conflict_missing_move_to_next_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'conflict_select_users':
      return 'conflict_mail_body';
     break;
  }

}


/**
 * Given the current stage the user is on, calculate what the previous step
 * would be
 *
 * @param type $form_state
 * @return string
 */

function mkb_eval_conflict_missing_move_to_previous_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'conflict_mail_body':
      return 'conflict_select_users';
     break;
  }

}

/**
 * Master form which calls an individual form for each step.
 *
 * @see mkb_eval_conflict_missing_form_form_validate().
 * @see mkb_eval_conflict_missing_form_form_submit().
 *
 * @param $form
 * @param $form_state
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Evaluation filter nid.
 * @return type
 */
function mkb_eval_conflict_missing_form($form, &$form_state, $cid, $fid){

//   drupal_add_css(drupal_get_path('module', 'customer_survey') . '/css/customer_survey.css');
  if (!isset($form_state['stage'])) $form_state['stage'] = 'conflict_select_users';

  $form = array();
  $form = mkb_eval_conflict_missing_get_header($form, $form_state);

  switch ($form_state['stage']) {

    case 'conflict_select_users':
      return mkb_eval_conflict_select_users_form($form, $form_state, $cid, $fid);
     break;

    case 'conflict_mail_body':
      return mkb_eval_conflict_mail_body_form($form, $form_state, $cid);
     break;

    default:
      return mkb_eval_conflict_select_users_form($form, $form_state, $cid, $fid);
     break;
  }

  return $form;
}

/**
 * @param $cid
 *   Call-main-page nid.
 * @return form
 *   Form to select users to recieve the reminder of missing conflict
 */
function mkb_eval_conflict_select_users_form($form, &$form_state, $cid, $fid){
  // Load values from form_state
  $values = isset($form_state['multistep_values']['conflict_select_users']) ?
    $form_state['multistep_values']['conflict_select_users'] : array();

  $header = array('Name', 'Role(s)', 'Application(s)');

  $options = array();

  // Load groups
  $groups = mkb_eval_get_stage_applications($cid, $fid);

  // Expert groups - array with no duplicate applications
  $expert_groups = array();

  foreach ($groups as $gid => $group){
    // Get expert evaluation
    $expert_evaluation_nid = end(mkb_application_get_group_content($group->nid, 'expert_evaluators'));

    // Get project-info
    $project_info_nids = mkb_application_get_group_content($gid, 'application_project_info');
    $acronym = 'project-info file missing!';
    if($project_info_nids){
      $project_info_node = node_load($project_info_nids[0]);
      $acronym = $project_info_node->field_app_acronym['und'][0]['value'];
    }

    if($expert_evaluation_nid){
      $expert_evaluations = entity_load('node', array($expert_evaluation_nid));
      $expert_evaluation = $expert_evaluations[$expert_evaluation_nid];
      $expert_evaluation_wrapper = entity_metadata_wrapper('node', $expert_evaluation);

      foreach ($expert_evaluation_wrapper->field_ee_evaluator->getIterator() as $delta => $user_wrapper) {
        // Load user
        $expert = $user_wrapper->value();

        $conflict_nid = mkb_eval_get_eval_conflict($gid, $expert->uid);
        // Conflict not created yet
        if(!$conflict_nid) {
          // Find expert roles
          $roles = '';
          foreach ($expert->roles as $role){
            if($role == 'scientific expert'){
              if($roles == '') $roles = '<ul><li>Scientific expert</li>';
              else $roles .= '<li>Scientific expert</li>';
            }
            if($role == 'sector expert'){
              if($roles == '') $roles = '<ul><li>Sector expert</li>';
              else $roles .= '<li>Sector expert</li>';
            }
            if($role == 'rapporteur'){
              if($roles == '') $roles = '<ul><li>Rapporteur</li>';
              else $roles .= '<li>Rapporteur</li>';
            }
          }

          // Add expert name, roles and applications to options
          if(!isset($options[$expert->uid])){
            // Name and roles
            $options[$expert->uid] = array(
                0 => $expert->realname,
                1 => $roles,
                );

            // Applications
            $options[$expert->uid][2] = '<ul><li>' . $acronym . '</li>';
            $expert_groups[$expert->uid][$gid] = $gid;
          }
          else{
            if(!in_array($gid, $expert_groups[$expert->uid])){
              $options[$expert->uid][2] .= '<li>' . $acronym . '</li>';
              $expert_groups[$expert->uid][$gid] = $gid;
            }
          }
        }
      }
    }
  }

  // Close all the lists in 'roles' and 'application' in options
  foreach ($options as $option){
    // Roles
    $option[1] .= '</ul>';
    // Applications
    $option[2] .= '</ul>';
  }

  // Set options to TRUE and FALSE instead of uids
  $default_value = NULL;
  if(isset($values['table'])){
    foreach ($values['table'] as $uid => $option){
      if($option == 0) $default_value[$uid] = FALSE;
      else $default_value[$uid] = TRUE;
    }
  }

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => 'All users registred as application expert has declared a conflict of interest',
    '#multiple' => TRUE,
    '#default_value' => $default_value,
  );

  $form['next'] = array(
    '#type' => 'submit',
    '#value' => 'Next',
  );

  return $form;
}

/**
 * @param $cid
 *   Call-main-page nid.
 * @return form
 *   Write email body and send email.
 */
function mkb_eval_conflict_mail_body_form($form, &$form_state, $cid){
  $account = $GLOBALS['user'];

  $values = isset($form_state['multistep_values']['conflict_mail_body']) ?
    $form_state['multistep_values']['conflict_mail_body'] : array();

  $form['from'] = array(
    '#type' => 'textfield',
    '#title' => 'From',
    '#description' => 'A copy of the email will be sent to this address',
    '#default_value' => $account->mail,
    '#size' => 60,
    '#maxlength' => 128,
    '#disabled' => TRUE,
  );

  $form['mail'] = array(
    '#title' => 'Email body',
    '#type' => 'text_format',
    '#format' => 'full_html',
    '#description' => '',
    '#default_value' => isset($values['mail']['value']) ?
      $values['mail']['value'] : mkb_eval_conflict_mail_body_default(),
  );

  $form['back'] = array(
    '#type' => 'submit',
    '#value' => 'Back',
  );

  $form['next'] = array(
    '#type' => 'submit',
    '#value' => 'Send email',
  );
  return $form;
}

/**
 * @return $string
 *   Default email body
 */
function mkb_eval_conflict_mail_body_default(){
  $website = l('CORE-ORGANIC website', $GLOBALS['base_url']);

  $default = '<p>Dear evaluator,</p>';
  $default .= '<p>This is a reminder from the ' . $website . '.You are registred as expert evaluator and we kindly remind you to declare if you have any conflict of interest with the applications you are assigned to evaluate.</p>';
  $default .= '<p>Best regards,</p>';
  $default .= '<p>Call adminstrators of CORE-ORGANIC</p>';
  return $default;
}

/**
 * Handles what to do with the submitted form depending on what stage has been
 * completed.
 *
 * @see mkb_eval_conflict_missing_form()
 * @see mkb_eval_conflict_missing_validate()
 *
 * @param type $form
 * @param type $form_state
 */
function mkb_eval_conflict_missing_form_submit($form, &$form_state) {

  switch ($form_state['stage']) {

    case 'conflict_mail_body':
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      if ($form_state['triggering_element']['#value'] != 'Back') {
        mkb_eval_conflict_mail_body_form_submit($form, $form_state);
        $form_state['complete'] = TRUE;
      }
     break;

    default:
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      $form_state['new_stage'] = mkb_eval_conflict_missing_move_to_next_stage($form, $form_state);
     break;

  }

  if (isset($form_state['complete'])){
    drupal_goto($GLOBALS['base_url'] . '/eval/application_experts/41');
  }

  if ($form_state['triggering_element']['#value'] == 'Back') {
    $form_state['new_stage'] = mkb_eval_conflict_missing_move_to_previous_stage($form, $form_state);
  }

  if (isset($form_state['multistep_values']['form_build_id'])) {
    $form_state['values']['form_build_id'] = $form_state['multistep_values']['form_build_id'];
  }
  $form_state['multistep_values']['form_build_id'] = $form_state['values']['form_build_id'];
  $form_state['stage'] = $form_state['new_stage'];
  $form_state['rebuild'] = TRUE;

}

 /**
  * Handles the submission of the final stage
  *
  * Sends an email to the user confirming their entry
  *
  * @param type $form
  * @param type $form_state
  */
function mkb_eval_conflict_mail_body_form_submit($form, &$form_state) {
  $account = $GLOBALS['user'];

  $multstep_values = $form_state['multistep_values'];

  $module = 'mkb_eval';
  $key = 'mkb_eval_conflict';
  $site_name = variable_get('site_name', '');

  // Add the selected experts to receive the mail
  $to = '';
  foreach ($multstep_values['conflict_select_users']['table'] as $uid => $option) {
    if($option != 0){
      $expert = user_load($uid);
      if($to == '') $to = isset($expert->mail) ? $expert->mail : '';
      else $to .= isset($expert->mail) ? ',' . $expert->mail : '';
    }
  }

  // Send copy to the user sending the emails
  $to .= ',' . $account->mail;

  $from = $site_name . '<' . $account->mail . '>';

  $params = array(
    'body' => $multstep_values['conflict_mail_body']['mail']['value'],
    'subject' => 'Reminder from ' . $site_name,
  );

  $language = language_default();
  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);

  if ($result['result'] == TRUE) {
    drupal_set_message('You have sent emails reminding the selected experts to declare any missing conflict of interest. A copy of the email is sent to your email address.');
  }
  else {
    drupal_set_message('There was a problem sending your message and it was not sent.', 'error');
  }

}
