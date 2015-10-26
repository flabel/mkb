<?php
module_load_include('inc', 'mkb_application', 'includes/mkb_application.helper');

/**
 * Generates content for group_members form.
 *
 * @param $gid
 *   Group node id
 * @return form
 *   Group members form.
 */
function mkb_application_group_members_form($form, &$form_state, $gid){

  $form['my_title'] = array(
      '#markup' => '<h2 class="block-title">Application consortium members</h2><p>The consortium members shall be companies/organisations represented by the selected persons. Only one person per company/organisation.</p>',
      );

  // New member
  $form['new_member_container'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('container-inline')),
      );
  $form['new_member_container']['new_member'] = array(
    '#type' => 'textfield',
    '#title' => t('Select website user by name'),
    '#description' => '',
    '#autocomplete_path' => 'realname/autocomplete',
  );

  $form['new_member_container']['new_member_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add user to group'),
    '#submit' => array('mkb_application_new_member_submit'),
    '#validate' => array('mkb_application_new_member_validate'),
  );

  // Manage members table
  $header = array('Name', 'State', 'Roles', 'Member since', 'Request message');

  $rows = array();
  $etids = (array)mkb_groups_get_group_users($gid);
  $accounts = user_load_multiple($etids);
  $realnames = realname_load_multiple($accounts);

  $og_memberships = array();
  foreach ($etids as $i => $etid){
    $og_memberships[$etid] = og_get_membership('node', $gid, 'user', $etid);
  }

  $options = array();
  $content_states = og_group_content_states();
  $default_value = 0;
  foreach ($etids as $etid){
    if ($etid === reset($etids)) $default_value = $etid;
    $roles = og_get_user_roles('node', $gid, $etid);
    $state = $content_states[$og_memberships[$etid]->state];
    $created = format_interval(time() - $og_memberships[$etid]->created, 1). ' '. t('ago');
    if(isset($roles)){
      $role_string = '<ul>';
      foreach ($roles as $role){
        if($role !== 'member') $role_string .= '<li>' . $role . '</li>';
      }
      $role_string .= '</ul>';
    }
    else{
      $role_string = '';
    }
    $options[$etid] = array(
        0 => $realnames[$etid],
        1 => $state,
        2 => $role_string,
        3 => $created,
        4 => isset($og_memberships[$etid]->og_membership_request) ? $og_memberships[$etid]->og_membership_request : '',
        );
  }

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#empty' => t('No users found'),
    '#multiple' => FALSE,
    '#default_value' => $default_value,
  );

  $op_options = array(
      0 => 'Remove user',
      1 => 'New project coordinator',
      'Add Roles' => array(
          2 => 'Add project editor',
          3 => 'Add project partner',
          ),
      'Remove roles' => array(
          4 => 'Remove project editor',
          5 => 'Remove project partner',
          ),
  );

  $form['operations_container'] = array(
      '#type' => 'container',
      '#attributes' => array('class' => array('container-inline')),
  );

  $form['operations_container']['operations'] = array(
    '#type' => 'select',
    '#title' => t('Operations'),
    '#options' => $op_options,
    '#description' => '',
    '#empty_option' => '- Select -',
    '#required' => FALSE,
  );

  $form['operations_container']['manage_members_submit'] = array(
    '#type' => 'submit',
    '#value' => t('Execute'),
    '#submit' => array('mkb_application_manage_members_submit'),
    '#validate' => array('mkb_application_manage_members_validate'),
  );

  return $form;
}

/**
 * @param $form
 *   form.
 * @param $form_state
 *   form_state.
 */
function mkb_application_new_member_validate($form, $form_state){
}

/**
 * @param $form
 *   form.
 * @param $form_state
 *   form_state.
 */
function mkb_application_new_member_submit($form, $form_state){
  $gid = $form_state['build_info']['args'][0];
  if(mkb_application_is_coordinator_or_editor($gid)){
    if(isset($form_state['values']['new_member'])){
      $account = user_load_by_name($form_state['values']['new_member']);

      // Add the user to the group
      og_group('node', $gid, array(
          "entity type"       => "user",
          "entity"        => $account,
          "membership type"   => OG_MEMBERSHIP_TYPE_DEFAULT,
      ));

      // Changes the users role in the group (1 = non-member, 2 = member, 3 = administrator member)
      og_role_grant('node', $gid, $account->uid, 2);
    }
    else{
      drupal_set_message(t('User not found.'), $type = 'warning');
    }
  }
  else{
    drupal_set_message('Only the coordinator and editors are authorized to add users to the group.', $type = 'warning');
  }
}

/**
 * @param $form
 *   form.
 * @param $form_state
 *   form_state.
 */
function mkb_application_manage_members_validate($form, $form_state){
}

/**
 * @param $form
 *   form.
 * @param $form_state
 *   form_state.
 */
function mkb_application_manage_members_submit($form, $form_state){
  $gid = $form_state['build_info']['args'][0];
  if(mkb_application_is_coordinator_or_editor($gid)){
    // Get selected user
    $selected_uid = $form_state['values']['table'];
    $selected_account = user_load($selected_uid);

    // Get selected operation
    $operation = $form_state['values']['operations'];

    // Get og membership and roles for selected user
    $og_membership = og_get_membership('node', $gid, 'user', $selected_uid);
    $og_roles = og_get_user_roles('node', $gid, $selected_uid);
    // Get all og roles
    $all_og_roles = array_flip(mkb_groups_get_group_roles());

    switch ($operation) {
        // Remove user
        case 0:
          $group = node_load($gid);
          $coordinator_uid = $group->uid;
          if($coordinator_uid == $selected_uid){
            drupal_set_message('Please assign a new coordinator before removing the user that is currently coordinator.', $type = 'warning');
          }
          else{
            // Remove user from group
            og_ungroup('node', $gid, 'user', $selected_uid);
            // Delete og_membership and nodes created by this user
            $og_membership_ids = mkb_groups_get_group_content_ids($gid, $selected_uid);
            $node_ids = mkb_groups_get_node_ids($gid, $selected_uid);
            if (!empty($og_membership_ids)) {
              og_membership_delete_multiple($og_membership_ids);
              if (!empty($og_membership_ids)) {
                node_delete_multiple($node_ids);
              }
            }
          }
          break;
        // New project coordinator
        case 1:
            $group = node_load($gid);
            $coordinator_uid = $group->uid;
            $rid = $all_og_roles['project coordinator'];

            // Remove coordinator role
            $coordinator_og_membership = og_get_membership('node', $gid, 'user', $coordinator_uid);
            og_role_revoke('node', $gid, $coordinator_uid, $rid);
            $coordinator_og_membership->save();

            // Add coordinator role to selected user
            og_role_revoke('node', $gid, $selected_uid, $rid);

            // If selected user is partner: remove partner role
            $rid = $all_og_roles['project partner'];
            $og_roles = og_get_user_roles('node', $gid, $selected_uid);
            if(array_key_exists($rid, $og_roles)){
              og_role_revoke('node', $gid, $selected_uid, $rid);
            }
            $og_membership->save();


            // Set selected user as author in group
            $group->uid = $selected_uid;
            node_save($group);

            // Set selected user as author in application-project-info
            $group_content_nids = mkb_application_get_group_content($gid, 'application_project_info');
            if(isset($group_content_nids[0])){
              $application_info = node_load($group_content_nids[0]);
              $application_info->uid = $selected_uid;
//               dpm($application_info);
              node_save($application_info);
            }
            break;
        // Add Project editor
        case 2:
            $rid = $all_og_roles['project editor'];
            og_role_grant('node', $gid, $selected_uid, $rid);
            $og_membership->save();
            break;
        // Add Project partner
        case 3:
            $rid = $all_og_roles['project partner'];
            og_role_grant('node', $gid, $selected_uid, $rid);
            $og_membership->save();
            break;
        // Remove Project editor
        case 4:
            $rid = $all_og_roles['project editor'];
            og_role_revoke('node', $gid, $selected_uid, $rid);
            $og_membership->save();
            break;
        // Remove Project partner
        case 5:
            // Remove role
            $rid = $all_og_roles['project partner'];
            og_role_revoke('node', $gid, $selected_uid, $rid);
            $og_membership->save();
            // Remove application-partner-info and application-partner-budget
            $node_ids = mkb_application_get_node_type_ids($gid, $selected_uid, array('application_partner_info',
                'application_partner_budget'));
            node_delete_multiple($node_ids);
            break;
    }
  }
  else{
    drupal_set_message('Only the coordinator and editors are authorized to alter roles.', $type = 'warning');
  }
}
