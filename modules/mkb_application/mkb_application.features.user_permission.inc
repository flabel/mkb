<?php
/**
 * @file
 * mkb_application.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mkb_application_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create application_partner_budget content'.
  $permissions['create application_partner_budget content'] = array(
    'name' => 'create application_partner_budget content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create application_partner_info content'.
  $permissions['create application_partner_info content'] = array(
    'name' => 'create application_partner_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create application_project_info content'.
  $permissions['create application_project_info content'] = array(
    'name' => 'create application_project_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application_partner_budget content'.
  $permissions['delete any application_partner_budget content'] = array(
    'name' => 'delete any application_partner_budget content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application_partner_info content'.
  $permissions['delete any application_partner_info content'] = array(
    'name' => 'delete any application_partner_info content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application_project_info content'.
  $permissions['delete any application_project_info content'] = array(
    'name' => 'delete any application_project_info content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application_partner_budget content'.
  $permissions['delete own application_partner_budget content'] = array(
    'name' => 'delete own application_partner_budget content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application_partner_info content'.
  $permissions['delete own application_partner_info content'] = array(
    'name' => 'delete own application_partner_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application_project_info content'.
  $permissions['delete own application_project_info content'] = array(
    'name' => 'delete own application_project_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any application_partner_budget content'.
  $permissions['edit any application_partner_budget content'] = array(
    'name' => 'edit any application_partner_budget content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any application_partner_info content'.
  $permissions['edit any application_partner_info content'] = array(
    'name' => 'edit any application_partner_info content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any application_project_info content'.
  $permissions['edit any application_project_info content'] = array(
    'name' => 'edit any application_project_info content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own application_partner_budget content'.
  $permissions['edit own application_partner_budget content'] = array(
    'name' => 'edit own application_partner_budget content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own application_partner_info content'.
  $permissions['edit own application_partner_info content'] = array(
    'name' => 'edit own application_partner_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own application_project_info content'.
  $permissions['edit own application_project_info content'] = array(
    'name' => 'edit own application_project_info content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  return $permissions;
}
