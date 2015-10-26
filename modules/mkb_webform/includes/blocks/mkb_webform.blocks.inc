<?php

/*
 * Content for the questionnaire block
 */
function mkb_webform_block_content() {
  $content = '';
  $gid = mkb_groups_block_content_gid();
  if($gid == 0) return $content;
  
  $content = '<div class="block-menu"><ul class="menu clearfix">';
  $content .= '<li class="first leaf menu-depth-1">' . l('View',  'groups/workspace/questionnaire/' . $gid . '/' . '34974') . '</li>';
  $content.= '</ul></div>';
  return $content;
}
