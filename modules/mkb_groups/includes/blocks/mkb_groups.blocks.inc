<?php
module_load_include('inc', 'mkb_groups', 'includes/mkb_groups.helper');

/*
 * Determines visibiblity of groups block
 */
function mkb_groups_block_visibility($delta = '') {
  if ($delta == 'groups') {
//    $_SESSION["mkb_display_meny"] = 'none';
    $account = $GLOBALS['user'];
    // Get group id
    $gid = 0;
    if (arg(0) == 'groups' && arg(1) == 'workspace'){
      for ($i=1; $i<=count(arg()); $i++) {
        if (is_numeric(arg($i))){
          $node = node_load(arg($i));
          if($node !== FALSE){
            if($node->type == 'group'){
              $gid = arg($i);
            }
          }
        }
      }
    }
    elseif(isset($_SESSION['mkb_gid'])){
      $gid = $_SESSION['mkb_gid'];
    }

    if(arg(2) == 'application_page'){
      $workspace_menu = FALSE;
      $etids = (array)mkb_groups_get_group_users($gid);
      if(!in_array($account->uid, $etids)){
        if(in_array('administrator', $account->roles)){
        }
        else{
          return FALSE;
        }
      }
    }

    // Don't display on error pages
    $headers = drupal_get_http_header('status');
    if(strpos($headers,'403') !== false) return false;

    // Don't display when current user is not a member of the group
  // or access permission is not set for current user
  $user_access = FALSE;
    if(og_is_member('node', $gid, 'user', NULL, array(OG_STATE_ACTIVE))) $user_access = TRUE;
    if (user_access('administer group')) $user_access = TRUE;
  if (!$user_access) return FALSE;

    // Determine access for paths
    $match = FALSE;
    // Within groups/workspace path
    if (arg(0) == 'groups' && arg(1) == 'workspace'){
      if(arg(2) != 'rapport_comment') $match = TRUE;
    }
    // Within node/% path
    if (arg(0) == 'node' && is_numeric(arg(1))) {
      $nid = arg(1);
      $node = node_load($nid);
      if($node == FALSE) return FALSE;

      $node_types = array('post','group_docs', 'application_project_info', 'application_partner_info',
          'application_partner_budget', 'application_project_publish', 'webform');
      if (in_array($node->type, $node_types)) $match = TRUE;

      // Specific nodes that are imported. See mkb_groups.features.node_export_features.inc
      $uuids = array('5ca69e93-e378-4939-ada2-64a6b40d7305', '642e6311-1725-47b5-97c3-465dea98c871');
      $imported_nodes = entity_uuid_load('node', $uuids);
      if($imported_nodes){
        foreach ($imported_nodes as $imported_nid => $imported_node){
          if($imported_nid == $nid) $match = TRUE;
        }
      }
    }
    return $match;
  }
}

/*
 * Content for the groups block
 */
function mkb_groups_block_content() {
  $content = '';
  $gid = mkb_groups_block_content_gid();
  if($gid == 0) return $content;

  $this_page = drupal_get_destination();
  $group_docs_nid = mkb_groups_get_group_document_nid($gid);
  $content.= '<div class="block-menu">';
  $content.= '<ul class="menu clearfix">';
  $content.= '<li class="first leaf menu-depth-1">' . l('Edit group page',  'node/' . $gid . '/edit', array('query' => $this_page)) . '</li>';
  $content.= '<li class="first leaf menu-depth-1">' . l('Contact members',  'groups/workspace/members/' . $gid) . '</li>';
  $content.= '<li class="leaf menu-depth-1">' . l('Manage members',  'groups/workspace/manage_members/' . $gid) . '</li>';
  $content.= '<li class="leaf menu-depth-1">' . l('Forum',  'groups/workspace/forum/' . $gid) . '</li>';
  if($group_docs_nid){
    $content.= '<li class="leaf menu-depth-1">' . l('Documents',  'node/' . $group_docs_nid) . '</li>';
  }
  else{
    $content.= '<li class="leaf menu-depth-1">' . l('Documents',  'node/add/group-docs') . '</li>';
  }

  // get "How to mangage your groups (alias: mkb-group-help)" basic page nid
  $imported_nodes = entity_uuid_load('node', $uuids = array('5ca69e93-e378-4939-ada2-64a6b40d7305'));
  $nid = 0;
  if(isset($imported_nodes)){
    foreach ($imported_nodes as $imported_nid => $imported_node){
      if($imported_node->type == 'page') $nid = $imported_nid;
    }
  }

  $content.= '<li class="leaf menu-depth-1">' . l('Help',  'node/' . $nid) . '</li>';
  $content.= '</ul>';
  $content.= '</div>';
  return $content;
}

function mkb_groups_block_content_gid(){
  $gid = 0;
  for ($i=1; $i<=count(arg()); $i++) {
    if (is_numeric(arg($i))){
      $node = node_load(arg($i));
      if($node !== FALSE){
        if($node->type == 'group'){
          $gid = arg($i);
        }
      }
    }
  }

  if ($gid==0){
   $gid=$_SESSION['mkb_gid'];
  }
  else {
    if (arg(0) == 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $node = node_load($nid);
    $type = $node->type;
    $node_types = array('post','page','group_docs', 'application_project_info', 'application_partner_info',
        'application_partner_budget');
    if (in_array($type, $node_types)) $gid=$_SESSION['mkb_gid'];
    }
    else $_SESSION['mkb_gid'] = $gid;
  }
  return $gid;
}
