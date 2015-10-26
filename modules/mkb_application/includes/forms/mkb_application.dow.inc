<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * @param $form
 *   form.
 * @param $form_state
 *   form_state.
 */
function mkb_application_dow_form_validate($form, &$form_state) {
  if (!isset($form_state['values']['dow']) || !is_numeric($form_state['values']['dow'])) {
    form_set_error('Description of work', t('Please select a file to upload.'));
  }
}

/**
 * @param $form
 *   form.
 * @param $form_state
 *   form_state.
 */
function mkb_application_dow_form_submit($form, &$form_state) {
  $gid = $form_state['build_info']['args'][0];
  $group_content_nids = mkb_application_get_group_content($gid, 'application_project_info');
  if (empty($group_content_nids)) {
    drupal_set_message('Cannot upload DOW because Project info has not been created', 'error');
	drupal_goto('/groups/workspace/dow/' . $gid);
  }
  $project_info = node_load($group_content_nids[0]);

  $fid = variable_get('dow', FALSE);
  // Save with no file
  if($form_state['values']['dow'] == 0 && isset($fid)){
    // Delete file
    $file = $fid ? file_load($fid) : FALSE;
    if($file){
      // Delete file
      file_usage_delete($file, 'file', 'node', 1);
      file_delete($file, $force = TRUE);
      // Remove reference to file in node and save
      unset($project_info->field_app_dow['und'][0]);
      node_save($project_info);
      variable_del('dow');
    }
  }
  // Save with file
  elseif($form_state['values']['dow'] > 0){
    $file = file_load($form_state['values']['dow']);
    // Change status to permanent.
    $file->status = FILE_STATUS_PERMANENT;
    file_save($file);
    // Record that the module (in this example, node module) is using the file.
    file_usage_add($file, 'file', 'node', $group_content_nids[0]);

    // Save the node with reference to file
    $project_info->field_app_dow['und'][] = array(
      'fid' => $file->fid,
      'display' => 1,
      'description' => '',
    );
    node_save($project_info);
    variable_del('dow');
  }
}

/**
 * @param $form
 *   form.
 * @param $form_state
 *   form_state.
 * @return $form
 */
function mkb_application_dow_form($form, &$form_state, $gid){
  $fid = 0;
  if (!isset($form_state['values']['dow']) || !is_numeric($form_state['values']['dow'])) {
    $group_content_nids = mkb_application_get_group_content($gid, 'application_project_info');
    if(!empty($group_content_nids)){
      $project_info_node = node_load($group_content_nids[0]);
      if(isset($project_info_node->field_app_dow['und'][0]['fid'])){
        $fid = $project_info_node->field_app_dow['und'][0]['fid'];
      }
    }
    if (empty($group_content_nids)) {
      drupal_set_message('Cannot upload DOW because Project info has not been created', 'error');
    }

  }
  else{
    $fid = $form_state['values']['dow'];
  }
	variable_set('dow', $fid);

  $form['my_title'] = array(
      '#markup' => '<h2 class="block-title">Description of work</h2>',
      );
//  if ($fid) {
    $form['dow'] = array(
      '#title' => '</br>',
      '#type' => 'managed_file',
      '#description' => 'Allowed extensions: pdf.</br><b>Important: If you upload a file or remove an existing file
        please remember to save.</b>',
      '#default_value' => $fid,
      '#upload_location' => 'private://dow/',
      '#upload_validators' => array(
        'file_validate_extensions' => array('pdf'),
       ),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Save',
    );
//  }

  return $form;
}
