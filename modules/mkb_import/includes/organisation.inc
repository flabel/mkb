<?php
class OrganisationMigration extends mkb_import_Basic_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t('Import organisation CSV-file');
    $columns = array(
      // "Source": ('Fieldname', 'Description')
      0 => array('csv_id', t('CSV id')),
      1 => array('title', t('Title')),
      2 => array('uid', t('Authored by (uid)')),
      3 => array('field_short_name', t('Short name')),
      4 => array('field_parent_organisation', t('Parent organisation')),
      5 => array('field_country', t('Country')),
      6 => array('field_url', t('URL')),
      7 => array('field_organisation_type', t('Organisation type')),
      8 => array('field_description', t('Description')),
      9 => array('field_contact_person', t('Contact person')),
      10 => array('field_email', t('Email')),
      11 => array('field_phone', t('Phone')),
      12 => array('field_street_name', t('Street name')),
      13 => array('field_house_number', t('House number')),
      14 => array('field_zip', t('ZIP')),
      15 => array('field_city', t('City')),
      16 => array('field_region', t('Region')),
      17 => array('field_exposed', t('Exposed')),
    );
    $this->source = new MigrateSourceCSV(
      DRUPAL_ROOT . '/' . drupal_get_path('module', 'mkb_import') . '/data_sources/Organisation/organisation.' . $arguments['language_prefix'] . '.csv',
      $columns,
      array(
        'header_rows' => 1,
        'embedded_newlines' => TRUE
      )
    );
    $this->destination = new MigrateDestinationNode('organisation');
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'csv_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    if ($arguments['language_prefix'] != 'en') {
      $this->addSoftDependencies(array('Organisation_en'));
    }
    // Mapped fields
    $this->addFieldMapping('title', 'title')
      ->defaultValue('');
    $this->addFieldMapping('language')
      ->defaultValue(str_replace('_', '-', $arguments['language_prefix']));
    $this->addFieldMapping('uid', 'uid')
      ->defaultValue(0)
      ->description(t('Authored by (uid)'));
    $this->addFieldMapping('field_short_name', 'field_short_name')
      ->defaultValue('')
      ->description(t('Short name'));
		$this->addFieldMapping('field_parent_organisation', 'field_parent_organisation')
      ->defaultValue(0)
      ->description(t('Parent organisation'));
		$this->addFieldMapping('field_country', 'field_country')
      ->defaultValue('')
      ->description(t('Country'));
		$this->addFieldMapping('field_url', 'field_url')
      ->defaultValue('')
      ->description(t('URL'));
		$this->addFieldMapping('field_organisation_type', 'field_organisation_type')
	  ->separator('#')
      ->defaultValue(0)
      ->description(t('Organisation type'));
		$this->addFieldMapping('field_description', 'field_description')
      ->defaultValue('')
      ->description(t('Description'));
		$this->addFieldMapping('field_contact_person', 'field_contact_person')
      ->defaultValue('')
      ->description(t('Contact person'));
		$this->addFieldMapping('field_email', 'field_email')
      ->defaultValue('')
      ->description(t('Email'));
		$this->addFieldMapping('field_phone', 'field_phone')
      ->defaultValue('')
      ->description(t('Phone'));
		$this->addFieldMapping('field_street_name', 'field_street_name')
      ->defaultValue('')
      ->description(t('Street name'));
		$this->addFieldMapping('field_house_number', 'field_house_number')
      ->defaultValue('')
      ->description(t('House number'));
		$this->addFieldMapping('field_zip', 'field_zip')
      ->defaultValue('')
      ->description(t('ZIP'));
		$this->addFieldMapping('field_city', 'field_city')
      ->defaultValue('')
      ->description(t('City'));
		$this->addFieldMapping('field_region', 'field_region')
      ->defaultValue('')
      ->description(t('Region'));
		$this->addFieldMapping('field_exposed', 'field_exposed')
      ->defaultValue(0)
      ->description(t('Exposed'));

    // tnid
    if ($arguments['language_prefix'] != 'en') {
      $this->addFieldMapping('tnid', 'csv_id')
        ->callbacks(array($this, 'gettnid'));
    }
  }
  // Return the english Organisation nid from which this Organisation is translated.
  protected function gettnid($value) {
    $value = db_select('migrate_map_organisation_en')
      ->fields('migrate_map_organisation_en', array('destid1'))
      ->condition('sourceid1', $value)
      ->execute()
      ->fetchField();
    return $value;
  }
  public function postImport() {
    parent::postImport();
    // Put the tnid for english content after it is created.
    if ($this->arguments['language_prefix'] == 'en') {
      $nid_pre_list = db_select('migrate_map_organisation_en')
        ->fields('migrate_map_organisation_en', array('destid1'))
        ->execute()
        ->fetchAllAssoc('destid1');
      $nid_list = array_keys($nid_pre_list);
      $node_list = node_load_multiple($nid_list);
      foreach ($node_list as $node) {
        $node->tnid = $node->nid;
        node_save($node);
      }
    }
  }
}