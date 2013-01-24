<?php
/**
 * @file
 * ical_feed_importer.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function ical_feed_importer_taxonomy_default_vocabularies() {
  return array(
    'event_categorisation' => array(
      'name' => 'Event Categorisation',
      'machine_name' => 'event_categorisation',
      'description' => 'Event Categorisation',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
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
