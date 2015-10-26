<?php
module_load_include('inc', 'mkb_groups', 'includes/mkb_groups.helper');

/**
 * @return $template
 *   Rendered my_groups_template
 */
function mkb_groups_my_groups_function(){
  $variables = array();
  $account = $GLOBALS['user'];
  $gids = og_get_groups_by_user($account, 'node');
  $groups = node_load_multiple($gids);

  foreach($groups as $gid => $group){
    // Rules for a delete option 
    $delete_allowed = false;
    if ($group->uid == $account->uid) $delete_allowed = true;  // Group owner may delete
    if (in_array('administrator',$account->roles)) $delete_allowed = true;  // Administrator may delete
    if (function_exists('mkb_application_get_node_type_ids')) {
      $project_info_nid = mkb_application_get_node_type_ids($gid, $group->uid, array('application_project_info'));
	  if ($project_info_nid) {
	    $project_info = node_load($project_info_nid[0]);
        $wrapper = entity_metadata_wrapper('node', $project_info);
	    if ($wrapper->field_app_submitted->value() > 0) $delete_allowed = false; // Submitted applications may never be deleted
	  }
    }
    $author = user_load($group->uid);
    $wrapper = entity_metadata_wrapper('node', $group);
    $workspace = l($author->realname, 'user-profile/' . $group->uid) . '</br>' . l('Workspace', 'groups/workspace/members/' . $gid);
    if ($delete_allowed) {
	  $workspace .= '</br>' . l('Delete group', 'node/' . $gid . '/delete', array('query' => array('destination' => 'groups/my_groups') )); 
	}
    $rows = array(
        'group' => '<b>' . $wrapper->title->value() . '</b>'
		. '</br>' . $wrapper->body->value->value(array('decode' => FALSE))
		, 'workspace' => $workspace
		,
        );
	if ($wrapper->group_access->value() == 1) $private_rows[$gid] = $rows;
    if ($wrapper->group_access->value() == 0) $public_rows[$gid] = $rows;
  }

  // Private groups
  $private_header = array('Private groups', 'Workspace');

  // Public groups
  $public_header = array('Public groups', 'Workspace');

  $variables['groups'] = array(
      'private' => array('header' => $private_header, 'rows' => $private_rows),
      'public' => array('header' => $public_header, 'rows' => $public_rows),
      );
  return theme('my_groups_template', $variables);
}
