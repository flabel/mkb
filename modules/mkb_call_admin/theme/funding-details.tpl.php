<?php
//dpm($variables);

print '<h1>' . $variables['funder'] -> title . '</h1>';
print '<h2>Funding details</h2>';
print '<p><b>Call :</b> ' . $variables['call'] -> title . '</p>';
$country_specific = $variables['funder'] -> field_country_specific['und'][0]['value'];
if ($country_specific) {
  print '<p><b>Country specific:</b> Funding is restricted to organisations from ' . $variables['agency_country'] . '</p>';
}
elseif ($variables['funder'] -> nid = 13796) {
  print '<p><b>Country specific:</b> Funding is available for project coordinators from EU countries and FP7 associated countries. Funding is not available for project partners.</p>';
}
else {
  print '<p><b>Country specific:</b> Funding is not restricted to a single country</p>';
}

print '<p><b>Funding:</b> &euro;' . $variables['funder'] -> field_funding['und'][0]['value'] . ',000</p>';
print '<p><b>Conditions short:</b> ' . $variables['funder'] -> field_conditions_short['und'][0]['value'] . '</p>';
print '<p><b>Conditions full:</b>' . $variables['funder'] -> field_conditions_full['und'][0]['value'] . '</p>';
if(!empty($variables['condition_files'])){
  print theme("item_list", array(
  	 'items' => $variables['condition_files'],
  	 'type' => 'ul',
  	 'title' => 'Conditions pdf',
  ));
}

print '<p><b>Contact person(s):</b> ';
$contacts = $variables['funder'] -> field_contact_persons['und'];
foreach ($contacts as $contact) {
  $uid = $contact['target_id'];
  $this_user = user_load($uid);
  $name = $this_user -> field_first_name['und'][0]['safe_value'] . ' ' . $this_user -> field_last_name['und'][0]['safe_value'];
  print '<br>' . l($name,'user-profile/' . $uid);
}
print '</p>';

print '<h2>Funding schemes</h2>';
print '<p>' . t('Funding schemes define the funding conditions for different types of applicants.') . '</p>';
foreach($variables['schemes'] as $scheme) {
  print '<h3>' . l($scheme -> title, 'node/' . $scheme -> nid) . '</h3>';
//  print '<p>' . $scheme -> field_fun_schc['und'][0]['value'] . '</p>';
}

?>





