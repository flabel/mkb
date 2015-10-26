<?php
// Build header
$header = array();
$i = 0;
foreach ($variables['header'] as $field){
  $header[$i] = array(
      'data' => $field,
      'class' => 'eval_status_header',
      );
  $i++;
}

// Build rows
$arr_rows = array();
$i = 0;
foreach ($variables['content'] as $gid => $row){
  // Create each row
  $row_data = array();
  $eval_link = '/eval/group/' . $row['gid'];
  $j = 0;
  foreach ($row as $field){

    // Create each field
    $field_class = 'eval_status_td';
    if($field == 'Nothing'){
      $field_data = '<div class="status_nothing" onclick="document.location=' . "'" . $eval_link . "'" . ';" title="Click to see all evaluations of ' . $row['acronym'] . '">&nbsp;</div>';
    }
    elseif($field == 'Pending'){
      $field_data = '<div class="status_pending" onclick="document.location=' . "'" . $eval_link . "'" . ';" title="Click to see all evaluations of ' . $row['acronym'] . '">&nbsp;</div>';
    }
    elseif($field == 'Approved'){
      $field_data = '<div class="status_approved" onclick="document.location=' . "'" . $eval_link . "'" . ';" title="Click to see all evaluations of ' . $row['acronym'] . '">&nbsp;</div>';
    }
    elseif($field == 'Approved with conditions'){
      $field_data = '<div class="status_approved_with_conditions" onclick="document.location=' . "'" . $eval_link . "'" . ';" title="Click to see all evaluations of ' . $row['acronym'] . '">&nbsp;</div>';
    }
    elseif($field == 'Not approved'){
      $field_data = '<div class="status_not_approved" onclick="document.location=' . "'" . $eval_link . "'" . ';" title="Click to see all evaluations of ' . $row['acronym'] . '">&nbsp;</div>';
    }
    else{
      $field_class = 'status_no_br';
      $field_data = $field;
    }
    // Add each field to rows
    $row_data[$j] = array('data' => $field_data, 'class' => $field_class);
    $j++;
  }
  $arr_rows[$i] = array('data' => $row_data, 'class' => array());
  $i++;
}

print '<div class="evaluation_status">';
$table = array(
    'header' => $header,
    'rows' => $arr_rows,
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'No applications fulfill the filter for this page.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);
print '</div>';
?>

