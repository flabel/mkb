<?php
print '<div class="evaluation_pages">';
drupal_set_title('Proposals budgets');

$arr_header = array();
$header_data = array();
$j = 0;
foreach ($variables['header'] as $field){
  // Create each field
  $field_to_add = array(
      'data' => $field,
      );

  if($j>1 && $j<$variables['countries_count']+3){
    $field_to_add['class'] = 'align_right';
  }

  // Add each field to rows
  $header_data[$j] = $field_to_add;
  $j++;
}
$arr_header = $header_data;

$arr_rows = array();
$i = 0;
foreach ($variables['rows'] as $row){
  // Create each row
  $row_data = array();
  $j = 0;
  foreach ($row as $field){
    // Create each field
    $field_to_add = array(
        'data' => $field,
        );

    if($j>1 && $j<$variables['countries_count']+3){
      $field_to_add['class'] = 'align_right';
    }

    // Add each field to rows
    $row_data[$j] = $field_to_add;
    $j++;
  }
  $arr_rows[$i] = array('data' => $row_data, 'class' => array());
  $i++;
}

$table = array(
    'header' => $arr_header,
    'rows' => $arr_rows,
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'There are no proposals which has passed formality and eligibility.',
    'colgroups' => array(),
    'caption' => $variables['description'],
    );
print theme_table($table);

print '</div>';
?>

