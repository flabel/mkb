<?php

/**
 * @file
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $caption: The caption for this table. May be empty.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */

print '<h2>Edit call themes and topics</h2>';

$i=0;
$call_id_index=0;
$url_comp = explode('/', request_uri());
foreach($url_comp as $comp) {
  if ($comp == 'call-topics-setup') $call_id_index = $i;
  $i++;
}
if (!isset($url_comp[$call_id_index+1])) {
  print 'Please select a call:';
  $call_ids = array();
  foreach($rows as $row) {
    if(!in_array($row['field_call_id'], $call_ids)) {
      print '<br>' . l($row['field_call_id_1'],'call-topics-setup/' . $row['field_call_id']);
      $call_ids[] = $row['field_call_id'];
    }
  }
}

else {
  drupal_add_js('misc/form.js');
  drupal_add_js('misc/collapse.js');

  print '<h3>' . $rows[0]['field_call_id_1'] . '</h3>';

  $rows_copy = $rows;

  foreach($rows as $row) {
    if ($row['field_topic_level'] == 1) {
      $pid = $row['nid'];
      $call_id = $row['field_call_id'];
      $topic = array(
        '#attributes' => array(
          'class' => array('collapsible', 'collapsed'),
        ),
        '#title' => '<strong>' . $row['title'] . '</strong>' . ' (' . $row['field_topic_weight'] . ')',
	    '#description' => l('Edit','node/' . $row['nid'] . '/edit'),
        '#children' => $row['field_topic_description'],
      );
      print theme('fieldset', array('element' => $topic));

      $weight = 10;
	  foreach($rows_copy as $row_copy) {
	    if ($row_copy['field_topic_parent'] == $pid) {
          $topic = array(
            '#attributes' => array(
              'class' => array('collapsible', 'collapsed'),
            ),
            '#title' => $row_copy['title'] . ' (' . $row_copy['field_topic_weight'] . ')',
	        '#description' => l('Edit','node/' . $row_copy['nid'] . '/edit'),
            '#children' => $row_copy['field_topic_description'],
          );
          print theme('fieldset', array('element' => $topic));
	      $weight = $row_copy['field_topic_weight'] + 10;
	    }
  	  }
	  print '<br>';
  	  print l('Add new topic', 'node/add/call-topic/' . $call_id . '/' . $pid . '/2/' . $weight);
      $weight = $row['field_topic_weight'] + 10;
    }
  }
  print '<br><br>';
  print l('ADD NEW THEME', 'node/add/call-topic/' . $call_id . '/0/1/' . $weight);
  print '<br><br>';
  print 'The order of themes and topics is determined by the weights shown in parenthesis. The order can be modfied by Edit and changing the weights.';
}
?>


<!--
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php foreach ($header as $field => $label): ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?>>
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php foreach ($row as $field => $content): ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
            <?php print $content; ?>
          </td>
        <?php endforeach; ?>
      </tr>
    <?php endforeach; ?>
  </tbody>
</table>
-->