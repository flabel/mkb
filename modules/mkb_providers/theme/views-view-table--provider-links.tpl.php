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

// Empty all fields except user name when there are multiple rows for same organisation
// Replace organisation name with - for repeats of country
// Replace country name with - for repeats of country
// Remove organisation nid
// Empty text in user field when there is no user

// See about the invitation mail in function mkb_providers_preprocess_views_view_table() in mkb_providers.module

//dpm($rows);

unset($header['nid_1']); // Hide node id
unset($header['uuid']);  // Hide generated link
$nid = 0;
//$country = '';
foreach ($rows as $row_count => $row) {
// Get provider-organisation id
  $nid = $row['nid_1']; // Id of provider's organisation
  if ($nid) $pid = mkb_providers_get_parent_organisation_id($nid);
  else $pid = NULL;
	$field = '';
    if ($pid) {
      $result = get_survey_response_types($pid);
	  if (!empty($result)) {
		foreach($result as $response) {
		  if ($field) $field.= '<br>';
		  $field.= substr($response -> bundle,9);
		}
	  $rows[$row_count]['views_bulk_operations'] = ''; // No mail if survey response exist
      }			
    }
	$rows[$row_count]['nothing'] = $field;

  if (empty($row['field_email'])) $rows[$row_count]['views_bulk_operations'] = ''; // No select if no email address
  unset($rows[$row_count]['nid_1']); // Hide node id   
  unset($rows[$row_count]['uuid']);  // Hide generated link   
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
