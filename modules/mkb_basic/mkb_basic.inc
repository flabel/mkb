<?php

/**
 * @file
 * Inc for the mkb_basic module.
 */
/**
 * Implements hook_views_api().
 */
function mkb_basic_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_basic'),
    'template path' => drupal_get_path('module', 'mkb_basic') . '/theme',
  );
}

function mkb_display_menu($this_mkb_meny) {
  $mkb_path = current_path();
  if (!isset($mkb_path)) return false;
  if (substr_count($mkb_path,'admin') > 0) return false;
  if (substr_count($mkb_path,'#') > 0) return false;
  if (!isset($_SESSION["mkb_display_meny"])) {
    $_SESSION["mkb_display_meny"] = 'front';
  }
  if (!isset($GLOBALS['mkb_current_meny'])) {
    $mkb_meny = mkb_basic_meny();
    if (isset($mkb_meny[$mkb_path])) {
	  /*if ($mkb_meny[$mkb_path] != 'menu-match-making')*/ {
	    $_SESSION["mkb_display_meny"] = $mkb_meny[$mkb_path];
	  }
    }
	$GLOBALS['mkb_current_meny'] = $_SESSION["mkb_display_meny"];
    if (drupal_is_front_page()) $GLOBALS['mkb_current_meny'] = 'front'; // Front page
  }
  if (drupal_is_front_page()) {
    $_SESSION["mkb_display_meny"] = 'front';  // Front page has no menu, this keeps no menu for pages chosen from the front page
  }
  if ($this_mkb_meny == $GLOBALS['mkb_current_meny']) return TRUE;
  else return FALSE;
}

// Create an array with key=path and value=menu machine name for all paths having a menu 
// Only once per new page by setting $GLOBALS['mkb_current_meny']
function mkb_basic_meny() {
  $mkb_query = db_select('menu_links', 'm');
  $mkb_query  -> fields('m', array('menu_name', 'link_path'));
  $mkb_result = $mkb_query->execute();
  $mkb_meny = array();
  foreach($mkb_result as $row) {
    if($row -> menu_name != 'management' && $row -> menu_name != 'main-menu') $mkb_meny[$row -> link_path] = $row -> menu_name;
  }
  return $mkb_meny;
}

