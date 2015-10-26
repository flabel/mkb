<?php
/**
 * @file
 * mkb_pm.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mkb_pm_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create application_project_publish content'.
  $permissions['create application_project_publish content'] = array(
    'name' => 'create application_project_publish content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create application_publish_conf content'.
  $permissions['create application_publish_conf content'] = array(
    'name' => 'create application_publish_conf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application_project_publish content'.
  $permissions['delete any application_project_publish content'] = array(
    'name' => 'delete any application_project_publish content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application_publish_conf content'.
  $permissions['delete any application_publish_conf content'] = array(
    'name' => 'delete any application_publish_conf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application_project_publish content'.
  $permissions['delete own application_project_publish content'] = array(
    'name' => 'delete own application_project_publish content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application_publish_conf content'.
  $permissions['delete own application_publish_conf content'] = array(
    'name' => 'delete own application_publish_conf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any application_project_publish content'.
  $permissions['edit any application_project_publish content'] = array(
    'name' => 'edit any application_project_publish content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any application_publish_conf content'.
  $permissions['edit any application_publish_conf content'] = array(
    'name' => 'edit any application_publish_conf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own application_project_publish content'.
  $permissions['edit own application_project_publish content'] = array(
    'name' => 'edit own application_project_publish content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own application_publish_conf content'.
  $permissions['edit own application_publish_conf content'] = array(
    'name' => 'edit own application_publish_conf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
