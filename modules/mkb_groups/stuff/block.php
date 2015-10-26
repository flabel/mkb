<?php
$_SESSION["mkb_display_meny"] = 'none'; 
$gid = 0;
if (is_numeric(arg(1))) {
$gid = arg(1);
}
if (is_numeric(arg(2))) {
$gid = arg(2);
}
if (is_numeric(arg(3))) {
$gid = arg(3);
}
if ($gid==0){
 $gid=$_SESSION['mkb_gid'];
}
else {
  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $nid = arg(1);
    $node = node_load($nid);
    $type = $node->type;
    if ($type == 'post') $gid=$_SESSION['mkb_gid'];
    if ($type == 'page') $gid=$_SESSION['mkb_gid'];
    if ($type == 'application_project_info') $gid=$_SESSION['mkb_gid'];
    if ($type == 'application_partner_info') $gid=$_SESSION['mkb_gid'];
    if ($type == 'application_partner_budget') $gid=$_SESSION['mkb_gid'];
    if ($type == 'group_docs') $gid=$_SESSION['mkb_gid'];
  }
  else $_SESSION['mkb_gid'] = $gid;
}

  $group_docs_nid = mkb_application_get_group_document_nid($gid);
  print '<div class="block-menu">';
  print '<h2  class="block-title">Work Space</h2>';
  print '<ul class="menu clearfix">';
  print '<li class="first expanded menu-depth-1">Group';
    print '<ul class="menu clearfix">';
      print '<li class="first leaf menu-depth-2">' . l('Home',  'iprojects/workspace/' . $gid) . '</li>';
      print '<li class="leaf menu-depth-2">' . l('Contact members',  'iprojects/workspace/members/' . $gid) . '</li>';
      print '<li class="leaf menu-depth-2">' . l('Search users',  'iprojects/workspace/user-profiles/' . $gid) . '</li>';
      print '<li class="leaf menu-depth-2">' . l('Forum',  'iprojects/workspace/forum/' . $gid) . '</li>';
  if($group_docs_nid){
    print '<li class="leaf menu-depth-2">' . l('Documents',  'node/' . $group_docs_nid) . '</li>';
  }
  else{
    print '<li class="leaf menu-depth-2">' . l('Documents',  'node/add/group-docs') . '</li>';
  }
      print '<li class="leaf menu-depth-2">' . l('Help',  'mkb-group-help') . '</li>';
    print '</li></ul>';

  //Display links if a call-main-page is chosen in group (=application)
/*   $is_application = mkb_application_group_is_application($gid);
  if($is_application){
    print '<li class="expanded menu-depth-1">Application';
    print '<ul class="menu clearfix">'; 
      print '<li class="leaf menu-depth-2">' . l('Manage partners',  'iprojects/workspace/group_members/' . $gid) . '</li>';
      print '<li class="leaf menu-depth-2">' . l('Edit application',  'iprojects/workspace/edit_app/' . $gid) . '</li>';
      print '<li class="leaf menu-depth-2">' . l('Upload DOW',  'iprojects/workspace/dow/' . $gid) . '</li>';
      print '<li class="leaf menu-depth-2">' . l('Submit application',  'iprojects/workspace/application_submit/' . $gid) . '</li>';
      print '<li class="leaf menu-depth-2">' . l('View application',  'iprojects/workspace/application_page/' . $gid) . '</li>';
  }
  else{
    print '<li class="expanded menu-depth-1">Application';
    print '<ul class="menu clearfix">'; 
  }
 */    print '<li class="leaf menu-depth-2">' . l('How to apply',  'node/89/' . $gid) . '</li>';
    print '<li class="leaf menu-depth-2">' . l('Call documents and template',  'iprojects/workspace/call_documents/' . $gid) . '</li>';
  print '</li></ul>';
print '</ul>';
print '</div>';
?>
