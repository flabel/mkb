<?php
/**
* Implements hook_migrate_api().
*/
function mkb_import_migrate_api() {
//   module_load_include('inc', 'mkb_import', 'includes/basic');
  module_load_include('inc', 'mkb_import', 'includes/organisation');
  // Prepare migration per language
  $migrations = array();
  $language_list = language_list();
  foreach ($language_list as $language_prefix => $language) {
    // Need to remove '-'
    $language_prefix = str_replace('-', '_', $language_prefix);
    $migrations['Organisation_' . $language_prefix] = array(
      'class_name' => 'OrganisationMigration',
      'group_name' => 'OrganisationMigrate',
      'language_prefix' => $language_prefix,
    );
  }
  $api = array(
    'api' => 2,
    'groups' => array(
      'OrganisationMigrate' => array(
        'title' => t('Organisation Migrations'),
      ),
    ),
    'migrations' => $migrations,
  );
  return $api;
}