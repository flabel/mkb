<?php
 dpm($variables);
$base_url = $GLOBALS['base_url'];
$provider_id = $variables['provider'] -> vid;

// Print page header
print '<div id="provider-page">ICT provider survey 2014</div>';
// Print title: ICT provider survey for "provider name"
print '<h1 id="page-title">ICT provider survey for <i>' . $variables['provider'] -> title . '</i></h1>';
// Print mail link

// Print Profile
print '<h3 id="provider-header">Provider profile survey</h3>';
if(!empty($variables['profile'])){
  // fields are used for replacing title with description
  $fields = field_info_instances('provider', 'provider_profile');
// Sort fields by display weight (sort function in bottom of module)
  usort($fields, 'mkb_providers_sort');
dpm($fields);

  $entity_id = key($variables['profile']['provider']);
  print l('Edit', $base_url . '/provider/provider_profile/' . $entity_id . '/edit');
//  print '<table>';

// Print description and response in a table
  foreach ($fields as $field){
//	dpm($field);
    $field_name = $field['field_name'];
    if($field_name !== 'field_provider_id' && isset($variables['profile']['provider'][$entity_id][$field_name])){
	  print '<p><strong>' . $field['description'] . ' (' . $field_name  . ')' .'</strong>';
	  $values = $variables['profile']['provider'][$entity_id][$field_name];
//	  dpm($values);
	  foreach ($values as $key => $value) {
//	  dpm($value);
	    if (is_numeric($key)) {
		  print '&nbsp; ' . $value['#markup'] . '<br>';
		}
      print '</p>';
      }
    }
  }
}
else{
  print 'No data available';
}
// dpm($variables);

?>