<?php

/**
 * @param $groups
 *   Groups
 * @param $visibility
 *   Visibility: 0 = public groups, 1 = private groups
 * @return $array
 *   Groups.
 */
function mkb_groups_get_groups_by_visibility($groups, $visibility){
  $return_groups = array();
  foreach ($groups as $gid => $group){
    $wrapper = entity_metadata_wrapper('node', $group);
    if($wrapper->group_access->value() == $visibility){
      $return_groups[$gid] = $group;
    }
  }
  return $return_groups;
}

/**
 * @return og_membership_ids
 *   og_membership ids.
 */
function mkb_groups_get_all_groups(){
  $gids = array();
  $query = db_select("node", "node");
  $query ->addField("node", "nid", "nid");
  $query
    ->condition("type", "group")
  ;
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    foreach ($result as $row){
      $gids[] = $row->nid;
    }
  }
  return $gids;
}

/**
 * @param $gid
 *   Group node id
 * @param $uid
 *   User id.
 * @return og_membership_ids
 *   og_membership ids.
 */
function mkb_groups_get_node_ids($gid, $uid){
  $node_ids = array();
  $query = db_select("og_membership", "og_membership");
  $query->leftJoin("node", "node", "node.nid = og_membership.etid");
  $query ->addField("node", "nid", "nid");
  $query
    ->condition("og_membership.entity_type", "node")
    ->condition("og_membership.group_type", "node")
    ->condition("og_membership.gid", $gid)
    ->condition("node.uid", $uid);
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    foreach ($result as $row){
      $node_ids[] = $row->nid;
    }
  }
  return $node_ids;
}

/**
 * @param $gid
 *   Group node id
 * @param $uid
 *   User id.
 * @return og_membership_ids
 *   og_membership ids.
 */
function mkb_groups_get_group_content_ids($gid, $uid){
  $og_membership_ids = array();
  $query = db_select("og_membership", "og_membership");
  $query->leftJoin("node", "node", "node.nid = og_membership.etid");
  $query ->addField("og_membership", "id", "id");
  $query
    ->condition("og_membership.entity_type", "node")
    ->condition("og_membership.group_type", "node")
    ->condition("og_membership.gid", $gid)
    ->condition("node.uid", $uid);
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    foreach ($result as $row){
      $og_membership_ids[] = $row->id;
    }
  }
  return $og_membership_ids;
}

/**
 * @return roles
 *   All organic group roles.
 */
function mkb_groups_get_group_roles(){
  $roles = array();
  $query = db_select("og_role", "og_role");
  $query ->addField("og_role", "rid", "rid");
  $query ->addField("og_role", "name", "name");
  $query
    ->condition("og_role.group_bundle", 'group');
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    foreach ($result as $row){
      $roles[$row->rid] = $row->name;
    }
  }
  return $roles;
}

/**
 * @param $gid
 *   Group node id
 * @return etid
 *   All user og_membership ids.
 */
function mkb_groups_get_group_users($gid){
  $etids = array();
  $query = db_select("og_membership", "og_membership");
  $query ->addField("og_membership", "etid", "etid");
  $query
    ->condition("og_membership.gid", $gid)
    ->condition("og_membership.entity_type", 'user');
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    foreach ($result as $row){
      $etids[] = $row->etid;
    }
  }
  return $etids;
}

function mkb_groups_get_group_document_nid($gid){
  $query = db_select("og_membership", "o");
  $query ->leftJoin("node", "n", "n.nid = o.etid");
  $query ->addField("n", "nid", "nid");
  $query
  ->condition("o.gid", $gid)
  ->condition("o.entity_type", "node")
  ->condition("n.type", "group_docs");
  $result = $query->execute();
  $nid = $result->fetchField();
  return $nid;
}