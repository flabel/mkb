<?php
/**
 * @file
 * mkb_groups.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function mkb_groups_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:group:administrator'.
  $roles['node:group:administrator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'group',
    'name' => 'administrator',
  );
  // Exported OG Role: 'node:group:project coordinator'.
  $roles['node:group:project coordinator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'group',
    'name' => 'project coordinator',
  );
  return $roles;
}
