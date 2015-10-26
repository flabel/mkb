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

// dpm($header);
// dpm($rows);

// replace country name with "Any" if not country specific 
// remove field_country_specific
foreach ($rows as $row_count => $row) {
  if ($row['field_country_specific']=='No') $rows[$row_count]['field_country'] = 'Any';
  unset($rows[$row_count]['field_country_specific']);
}
unset($header['field_country_specific']);


 // Print theme titles at top and replace titles with T1, T2, .. in table header.
$funding_total = 0;
$theme_funding_total = array();
for ($i=0; $i<8; $i++) {
	if (isset($header[$i])) {
		if ($i==0) print '<b>Themes:</b>';
		$t=$i+1;
		print '<br>';
		print '<b>';
		print 'T' . $t . ' ';
		if (substr($header[$i],0,1) == $t) $header[$i] = substr($header[$i],2);
		print $header[$i];
		print '</b>';
		$header[$i] = 'T' . $t;
        $theme_funding_total[$i] = 0;
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
          <th <?php if (isset($header_classes[$field])) { print 'class="'. $header_classes[$field] . '" '; } ?>
          <?php if ($field=='field_funding' or ($field>1 and $field<9)) print ' style="text-align:right;"'; ?>
		  >
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
		<?php
          if ($field=='field_funding' or ($field>'0' and $field<'9')) print '<td style="text-align:right;">';
		  else print '<td>';
		?>
        <?php print $content; ?>
        </td>
      <?php endforeach; ?>
      </tr>
	  <?php $funding_total += ($row['field_funding'] + 0); ?>
	  <?php for ($i=0; $i<8; $i++) if (isset($row[$i])) $theme_funding_total[$i] += $row[$i]; ?>
    <?php endforeach; ?>
  </tbody>
  <tfoot>
    <tr><th>Total</th><th>&nbsp;</th>
	<th style="text-align:right;"> 
	<?php print $funding_total; ?>
	<?php for ($i=0; $i<8; $i++) if (isset($theme_funding_total[$i])) {?>
	  <th style="text-align:right;"> <?php print $theme_funding_total[$i]; ?> </th>
    <?php } ?>
    </th><th>&nbsp;</th></tr>
  </tfoot>
</table>