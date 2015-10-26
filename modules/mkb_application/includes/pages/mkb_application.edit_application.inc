<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Generates content for edit_application template.
 *
 * @param $gid
 *   Group node id
 * @return form
 *   Edit application template.
 */
function edit_application_function($gid){
  $variables = mkb_application_get_group_user_and_roles($gid);
  // Check if user is coordinator or editor (overriding code in mkb_application_get_group_user_and_roles).
  global $user;
  $og_roles = og_get_user_roles('node', $gid, $user->uid);
  $all_og_roles = array_flip(mkb_groups_get_group_roles());

//   $coordinator_rid = $all_og_roles['project coordinator'];
  $editor_rid = $all_og_roles['project editor'];
  $og_roles = og_get_user_roles('node', $gid, $user->uid);

//   $variables['coordinator'] = array('uid' => '', 'is_coordinator' => FALSE);
  if(array_key_exists($editor_rid, $og_roles)){
    $variables['editor'] = array('uid' => $user->uid, 'is_editor' => TRUE);
  }

  return theme('edit_application_template', $variables);
}