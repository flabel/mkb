<?php
/**
 * @file
 * mkb_call_admin.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mkb_call_admin_taxonomy_default_vocabularies() {
  return array(
    'funding_mode' => array(
      'name' => 'Funding mode',
      'machine_name' => 'funding_mode',
      'description' => 'Funding mode',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
