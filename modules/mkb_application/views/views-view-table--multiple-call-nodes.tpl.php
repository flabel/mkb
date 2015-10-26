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
 
//dpm($rows);

print '<h3>Application documents are checked for being unique per Group and Author</h3>'; 
print '<h3>Group id - Node type - Node ids for same group and author</h3>'; 

$lag_gid = 0;
foreach($rows as $group) {
  if ($lag_gid != $group['gid']) {
    $lag_gid = $group['gid'];
    $group_nodes = mkb_application_get_group_user_and_roles($group['gid']);
    $multi_nodes = FALSE;
    foreach ($group_nodes['rows'] AS $node) {
      if ($node->entity_type == 'node') {
	    if (isset($count[$node->author_uid][$node->type])) {
		  print '<p>';
		  print $group['gid'];
		  print ' ' . $node->type;
		  print ' ' . $node->nid;
		  print ' ' . $count[$node->author_uid][$node->type];
		  print '</p>';
 		  $multi_nodes = TRUE;
		}
        $count[$node->author_uid][$node->type] = $node->nid;
      }	  
    }
    // if ($multi_nodes) dpm($group['gid'] . ' - ' . $node->nid);
    // if ($multi_nodes) dpm($group_nodes);
    // if ($multi_nodes) dpm($count);
    unset($count);
  }
}

/*
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
<?php */
