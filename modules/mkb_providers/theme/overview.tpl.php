<?php
// dpm($variables);
$base_url = $GLOBALS['base_url'];
// If the organisation is not a provider yet. Redirect to provider-organisation so the user can add the organisation.
if(!$provider){
  drupal_set_message('The selected organisation is not talking part in the survey. Please add the organisation to the list by clicking "Add" under survey.');
  drupal_goto($base_url . '/provider-organisation');
}
$provider_id = $variables['provider'] -> nid;

// Print page header
print '<div id="provider-page">ICT provider survey 2014</div>';
// Print title: ICT provider survey for "provider name"
print '<h1 id="page-title">' . t('ICT provider survey for ') . '<i>' . $variables['provider'] -> title . '</i></h1>';
// Print mail link

// Print page information
print t('The provider survey is divided in two separate parts: (1) questions about the provider profile, and (2) a compatibility survey.');

// Print Profile
print '<h3 id="provider-header">' . t('Provider profile survey') . '</h3>';
print '<p>';
print t('Basic questions about the ICT provider. (e.g.: In which agricultural sector is the provider active?)');
print '</p>';
print '<p>';
print t('This part of the survey is shown to visitors and is used in searching (unless <em>Expose my data</em> is disabled in the account settings)');
print '</p>';
if(!empty($variables['profile'])){
  $entity_id = key($variables['profile']['provider']);
  print l('View', $base_url . '/provider/provider_profile/' . $entity_id);
  print '&nbsp;&nbsp;&nbsp;';
  print l('Edit', $base_url . '/provider/provider_profile/' . $entity_id . '/edit');
  print '&nbsp;&nbsp;&nbsp;';
  print l('Delete', $base_url . '/provider/provider_profile/' . $entity_id . '/delete', array('query' => array('destination' => 'provider/overview/' . $provider_id)));
}
else{
  print l(t('Fill in provider profile'), $base_url . '/admin/structure/entity-type/provider/provider_profile/add/' . $provider_id . '/');
  print '</br>';
}

// Print Compatibility
print '<h3  id="provider-header">' . t('Compatibility survey') . '</h3>';
print '<p>';
print t('Survey questions about compatibility and the use of standards for creating compatible products.');
print '</p>';
print '<p>';
print t('This part of the survey is only used for anonymously statistics and is not shown to visitors.');
print '</p>';
if(!empty($variables['compatibility'])){
  $entity_id = key($variables['compatibility']['provider']);
  print l('View', $base_url . '/provider/provider_compatibility/' . $entity_id);
  print '&nbsp;&nbsp;&nbsp;';
  print l('Edit', $base_url . '/provider/provider_compatibility/' . $entity_id . '/edit');
  print '&nbsp;&nbsp;&nbsp;';
  print l('Delete', $base_url . '/provider/provider_compatibility/' . $entity_id . '/delete', array('query' => array('destination' => 'provider/overview/' . $provider_id)));
}
else{
  print l(t('Fill in compatibility survey'), $base_url . '/admin/structure/entity-type/provider/provider_compatibility/add/' . $provider_id . '/');
  print '</br>';
}

if(!empty($variables['profile']) && !empty($variables['compatibility'])){
  print '<h3>' . t('Thank you for participating') . '</h3>';
  }
?>
