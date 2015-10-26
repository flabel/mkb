<?php

/**
 * @file
 * Inc for the mkb module.
 */

/**
 * Implements hook_views_api().
 */
function mkb_org_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_org'),
    'template path' => drupal_get_path('module', 'mkb_org') . '/theme',
  );
}

/**
 * Builds and returns the options for parent organisation form.
 */
function mkb_org_options($this_nid) {
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_parent_organisation', 'p', 'n.nid = p.entity_id');
  $query->leftJoin('field_data_field_org_path', 'o', 'n.nid = o.entity_id');
  $query->leftJoin('field_data_field_country', 'c', 'n.nid = c.entity_id');
  $query
  ->fields('n', array('title', 'nid'))
  ->fields('p', array('field_parent_organisation_target_id'))
  ->fields('o', array('field_org_path_value'))
  ->fields('c', array('field_country_iso2'))
  ->condition('n.type', 'organisation')
  ->condition('c.bundle', 'organisation')
  ->orderBy('o.field_org_path_value')
  ->addTag('node_access');
  $result = $query->execute();

  $data = $result->fetchAll();
  function cmp($a, $b)
  {
      return strcmp($a->field_org_path_value, $b->field_org_path_value);
  }

  usort($data, "cmp");


// Read current user's country
  $query = db_select('field_data_field_country', 'o');
  $query->leftJoin('countries_country', 'c', 'c.iso2 = o.field_country_iso2');
  $query
    -> fields('o', array('field_country_iso2'))
    -> fields('c', array('name'))
    -> condition('o.bundle', 'user')
    -> condition('o.entity_id', $GLOBALS['user']->uid)
    ;
  $result = $query->execute()->fetchAll();
  if ($result) {
    $user_country = $result[0] -> field_country_iso2;
    $user_country_name = $result[0] -> name;
  }
  else $user_country = false;
  
// Read countries used in organisations
  $query = db_select('field_data_field_country', 'o');
  $query->leftJoin('countries_country', 'c', 'c.iso2 = o.field_country_iso2');
  $query
    -> fields('o', array('field_country_iso2'))
    -> fields('c', array('name'))
    -> condition('o.bundle', 'organisation')
    -> distinct()
    ->orderBy('c.name')
    ;
  $result = $query->execute();

  $options = array("_none" => "- None -");

// Create options for user's country
   country_organisations($user_country,$user_country_name,$data,$options,$this_nid);

   // Create options for other countries
  foreach($result as $row) {
    if ($row -> field_country_iso2 != $user_country) {
      $this_country = $row -> field_country_iso2;
      $this_country_name = $row -> name;
      $options[$this_country_name] = array();
      country_organisations($this_country,$this_country_name,$data,$options,$this_nid);
	}
  }
  return $options;
}

// Get organisations from a country	
function country_organisations($country,$country_name,$data,&$options,$this_nid) {
	$parent_array = array();
    foreach($data as $row) {
	  if ($row -> field_country_iso2 == $country) {
        $nid = $row -> nid;                                        // This organisation's id
        $pid = $row -> field_parent_organisation_target_id;        // This organisation's parent_id
        if (isset($pid)) $parent_array[$nid] = $pid;               // Parent_id in array
        else $parent_array[$nid] = null;                           // or null
        $name[$nid] = $row->title;
       }
	 }
    while (list($key,$val) = each($parent_array)) {
      $n_parents = mkb_org_count_parents(0, $key, $parent_array, $this_nid);
      $level_name = '';
      for ($x=0; $x<$n_parents; $x++) $level_name .= '- ';
      $level_name .= $name[$key];
      if ($n_parents>=0) $options[$country_name][strval($key)] = $level_name;        // Man kan ikke være sin egen far
    }
}

function mkb_org_count_parents($n_parents, $nid, $parent_array, $this_nid) {
  if ($nid == $this_nid) $n_parents = -100;
  if (isset($parent_array[$nid])) {
    $n_parents += mkb_org_count_parents($n_parents, $parent_array[$nid], $parent_array, $this_nid);
    $n_parents ++;
  }
  return $n_parents;
}

function mkb_org_name($pid, $name){
  if($name == 'country'){
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_country', 'o', 'n.nid = o.entity_id');
    $query ->addField('o', 'field_country_iso2', 'org_value');
  }
  else{
    $query = db_select('node', 'n');
    $query->leftJoin('field_data_field_' . $name, 'o', 'n.nid = o.entity_id');
    $query ->addField('o', 'field_' . $name . '_value', 'org_value');
  }
  $query
  ->condition('n.nid', $pid)
  ->addTag('node_access');
  $result = $query->execute();

  $parent_org_value = null;
  foreach($result as $row) {
    $parent_org_value = $row -> org_value;
  }
  return $parent_org_value;
}


