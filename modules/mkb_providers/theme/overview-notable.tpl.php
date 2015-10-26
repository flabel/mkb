<!--
<h2>Provider overview data</h2>
<p>This page links to three other pages:
<ul>
<li><b>Profile</b> with basic data about the ICT provider, e.g. agricultural sector</li>
<li><b>Compatibility</b> with questions to the ICT provider, e.g. importance of compatibility</li>
<li><b>Share cases</b> with data about where and how the ICT provider is using data sharing</li>
</ul>
</p>
-->
<?php
// dpm($variables);
$base_url = $GLOBALS['base_url'];
// If the organisation is not a provider yet. Redirect to provider-organisation so the user can add the organisation.
if(!$provider){
  drupal_set_message('The selected organisation is not talking part in the survey. Please add the organisation to the list by clicking "Add" under survey.');
  drupal_goto($base_url . '/provider-organisation');
}
$provider_id = $variables['provider'] -> vid;

// Print page header
print '<div id="provider-page">ICT provider survey 2014</div>';
// Print title: ICT provider survey for "provider name"
print '<h1 id="page-title">ICT provider survey for <i>' . $variables['provider'] -> title . '</i></h1>';
// Print mail link

// Print page information
print 'The provider survey is divided in three separate parts: (1) questions about the provider profile, (2) a compatibility survey and (3) questions about data sharing.</br>';
// Print Profile
print '<h3 id="provider-header">Provider profile survey</h3>';
if(!empty($variables['profile'])){
//  print drupal_render($variables['profile']);
  // sc fields are used for replacing title with description
  $sc_fields = field_info_instances('provider', 'provider_profile');

  $element = $variables['profile']['provider'];
  foreach ($element as $id => $data) {
    hide($data['field_provider_id']);
    print l('Edit', $base_url . '/provider/provider_profile/' . $id . '/edit');
    // Replace title with description
    foreach (element_children($data) as $child){
      if($child !== 'field_provider_id'){
        $data[$child]['#title'] = $sc_fields[$child]['description'];
      }
    }
    print drupal_render_children($data);
  }
}
else{
  print 'Basic questions about the ICT provider. (e.g.: In which agricultural sector is the provider active?)</br>';
  print l('Fill in provider profile', $base_url . '/admin/structure/entity-type/provider/provider_profile/add/' . $provider_id . '/');
  print '</br>';
}

// Print Compatibility
print '<h3  id="provider-header">Compatibility survey</h3>';
if(!empty($variables['compatibility'])){
  // pp fields are used for replacing title with description
  $pp_fields = field_info_instances('provider', 'provider_compatibility');

  $element = $variables['compatibility']['provider'];
  foreach ($element as $id => $data) {
    hide($data['field_provider_id']);
    print l('Edit', $base_url . '/provider/provider_compatibility/' . $id . '/edit');
    // Replace title with description
    foreach (element_children($data) as $child){
      if($child !== 'field_provider_id'){
        $data[$child]['#title'] = $pp_fields[$child]['description'];
      }
    }
    print drupal_render_children($data);
  }
}
else{
  print 'Survey questions about compatibility and the use of standards for creating compatible products.</br>';
  print l('Fill in compatibility survey', $base_url . '/admin/structure/entity-type/provider/provider_compatibility/add/' . $provider_id . '/');
  print '</br>';
}

// Build data for Share case
$share_case_header = array('ID');
$share_case_rows = array();
$fields = field_info_instances('provider', 'provider_share_case');
// Sort fields by display weight
usort($fields, 'mkb_providers_sort');


// Build header
foreach ($fields as $field_name => $field){
  if($field_name !== 'field_provider_id'){
    $share_case_header[] = $field['label'];
  }
}

// Build rows
foreach ($variables['share_case'] as $id => $share_case){
  $row = array($id);
  foreach ($fields as $field_name => $field){
    // Exclude provider ID
    if($field_name !== 'field_provider_id'){
        // This some other ways to work with the entity. Note for Direction you will get the value 0 instead of export
        // if you use one of these alternatives.
//       $wrapper = entity_metadata_wrapper('provider', $share_case);
//       $row[] = $wrapper->$field_name->value();
//       $row[] = render(field_view_field('provider', $share_case, $field_name));
      $items = field_get_items('provider', $share_case, $field_name);
      $row[] = render(field_view_value('provider', $share_case, $field_name, $items[0]));
    }
  }
  $share_case_rows[] = $row;
}
// dpm($share_case_header);
// dpm($share_case_rows);
// dpm($variables['share_case']);

// Build table array
$table = array(
    'header' => $share_case_header,
    'rows' => $share_case_rows,
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '',
        ),
    'sticky' => TRUE,
    'empty' => 'No share cases for this provider.',
    'colgroups' => array(),
    'caption' => '',
);

// Print Share case content
print '<h3  id="provider-header">Share cases survey</h3>';
print 'Questions about concrete cases of data sharing, carried out or planned by the ICT provider. This part can be filled in multiple times, one time for each concrete case of data sharing.</br>';
print l('Fill in share cases survey', $base_url . '/admin/structure/entity-type/provider/provider_share_case/add/' . $provider_id . '/');
print '</br></br>';

print theme_table($table);
?>