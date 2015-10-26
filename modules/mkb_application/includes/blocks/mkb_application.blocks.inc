<?php

/*
 * Content for the application block
 */
function mkb_application_block_content() {
  $content = '';
  $gid = mkb_groups_block_content_gid();
  if($gid == 0) return $content;
  $call_id = mkb_application_get_call_main_nid($gid);
  if ($call_id != 26957) return $content;

  //Display links if a call-main-page is chosen in group (=application)
  $is_application = mkb_application_group_is_application($gid);
  $content.= '<div class="block-menu">';
  if($is_application){
    $content .= '<ul class="menu clearfix">';
//    $content .= '<li class="first leaf menu-depth-1">' . l('Home',  'groups/workspace/' . $gid) . '</li>';
//    $content .= '<li class="leaf menu-depth-1">' . l('Manage partners',  'groups/workspace/group_members/' . $gid) . '</li>';
//    $content .= '<li class="leaf menu-depth-1">' . l('Edit application',  'groups/workspace/edit_app/' . $gid) . '</li>';
//    $content .= '<li class="leaf menu-depth-1">' . l('Upload DOW',  'groups/workspace/dow/' . $gid) . '</li>';
//    $content .= '<li class="leaf menu-depth-1">' . l('Submit application',  'groups/workspace/application_submit/' . $gid) . '</li>';
//    $content .= '<li class="leaf menu-depth-1">' . l('View application',  'groups/workspace/application_page/' . $gid) . '</li>';
    $content .= '<li class="leaf menu-depth-1">' . l('Evaluation feedback',  'groups/workspace/feedback/' . $gid) . '</li>';
  }
  else{
    $content .= '<ul class="menu clearfix">';
  }

  // get "How to apply" basic page nid
  $imported_nodes = entity_uuid_load('node', $uuids = array('642e6311-1725-47b5-97c3-465dea98c871'));
  $nid = 0;
  if(isset($imported_nodes)){
    foreach ($imported_nodes as $imported_nid => $imported_node){
      if($imported_node->type == 'page') $nid = $imported_nid;
    }
  }

//  $content .= '<li class="leaf menu-depth-1">' . l('How to apply',  'node/' . $nid . '/' . $gid) . '</li>';
//  $content .= '<li class="leaf menu-depth-1">' . l('Call documents and template',  'groups/workspace/call_documents/' . $gid) . '</li>';
  $content .= '</ul>';
  $content.= '</div>';

  $GLOBALS['mkb_current_meny'] = 'by-code';
  return $content;
}
