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
<?php if(in_array('project member',$GLOBALS['user'] -> roles)): ?>
  <p>The Edit link and this line is only shown to project partners</p>
<?php endif; ?>  
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
    <?php $old_participant_number = "0";?>
    <?php $empty_user = true;?>
    <?php $line_count = 0;?>
    <?php foreach ($rows as $row_count => $row): ?>
    <?php if($row["field_participant_number"] != $old_participant_number){?>
        <?php if($old_participant_number != "0"): ?>
          </td>
          </tr>
          <?php $empty_user = true;?>
        <?php endif; ?>
        <tr <?php if ($row_classes[$line_count]) { print 'class="' . implode(' ', $row_classes[$line_count]) .'"';  } ?>>
          <?php if(in_array('project member',$GLOBALS['user'] -> roles)): ?>
            <td><?php print $row["nothing"];?></td>
          <?php endif; ?>  
          <td><?php print $row["field_participant_number"];?></td>
          <td><?php print $row["title"];?></td>
          <td><?php print $row["field_org_name"];?></td>
          <td><?php print $row["field_country"];?></td>
		  <?php if (isset($row["field_participant_role"])) {?>
			<td><?php print $row["field_participant_role"];?></td>
		  <?php } ?>
          <td><?php if(isset($row["field_participant_contact"])) {?>
                <?php print $row["field_participant_contact"];?>
                <?php $empty_user = false;?>
              <?php } ?>

          <?php $old_participant_number = $row["field_participant_number"]; ?>
          <?php $line_count++; ?>
     <?php }else{?>
          <?php if(isset($row["field_participant_contact"])) {?>
         <?php if(!$empty_user){?>
           <br/>
         <?php } ?>
         <?php $empty_user = false;?>
         <?php print $row["field_participant_contact"];?>
     <?php }} ?>
    <?php endforeach; ?>
  </td></tr>
  </tbody>
</table>
