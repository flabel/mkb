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
 
// dpm($rows);

foreach($rows as $row_count => $row) {
  $nid = $row['nothing'];
  $delete = true;
  // Organisation children
  $query = db_select('node', 'n');
  $query->leftJoin('field_data_field_parent_organisation', 'p', 'p.entity_id = n.nid');
  $query
    -> fields('n', array('title'))
    -> fields('n', array('nid'))
    -> condition('p.field_parent_organisation_target_id', $nid)
    ->orderBy('n.title')
    ;
  $result = $query->execute();
  $hits = $result->rowCount();
  if ($hits) $rows[$row_count]['nothing'] = l($hits,'organisation-children/' . $nid);
  else $rows[$row_count]['nothing'] = t('None');
  if ($hits) $delete = false;
  // Organisation user
  $query = db_select('users', 'u');
  $query->leftJoin('profile', 'p', 'p.uid = u.uid');
  $query->leftJoin('field_data_field_my_organisation', 'm', 'm.entity_id = p.pid');
  $query
    -> fields('u', array('name'))
    -> fields('u', array('uid'))
    -> condition('m.field_my_organisation_target_id', $nid)
    ->orderBy('u.name')
    ;
  $result = $query->execute();
  $hits = $result->rowCount();
  if ($hits) $rows[$row_count]['nothing_1'] = l($hits,'organisation-users/' . $nid);
  else $rows[$row_count]['nothing_1'] = t('None');
  if ($hits) $delete = false;
  // Delete field
  if ($delete) $rows[$row_count]['nothing_2'] = l('Delete','node/' . $nid . '/delete',array('query' => array('destination' => 'organisation-children/' . $row['nothing_2'])));
  else $rows[$row_count]['nothing_2'] = t('');
  
  //  dpm($GLOBALS);
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
