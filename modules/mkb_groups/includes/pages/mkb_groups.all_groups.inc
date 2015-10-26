<?php
module_load_include('inc', 'mkb_groups', 'includes/mkb_groups.helper');

/**
 * @return $template
 *   Rendered my_groups_template
 */
function mkb_groups_all_groups_function($cid){
  $variables = array();
  $account = $GLOBALS['user'];
  // Get all groups
  $gids = og_get_all_group('node');
//dpm($gids);
  $gids = mkb_groups_get_all_groups();
//dpm($gids);
  $groups = node_load_multiple($gids);
  foreach($groups as $gid => $group){
    if (empty($group -> field_group_application)) {
	  unset($groups[$gid]);
	}
    elseif ($group -> field_group_application['und'][0]['target_id'] != $cid) {
	  unset($groups[$gid]);
	}
  }
  // Private groups
  $private_groups = mkb_groups_get_groups_by_visibility($groups, 1);
  $private_header = array('Private groups (confidential)', 'Workspace');
  $private_rows = array();

  foreach($private_groups as $gid => $group){
    $author = user_load($group->uid);
    $wrapper = entity_metadata_wrapper('node', $group);
    $workspace = '</br>' . l('Workspace', 'groups/workspace/members/' . $gid); 
	if ($author->uid == $account->uid) {
	  $workspace.= '</br>' . l('Delete group', 'node/' . $gid . '/delete', array('query' => array('destination' => 'groups/all_groups/' . $cid) ));
	}
	if (in_array('administrator', $account->roles)) {
	  $workspace.= '</br>' . l('Admin delete', 'node/' . $gid . '/delete', array('query' => array('destination' => 'groups/all_groups/' . $cid) ));
	}
    $private_rows[$gid] = array(
        'group' => '<b>' . $wrapper->title->value() . '</b>'
		. '</br>' . $wrapper->body->value->value(array('decode' => FALSE))
		,
        'workspace' => '<nobr>' . l($author->realname, 'user-profile/' . $group->uid) . $workspace 
		,
        );
  }

  // Public groups
  $public_groups = mkb_groups_get_groups_by_visibility($groups, 0);
  $public_header = array('Public groups', 'Workspace');
  $public_rows = array();

  foreach($public_groups as $gid => $group){
    $author = user_load($group->uid);
    $wrapper = entity_metadata_wrapper('node', $group);
    $workspace = '</br>' . l('Workspace', 'groups/workspace/members/' . $gid); 
	if ($author->uid == $account->uid) {
	  $workspace.= '</br>' . l('Delete group', 'node/' . $gid . '/delete', array('query' => array('destination' => 'groups/all_groups/' . $cid) ));
	}
	if (in_array('administrator', $account->roles)) {
	  $workspace.= '</br>' . l('Admin delete', 'node/' . $gid . '/delete', array('query' => array('destination' => 'groups/all_groups/' . $cid) ));
	}
    $public_rows[$gid] = array(
        'group' => '<b>' . $wrapper->title->value() . '</b>'
		. '</br>' . $wrapper->body->value->value(array('decode' => FALSE))
		,
        'workspace' => '<nobr>' . l($author->realname, 'user-profile/' . $group->uid) . $workspace 
		,
        );
  }

  $variables['groups'] = array(
      'private' => array('header' => $private_header, 'rows' => $private_rows),
      'public' => array('header' => $public_header, 'rows' => $public_rows),
      );
  return theme('all_groups_template', $variables);
}