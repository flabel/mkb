<?php
/**
 * @file
 * mkb_groups.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function mkb_groups_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:add user'
  $permissions['node:group:add user'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:administer group'
  $permissions['node:group:administer group'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:approve and deny subscription'
  $permissions['node:group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:create group_docs content'
  $permissions['node:group:create group_docs content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:create post content'
  $permissions['node:group:create post content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:delete any group_docs content'
  $permissions['node:group:delete any group_docs content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:delete any post content'
  $permissions['node:group:delete any post content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:delete own group_docs content'
  $permissions['node:group:delete own group_docs content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:delete own post content'
  $permissions['node:group:delete own post content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:edit any main profile'
  $permissions['node:group:edit any main profile'] = array(
    'roles' => array(
      'administrator' => 'administrator',
    ),
  );

  // Exported og permission: 'node:group:manage members'
  $permissions['node:group:manage members'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:manage permissions'
  $permissions['node:group:manage permissions'] = array(
    'roles' => array(
      'administrator' => 'administrator',
    ),
  );

  // Exported og permission: 'node:group:manage roles'
  $permissions['node:group:manage roles'] = array(
    'roles' => array(
      'administrator' => 'administrator',
    ),
  );

  // Exported og permission: 'node:group:subscribe'
  $permissions['node:group:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:group:subscribe without approval'
  $permissions['node:group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:group:unsubscribe'
  $permissions['node:group:unsubscribe'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:update any group_docs content'
  $permissions['node:group:update any group_docs content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:update any post content'
  $permissions['node:group:update any post content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:update group'
  $permissions['node:group:update group'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:update own group_docs content'
  $permissions['node:group:update own group_docs content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:update own post content'
  $permissions['node:group:update own post content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:view any main profile'
  $permissions['node:group:view any main profile'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'non-member' => 'non-member',
      'project coordinator' => 'project coordinator',
    ),
  );

  return $permissions;
}
