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
    <?php $old_partner_number = "0";?>
    <?php $empty_user = true;?>
    <?php $line_count = 0;?>
    <?php foreach ($rows as $row_count => $row): ?>
    <?php if($row["field_partner_2_number"] != $old_partner_number){?>
        <?php if($old_partner_number != "0"){?>
          </td>
        </tr>
        <?php $empty_user = true;?>
        <?php } ?>
        <tr <?php if ($row_classes[$line_count]) { print 'class="' . implode(' ', $row_classes[$line_count]) .'"';  } ?>>
          <td><?php print $row["field_partner_2_number"];?></td>
          <td><?php print $row["field_short_name"];?></td>
          <td><?php print $row["field_org_name"];?></td>
          <td><?php print $row["field_country"];?></td>
		  <?php if (isset($row["field_organisation_type"])) {?>
			<td><?php print $row["field_organisation_type"];?></td>
		  <?php } ?>
          <td><?php if(isset($row["realname"]) && substr_count($row["rid"], "project member")){?>
                <?php print $row["realname"];?>
                <?php $empty_user = false;?>
              <?php } ?>

          <?php $old_partner_number = $row["field_partner_2_number"]; ?>
          <?php $line_count++; ?>
     <?php }else{?>
       <?php if(isset($row["rid"]) && substr_count($row["rid"], "project member")){?>
         <?php if(!$empty_user){?>
           <br/>
         <?php } ?>
         <?php $empty_user = false;?>
         <?php print $row["realname"];?>
     <?php }} ?>
    <?php endforeach; ?>
  </tbody>
</table>
