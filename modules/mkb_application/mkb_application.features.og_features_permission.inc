<?php
/**
 * @file
 * mkb_application.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function mkb_application_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:group:add user'
  $permissions['node:group:add user'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:administer group'
  $permissions['node:group:administer group'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:approve and deny subscription'
  $permissions['node:group:approve and deny subscription'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:create application_partner_budget content'
  $permissions['node:group:create application_partner_budget content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'administrator member' => 'administrator member',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:create application_partner_info content'
  $permissions['node:group:create application_partner_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:create application_project_info content'
  $permissions['node:group:create application_project_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
    ),
  );

  // Exported og permission: 'node:group:create group_docs content'
  $permissions['node:group:create group_docs content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:create post content'
  $permissions['node:group:create post content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:delete any application_partner_budget content'
  $permissions['node:group:delete any application_partner_budget content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:delete any application_partner_info content'
  $permissions['node:group:delete any application_partner_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:delete any application_project_info content'
  $permissions['node:group:delete any application_project_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:delete any post content'
  $permissions['node:group:delete any post content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:delete own application_partner_budget content'
  $permissions['node:group:delete own application_partner_budget content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:delete own application_partner_info content'
  $permissions['node:group:delete own application_partner_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:delete own application_project_info content'
  $permissions['node:group:delete own application_project_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:delete own group_docs content'
  $permissions['node:group:delete own group_docs content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:delete own post content'
  $permissions['node:group:delete own post content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
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
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:unsubscribe'
  $permissions['node:group:unsubscribe'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:update any application_partner_budget content'
  $permissions['node:group:update any application_partner_budget content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:update any application_partner_info content'
  $permissions['node:group:update any application_partner_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:update any application_project_info content'
  $permissions['node:group:update any application_project_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:update any group_docs content'
  $permissions['node:group:update any group_docs content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:update any post content'
  $permissions['node:group:update any post content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:update group'
  $permissions['node:group:update group'] = array(
    'roles' => array(
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:update own application_partner_budget content'
  $permissions['node:group:update own application_partner_budget content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'member' => 'member',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:update own application_partner_info content'
  $permissions['node:group:update own application_partner_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:update own application_project_info content'
  $permissions['node:group:update own application_project_info content'] = array(
    'roles' => array(
      'administrator' => 'administrator',
      'project coordinator' => 'project coordinator',
      'project editor' => 'project editor',
    ),
  );

  // Exported og permission: 'node:group:update own group_docs content'
  $permissions['node:group:update own group_docs content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:update own post content'
  $permissions['node:group:update own post content'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  // Exported og permission: 'node:group:view any main profile'
  $permissions['node:group:view any main profile'] = array(
    'roles' => array(
      'project editor' => 'project editor',
      'project partner' => 'project partner',
    ),
  );

  return $permissions;
}
