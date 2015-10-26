<?php
// Build header
$arr_header = array();
$i=0;
foreach ($header as $row){
  $j=0;
  foreach ($row as $field){
    if($i<4 && $j==0){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'id' => "r" . $i . "c" . $j,
          'class' => 'app_selected_04_0',
          'colspan' => 5,
          );
    }
    elseif($i==0 && $j>0){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_center',
          );
    }
    elseif($i>0 && $i<4 && $j>0){
      if($field<0){
        $arr_header[$i][$j] = array(
            'data' => $field,
            'class' => 'app_selected_right_negative',
            );
      }
      else{
        $arr_header[$i][$j] = array(
            'data' => $field,
            'class' => 'app_selected_right',
            );
      }
    }
    elseif($i==4 && $j==0){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_4_0',
          );
    }
    elseif($i==4 && $j==1){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_4_1',
          );
    }
    elseif($i==4 && $j==2){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_4_2',
          );
    }
    elseif($i==4 && $j==3){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_4_3',
          );
    }
    elseif($i==4 && $j==4){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_4_4',
          );
    }
    elseif($i==4 && $j==5){
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_center',
          'colspan' => count($header[0]),
          );
    }
    else{
      $arr_header[$i][$j] = array(
          'data' => $field,
          'class' => 'app_selected_right',
          );
    }
    $j++;
  }
  $i++;
}

$form = drupal_get_form('mkb_eval_application_selection_form');

// Build rows
$arr_rows = array();
$i = 0;
foreach ($variables['content'] as $row){
  // Create each row
  $row_data = array();
  $j = 0;
  foreach ($row as $field){
    // Create each field
    $field_to_add = array(
        'data' => $field,
        'class' => 'app_selected_right',
        );

    if($j==0){
      $field_to_add['class'] = 'app_selected_none_right';
    }
    elseif($j==1){
      $field_to_add['class'] = 'app_selected_none_left';
    }
    elseif($j==2 || $j==3){
      $field_to_add['class'] = 'app_selected_none_center_right';
    }
    elseif($j==4){
      $field_to_add['class'] = 'app_selected_none_center';
    }
    else{
      $field_to_add['class'] = 'app_selected_none_right';
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
        'width' => '',
        ),
    'sticky' => TRUE,
    'empty' => 'No applications fulfill the filter for this page.',
    'colgroups' => array(),
    'caption' => '',
    'rows_multiple' => TRUE,
    );
// print theme_table($table);
print '<div class="application_selection">';
// Use custom theme_table for multiple header rows
print mkb_eval_table($table);
print '</div>';

// Form

print drupal_render($form);
?>

