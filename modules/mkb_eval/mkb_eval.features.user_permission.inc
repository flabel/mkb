<?php
/**
 * @file
 * mkb_eval.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function mkb_eval_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create eval_expert_application content'.
  $permissions['create eval_expert_application content'] = array(
    'name' => 'create eval_expert_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create evaluation content'.
  $permissions['create evaluation content'] = array(
    'name' => 'create evaluation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create evaluation_conf content'.
  $permissions['create evaluation_conf content'] = array(
    'name' => 'create evaluation_conf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create evaluation_conflict content'.
  $permissions['create evaluation_conflict content'] = array(
    'name' => 'create evaluation_conflict content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create evaluation_filter content'.
  $permissions['create evaluation_filter content'] = array(
    'name' => 'create evaluation_filter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create evaluation_view content'.
  $permissions['create evaluation_view content'] = array(
    'name' => 'create evaluation_view content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'create expert_evaluators content'.
  $permissions['create expert_evaluators content'] = array(
    'name' => 'create expert_evaluators content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any eval_expert_application content'.
  $permissions['delete any eval_expert_application content'] = array(
    'name' => 'delete any eval_expert_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any evaluation content'.
  $permissions['delete any evaluation content'] = array(
    'name' => 'delete any evaluation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any evaluation_conf content'.
  $permissions['delete any evaluation_conf content'] = array(
    'name' => 'delete any evaluation_conf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any evaluation_conflict content'.
  $permissions['delete any evaluation_conflict content'] = array(
    'name' => 'delete any evaluation_conflict content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any evaluation_filter content'.
  $permissions['delete any evaluation_filter content'] = array(
    'name' => 'delete any evaluation_filter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any evaluation_view content'.
  $permissions['delete any evaluation_view content'] = array(
    'name' => 'delete any evaluation_view content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any expert_evaluators content'.
  $permissions['delete any expert_evaluators content'] = array(
    'name' => 'delete any expert_evaluators content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own eval_expert_application content'.
  $permissions['delete own eval_expert_application content'] = array(
    'name' => 'delete own eval_expert_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own evaluation content'.
  $permissions['delete own evaluation content'] = array(
    'name' => 'delete own evaluation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own evaluation_conf content'.
  $permissions['delete own evaluation_conf content'] = array(
    'name' => 'delete own evaluation_conf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own evaluation_conflict content'.
  $permissions['delete own evaluation_conflict content'] = array(
    'name' => 'delete own evaluation_conflict content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own evaluation_filter content'.
  $permissions['delete own evaluation_filter content'] = array(
    'name' => 'delete own evaluation_filter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own evaluation_view content'.
  $permissions['delete own evaluation_view content'] = array(
    'name' => 'delete own evaluation_view content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own expert_evaluators content'.
  $permissions['delete own expert_evaluators content'] = array(
    'name' => 'delete own expert_evaluators content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any eval_expert_application content'.
  $permissions['edit any eval_expert_application content'] = array(
    'name' => 'edit any eval_expert_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any evaluation content'.
  $permissions['edit any evaluation content'] = array(
    'name' => 'edit any evaluation content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any evaluation_conf content'.
  $permissions['edit any evaluation_conf content'] = array(
    'name' => 'edit any evaluation_conf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any evaluation_conflict content'.
  $permissions['edit any evaluation_conflict content'] = array(
    'name' => 'edit any evaluation_conflict content',
    'roles' => array(
      'administrator' => 'administrator',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any evaluation_filter content'.
  $permissions['edit any evaluation_filter content'] = array(
    'name' => 'edit any evaluation_filter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any evaluation_view content'.
  $permissions['edit any evaluation_view content'] = array(
    'name' => 'edit any evaluation_view content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any expert_evaluators content'.
  $permissions['edit any expert_evaluators content'] = array(
    'name' => 'edit any expert_evaluators content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own eval_expert_application content'.
  $permissions['edit own eval_expert_application content'] = array(
    'name' => 'edit own eval_expert_application content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own evaluation content'.
  $permissions['edit own evaluation content'] = array(
    'name' => 'edit own evaluation content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own evaluation_conf content'.
  $permissions['edit own evaluation_conf content'] = array(
    'name' => 'edit own evaluation_conf content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own evaluation_conflict content'.
  $permissions['edit own evaluation_conflict content'] = array(
    'name' => 'edit own evaluation_conflict content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own evaluation_filter content'.
  $permissions['edit own evaluation_filter content'] = array(
    'name' => 'edit own evaluation_filter content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own evaluation_view content'.
  $permissions['edit own evaluation_view content'] = array(
    'name' => 'edit own evaluation_view content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own expert_evaluators content'.
  $permissions['edit own expert_evaluators content'] = array(
    'name' => 'edit own expert_evaluators content',
    'roles' => array(
      'call administrator' => 'call administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
