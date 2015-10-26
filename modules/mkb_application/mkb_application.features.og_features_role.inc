<?php
/**
 * @file
 * mkb_application.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function mkb_application_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:group:project editor'.
  $roles['node:group:project editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'group',
    'name' => 'project editor',
  );

  // Exported OG Role: 'node:group:project partner'.
  $roles['node:group:project partner'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'group',
    'name' => 'project partner',
  );

  return $roles;
}
