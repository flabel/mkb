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



 
// Do not show dates if declined
foreach ($rows as $row_count => $row) {
  if ($row['field_decline']) {
    $rows[$row_count]['field_arrival'] = '';
    $rows[$row_count]['field_departure'] = '';
  }
}

// Print version (/print in url) without declined registrations and without edit, declined and remark fields
// Nodate version (/print/nodate in url) also without arrival and departure fields 

$print = arg(2);
$nodate = arg(3);
if (isset($print) && $print == 'print') {
  unset($header['nothing']);
  unset($header['field_decline']);
  unset($header['field_remark']);
  if (isset($nodate) && $nodate == 'nodate') {
    unset($header['field_arrival']);
    unset($header['field_departure']);
  }
  foreach ($rows as $row_count => $row) {
    unset($rows[$row_count]['nothing']);
    unset($rows[$row_count]['field_remark']);
    if ($row['field_decline']) {
      unset($rows[$row_count]);
	  }
    else {
      unset($rows[$row_count]['field_decline']);
	}
    if (isset($nodate) && $nodate == 'nodate') {
      unset($rows[$row_count]['field_arrival']);
      unset($rows[$row_count]['field_departure']);
    }
  }
}

?>
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
