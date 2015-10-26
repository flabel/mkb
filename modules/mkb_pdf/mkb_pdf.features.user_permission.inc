<?php
/**
 * @file
 * mkb_pdf.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mkb_pdf_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access PDF version'.
  $permissions['access PDF version'] = array(
    'name' => 'access PDF version',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print_pdf',
  );

  // Exported permission: 'access print'.
  $permissions['access print'] = array(
    'name' => 'access print',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'print',
  );

  // Exported permission: 'administer print'.
  $permissions['administer print'] = array(
    'name' => 'administer print',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'print',
  );

  // Exported permission: 'create application_pdf content'.
  $permissions['create application_pdf content'] = array(
    'name' => 'create application_pdf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any application_pdf content'.
  $permissions['delete any application_pdf content'] = array(
    'name' => 'delete any application_pdf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own application_pdf content'.
  $permissions['delete own application_pdf content'] = array(
    'name' => 'delete own application_pdf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any application_pdf content'.
  $permissions['edit any application_pdf content'] = array(
    'name' => 'edit any application_pdf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own application_pdf content'.
  $permissions['edit own application_pdf content'] = array(
    'name' => 'edit own application_pdf content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'node-specific print configuration'.
  $permissions['node-specific print configuration'] = array(
    'name' => 'node-specific print configuration',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'print_ui',
  );

  return $permissions;
}
