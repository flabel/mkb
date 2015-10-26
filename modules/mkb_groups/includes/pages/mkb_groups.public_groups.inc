<?php
module_load_include('inc', 'mkb_groups', 'includes/mkb_groups.helper');

/**
 * @return $template
 *   Rendered public_groups_template
 */
function mkb_groups_public_groups_function(){
  $variables = array();
  $account = $GLOBALS['user'];
//dpm($account);
  // Get all groups
  $gids = og_get_all_group('node');
  $groups = node_load_multiple($gids);

  // Public groups
  $public_groups = mkb_groups_get_groups_by_visibility($groups, 0);
  $public_header = array('Public groups', 'Contact');
  $public_rows = array();

  foreach($public_groups as $gid => $group){
    $author = user_load($group->uid);
    $wrapper = entity_metadata_wrapper('node', $group);

    // Create subscribe link if current user is not member of group
	// Create Workspace link if current user is not member of group
    $subscribe = og_is_member('node', $gid, 'user', $account, array(OG_STATE_ACTIVE)) ?
      l('Workspace', 'groups/workspace/members/' . $gid) : l('Join group', 'group/node/' . $gid . '/subscribe/og_user_node');
	// Add Delete link if current user is owner of group
	if ($author->uid == $account->uid) {
	  $subscribe.= '</br>' . l('Delete group', 'node/' . $gid . '/delete', array('query' => array('destination' => 'groups/public_groups') ));
	}
	// Add Delete link if current user is administrator
	if (in_array('administrator', $account->roles)) {
	  $subscribe.= '</br>' . l('Delete by admin', 'node/' . $gid . '/delete', array('query' => array('destination' => 'groups/public_groups') ));
    }
    $public_rows[$gid] = array(
        'group' => '<b>' . $wrapper->title->value() . '</b></br>' .
        $wrapper->body->value->value(array('decode' => FALSE)),
        'subscribe' => '<nobr>' . l($author->realname, 'user-profile/' . $group->uid) . '</nobr></br>' . $subscribe,
        );
  }

  $variables['groups'] = array(
      'public' => array('header' => $public_header, 'rows' => $public_rows),
      );
  return theme('public_groups_template', $variables);
}