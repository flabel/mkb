<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper.inc');

/**
 * Generate a header which informs the user of which stage they're on.
 *
 * @param type $form
 * @param type $form_state
 * @return type
 */
function mkb_eval_eval_missing_get_header($form, &$form_state) {

  $form_state['stage'] = isset($form_state['stage']) ? $form_state['stage'] : 1;

  $form_stages = array(
    'eval_select_users' => 1,
    'eval_mail_body' => 2,
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
function mkb_eval_eval_missing_move_to_next_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'eval_select_users':
      return 'eval_mail_body';
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

function mkb_eval_eval_missing_move_to_previous_stage($form, &$form_state) {

  switch ($form_state['stage']) {
    case 'eval_mail_body':
      return 'eval_select_users';
     break;
  }

}

/**
 * Master form which calls an individual form for each step.
 *
 * @see mkb_eval_eval_missing_form_form_validate().
 * @see mkb_eval_eval_missing_form_form_submit().
 *
 * @param $form
 * @param $form_state
 * @param $cid
 *   Call-main-page nid.
 * @param $fid
 *   Evaluation filter nid.
 * @return type
 */
function mkb_eval_eval_missing_form($form, &$form_state, $cid, $fid){
  if (!isset($form_state['stage'])) $form_state['stage'] = 'eval_select_users';

  $form = array();
  $form = mkb_eval_eval_missing_get_header($form, $form_state);

  switch ($form_state['stage']) {

    case 'eval_select_users':
      return mkb_eval_eval_select_users_form($form, $form_state, $cid, $fid);
     break;

    case 'eval_mail_body':
      return mkb_eval_eval_mail_body_form($form, $form_state, $cid);
     break;

    default:
      return mkb_eval_eval_select_users_form($form, $form_state, $cid, $fid);
     break;
  }

  return $form;
}

/**
 * @param $cid
 *   Call-main-page nid.
 * @param $eval_conf_nid
 *   Evaluation configuration nid.
 * @param $fid
 *   Evaluation filter nid.
 * @return form
 *   Form to select users to recieve the reminder of missing evaluation
 */
function mkb_eval_eval_select_users_form($form, &$form_state, $cid, $eval_conf_nid, $fid){
  // Load values from form_state
  $values = isset($form_state['multistep_values']['eval_select_users']) ?
    $form_state['multistep_values']['eval_select_users'] : array();

  $header = array('Name', 'Role(s)', 'Application(s)');

  $options = array();
  $expert_groups = array();

  // Rows
  $rows = array();
  foreach ($groups as $gid => $group){
    // Get project_info
    $project_info = $group->applications['application_project_info'];
    $project_info_wrapper = entity_metadata_wrapper('node', $project_info);
    $acronym = $project_info_wrapper->field_app_acronym->value();

    // Get expert evaluators
    $expert_evaluators = NULL;
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'expert_evaluators')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
      ->fieldCondition('field_eval_conf', 'target_id', $eval_conf_nid, '=');
    $result = $query->execute();

    if (isset($result['node'])) {
      $expert_evaluators_nids = array_keys($result['node']);
      $expert_evaluators = node_load($expert_evaluators_nids[0]);
    }

    // Get all evaluations for this group and eval_conf
    $group_evaluations = NULL;
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'evaluation')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('og_group_ref', 'target_id', $gid, '=')
      ->fieldCondition('field_eval_conf', 'target_id', $eval_conf_nid, '=');
    $result = $query->execute();

    if (isset($result['node'])) {
      $group_evaluation_nids = array_keys($result['node']);
      $group_evaluations = entity_load('node', $group_evaluation_nids);
    }

    if(isset($expert_evaluators)){
      $expert_evaluators_wrapper = entity_metadata_wrapper('node', $expert_evaluators);

      foreach ($expert_evaluators_wrapper->field_expert_application_id->getIterator() as $delta => $expert_application_wrapper) {
        // Expert application
        $expert_application = $expert_application_wrapper->value();

        // Filter expert applications by eval_conf and selected
        $expert_application_eval_conf_nids = $expert_application_wrapper->field_eval_conf_id->raw();
        $selected_list = $expert_application_wrapper->field_expert_selected->value();

        if(!$selected_list) $selected_list = array();
        if(in_array($eval_conf_nid, $expert_application_eval_conf_nids) && in_array($eval_conf_nid, $selected_list)){

          // Expert application user
          $evaluator = $expert_application_wrapper->field_expert_usr->value();
          $name = ($evaluator->realname != '') ? $evaluator->realname : $evaluator->name;
          $evaluator_str .= '<li>' . $name . ': ';

          if(isset($group_evaluations)){
            // Add image to evaluator_str according to evaluations
            $eval_exist = FALSE;
            foreach ($group_evaluations as $group_evaluation){
              if($evaluator->uid == $group_evaluation->uid){
                $eval_exist = TRUE;
                $eval_exist_evaluation = $group_evaluation;
              }
            }

            if($eval_exist){
              $eval_exist_evaluation_wrapper = entity_metadata_wrapper('node', $eval_exist_evaluation);
              $eval_submit = $eval_exist_evaluation_wrapper->field_eval_submit->value();

              if($eval_submit == 1) {
                $evaluator_str .= ' ' . mkb_eval_link_img($eval_created_img, $eval_exist_evaluation, $gid);
              }
              elseif($eval_submit == 0){
                $evaluator_str .= ' ' . mkb_eval_link_img($eval_not_approved_img, $eval_exist_evaluation, $gid);
                $status = '<b>Incomplete</b>';
              }
            }
            else{
              $evaluator_str .= ' ' . $eval_missing_img;
              $status = '<b>Incomplete</b>';
            }
          }
          else{
            $evaluator_str .= ' ' . $eval_missing_img;
            $status = '<b>Incomplete</b>';
          }
        }
      }
    }

  }

//   // Close all the lists in 'roles' and 'application' in options
//   foreach ($options as $option){
//     // Roles
//     $option[1] .= '</ul>';
//     // Applications
//     $option[2] .= '</ul>';
//   }

//   // Set options to TRUE and FALSE instead of uids
//   $default_value = NULL;
//   if(isset($values['table'])){
//     foreach ($values['table'] as $uid => $option){
//       if($option == 0) $default_value[$uid] = FALSE;
//       else $default_value[$uid] = TRUE;
//     }
//   }

//   $form['table'] = array(
//     '#type' => 'tableselect',
//     '#header' => $header,
//     '#options' => $options,
//     '#empty' => 'All users registred as application expert has created an evaluation',
//     '#multiple' => TRUE,
//     '#default_value' => $default_value,
//   );

//   $form['next'] = array(
//     '#type' => 'submit',
//     '#value' => 'Next',
//   );

  return $form;
}

/**
 * @param $cid
 *   Call-main-page nid.
 * @return form
 *   Write email body and send email.
 */
function mkb_eval_eval_mail_body_form($form, &$form_state, $cid){
  $account = $GLOBALS['user'];

  $values = isset($form_state['multistep_values']['eval_mail_body']) ?
    $form_state['multistep_values']['eval_mail_body'] : array();

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
      $values['mail']['value'] : mkb_eval_eval_mail_body_default(),
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
function mkb_eval_eval_mail_body_default(){
  $website = l('CORE-ORGANIC website', $GLOBALS['base_url']);

  $default = '<p>Dear evaluator,</p>';
  $default .= '<p>This is a reminder from the ' . $website . '.You are registred as expert evaluator and we kindly remind you to evaluate the applications you are assigned to.</p>';
  $default .= '<p>Best regards,</p>';
  $default .= '<p>Call adminstrators of ' . variable_get('site_name', '') . '</p>';
  return $default;
}

/**
 * Handles what to do with the submitted form depending on what stage has been
 * completed.
 *
 * @see mkb_eval_eval_missing_form()
 * @see mkb_eval_eval_missing_validate()
 *
 * @param type $form
 * @param type $form_state
 */
function mkb_eval_eval_missing_form_submit($form, &$form_state) {

  switch ($form_state['stage']) {

    case 'eval_mail_body':
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      if ($form_state['triggering_element']['#value'] != 'Back') {
        mkb_eval_eval_mail_body_form_submit($form, $form_state);
        $form_state['complete'] = TRUE;
      }
     break;

    default:
      $form_state['multistep_values'][$form_state['stage']] = $form_state['values'];
      $form_state['new_stage'] = mkb_eval_eval_missing_move_to_next_stage($form, $form_state);
     break;

  }

  if (isset($form_state['complete'])){
    drupal_goto($GLOBALS['base_url'] . '/eval/application_experts/41');
  }

  if ($form_state['triggering_element']['#value'] == 'Back') {
    $form_state['new_stage'] = mkb_eval_eval_missing_move_to_previous_stage($form, $form_state);
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
function mkb_eval_eval_mail_body_form_submit($form, &$form_state) {
  $account = $GLOBALS['user'];

  $multstep_values = $form_state['multistep_values'];

  $module = 'mkb_eval';
  $key = 'mkb_eval_eval';
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
    'body' => $multstep_values['eval_mail_body']['mail']['value'],
    'subject' => 'Reminder from ' . $site_name,
  );

  $language = language_default();
  $send = TRUE;
  $result = drupal_mail($module, $key, $to, $language, $params, $from, $send);

  if ($result['result'] == TRUE) {
    drupal_set_message('You have sent emails reminding the selected experts to create any missing evaluations. A copy of the email is sent to your email address.');
  }
  else {
    drupal_set_message('There was a problem sending your message and it was not sent.', 'error');
  }

}
