<?php
/**
 * @file
 * mkb_eval.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function mkb_eval_taxonomy_default_vocabularies() {
  return array(
    'evaluation_type' => array(
      'name' => 'Evaluation type',
      'machine_name' => 'evaluation_type',
      'description' => 'Set evaluation type in Evaluation conf.',
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
