<?php
print '<h1>' . t('ICT provider survey responses') . '</h1>';
//dpm($variables);

$responses = $variables['responses'];

print 'Filter: ' . $variables['filter'] . ', ' . count($responses) . ' hits. ';
print l('Back to statistics', 'survey_stats/profile');

// Table header
$header = array('Organisation', 'Country', 'Profile', 'Contact');

// Table rows
$rows = array();
foreach($responses as $response) {
  if (!empty($response['parent'])) {
    $organisation = l($response['parent'] -> title, 'node/' . $response['parent'] -> nid);
	$country = $response['parent'] -> field_country['und'][0]['iso2'];
  }
  else {
    $organisation = null;
	$country = null;
  }
  if (!empty($response['user'])) $contact = l($response['user'] -> realname, 'user-profile/' . $response['user'] -> uid);
  else $contact = null;
  if (!empty($response['profile'])) $profile = l('View profile', 'provider/provider_profile/' . $response['profile'] -> id);
  else $profile = null;
  $row = array($organisation, $country, $profile, $contact); 
  $rows[] = $row;
}
//dpm($rows);

// Render and print table
$table = array(
  'header' => $header,
  'rows' => $rows,
  'attributes' => array(
    'class' => array('provider-survey-table'),
  ),
  'sticky' => FALSE,
  'empty' => 'Nothing',
  'colgroups' => array(),
    'caption' => '',
  );
print theme_table($table);


