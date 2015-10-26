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

// Hide registration link when field_event_registration is empty and hide field_event_registration
//dpm($rows);
foreach ($rows as $row_count => $row) {
  if (!$row['field_event_registration'] || $row['field_event_registration'] == 'No') {
    $rows[$row_count]['nothing'] = '';
  }
  unset($rows[$row_count]['field_event_registration']);
}
unset($header['field_event_registration']);

// Hide past or future events
if (arg(1) == 'past') $show_past = TRUE;
else $show_past = FALSE;
 
$past_events_exist = FALSE;
foreach ($rows as $row_count => $row) {
  $time_ago = $row['field_event_dates_1'];
  $is_past = (strpos($time_ago,'week') || strpos($time_ago,'month') || strpos($time_ago,'year'));
  if ($is_past && !$show_past) {
    unset($rows[$row_count]);
	$past_events_exist = TRUE;
  }
  if (!$is_past && $show_past) {
    unset($rows[$row_count]);
  }
// Remove time ago column
unset($rows[$row_count]['field_event_dates_1']);
}

// Remove time ago column header
unset($header['field_event_dates_1']);

// Print page title and link to past/future
if ($past_events_exist) {
  print '<h1 id="page-title">Events</h1>';
  print l('Past events', 'project-calendar/past');
}

if ($show_past) {
  print '<h1 id="page-title">Past events</h1>';
  print l('Future events', 'project-calendar');
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
