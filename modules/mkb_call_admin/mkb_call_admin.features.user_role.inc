<?php
/**
 * @file
 * mkb_call_admin.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function mkb_call_admin_user_default_roles() {
  $roles = array();

  // Exported role: call administrator.
  $roles['call administrator'] = array(
    'name' => 'call administrator',
    'weight' => 4,
  );

  return $roles;
}
