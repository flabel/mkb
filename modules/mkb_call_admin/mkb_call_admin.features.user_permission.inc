<?php
/**
 * @file
 * mkb_call_admin.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mkb_call_admin_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create call_funder_page content'.
  $permissions['create call_funder_page content'] = array(
    'name' => 'create call_funder_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create call_main_page content'.
  $permissions['create call_main_page content'] = array(
    'name' => 'create call_main_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create call_topic content'.
  $permissions['create call_topic content'] = array(
    'name' => 'create call_topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create funding_scheme content'.
  $permissions['create funding_scheme content'] = array(
    'name' => 'create funding_scheme content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create project_page content'.
  $permissions['create project_page content'] = array(
    'name' => 'create project_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any call_funder_page content'.
  $permissions['delete any call_funder_page content'] = array(
    'name' => 'delete any call_funder_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any call_main_page content'.
  $permissions['delete any call_main_page content'] = array(
    'name' => 'delete any call_main_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any call_topic content'.
  $permissions['delete any call_topic content'] = array(
    'name' => 'delete any call_topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any funding_scheme content'.
  $permissions['delete any funding_scheme content'] = array(
    'name' => 'delete any funding_scheme content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any project_page content'.
  $permissions['delete any project_page content'] = array(
    'name' => 'delete any project_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own call_funder_page content'.
  $permissions['delete own call_funder_page content'] = array(
    'name' => 'delete own call_funder_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own call_main_page content'.
  $permissions['delete own call_main_page content'] = array(
    'name' => 'delete own call_main_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own call_topic content'.
  $permissions['delete own call_topic content'] = array(
    'name' => 'delete own call_topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own funding_scheme content'.
  $permissions['delete own funding_scheme content'] = array(
    'name' => 'delete own funding_scheme content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own project_page content'.
  $permissions['delete own project_page content'] = array(
    'name' => 'delete own project_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in funding_mode'.
  $permissions['delete terms in funding_mode'] = array(
    'name' => 'delete terms in funding_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any call_funder_page content'.
  $permissions['edit any call_funder_page content'] = array(
    'name' => 'edit any call_funder_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any call_main_page content'.
  $permissions['edit any call_main_page content'] = array(
    'name' => 'edit any call_main_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any call_topic content'.
  $permissions['edit any call_topic content'] = array(
    'name' => 'edit any call_topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any funding_scheme content'.
  $permissions['edit any funding_scheme content'] = array(
    'name' => 'edit any funding_scheme content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any project_page content'.
  $permissions['edit any project_page content'] = array(
    'name' => 'edit any project_page content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own call_funder_page content'.
  $permissions['edit own call_funder_page content'] = array(
    'name' => 'edit own call_funder_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own call_main_page content'.
  $permissions['edit own call_main_page content'] = array(
    'name' => 'edit own call_main_page content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own call_topic content'.
  $permissions['edit own call_topic content'] = array(
    'name' => 'edit own call_topic content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own funding_scheme content'.
  $permissions['edit own funding_scheme content'] = array(
    'name' => 'edit own funding_scheme content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own project_page content'.
  $permissions['edit own project_page content'] = array(
    'name' => 'edit own project_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
      'project member' => 'project member',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in funding_mode'.
  $permissions['edit terms in funding_mode'] = array(
    'name' => 'edit terms in funding_mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}
