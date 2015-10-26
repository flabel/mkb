<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

//dpm($rows);

foreach ($rows as $row_count => $row) {
//  $row = str_replace('<p', '<div', $row);
//  $row = str_replace('</p', '</div', $row);
  $footer_start = stripos($row, '<footer',0);
  $footer_end = stripos($row, '</footer>');
  if ($footer_start) $row = substr($row,0,$footer_start-1) . substr($row,$footer_end+9);
  $figure_start = stripos($row, '<figure',0);
  $figure_end = stripos($row, '</figure>');
  if ($figure_start) $row = substr($row,0,$figure_start-1) . substr($row,$figure_end+9);
  $contextual_start = stripos($row, '<div class="contextual-links-wrapper">');
  if ($contextual_start) $row = substr($row,0,$contextual_start-1) . '</article>';
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
