<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

//dpm($rows);

foreach ($rows as $row_count => $row) {
  $row = str_replace('<p', '<div', $row);
  $row = str_replace('</p', '</div', $row);
  $footer_start = stripos($row, '<footer',0);
  $footer_end = stripos($row, '</footer>');
  $row = substr($row,0,$footer_start-1) . substr($row,$footer_end+11);
  $rows[$row_count] = $row;
}

//dpm($rows);


?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>
