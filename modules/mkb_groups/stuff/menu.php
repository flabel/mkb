<?php
$headers = drupal_get_http_header('status');
if(strpos($headers,'403') !== false) return false;
$gid = 0;
if (arg(0) == 'iprojects' && arg(1) == 'workspace' && is_numeric(arg(2))){
  $gid = arg(2);
}
elseif(isset($_SESSION['mkb_gid'])){
  $gid = $_SESSION['mkb_gid'];
}
// if(mkb_groups_is_og_member($gid) === FALSE) return FALSE;
$match = FALSE;
if (arg(0) == 'iprojects' && arg(1) == 'workspace') $match = TRUE;
//if (arg(0) == 'node' && arg(1) == 155) $match = TRUE;
if (arg(0) == 'node' && is_numeric(arg(1))) {
  $nid = arg(1);
  $node = node_load($nid);
  $type = $node->type;
  if ($type == 'group') $match = TRUE;
  if ($type == 'post') $match = TRUE;
  if ($type == 'application_project_info') $match = TRUE;
  if ($type == 'application_partner_info') $match = TRUE;
  if ($type == 'application_partner_budget') $match = TRUE;
  if ($type == 'group_docs') $match = TRUE;
  if ($nid == 89 && is_numeric(arg(2))) $match = TRUE;
}
$path = explode('/', $_GET['q']);
if (substr_count($_SERVER["REQUEST_URI"], 'mkb-group-help')) $match = TRUE;
return $match;
?>