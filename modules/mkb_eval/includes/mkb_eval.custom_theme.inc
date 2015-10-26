<?php

/**
 * Custom theme for application selection form.
 *
 * @param $form
 *   Form.
 * @return $output
 *   Rendered output.
 */
function theme_mkb_eval_application_selection_form_table($variables){
//   kpr(element_children($variables['form']));
//   kpr($variables);
  $form = $variables['form'];
  $rows = array();

  foreach(element_children($form['checkboxes']) as $gid){
    $row = array();
    $row[] = drupal_render($form['checkboxes'][$gid]);
    foreach (element_children($form) as $i){
      if($i==$gid){
        foreach (element_children($form[$i]) as $j){
//           kpr($element);
          $row[] = drupal_render($form[$i][$j]);
        }
      }
    }
    $rows[] = $row;
  }
  $header = array();
//   kpr($form);
  foreach (element_children($form['header']) as $row_key){
    foreach (element_children($form['header'][$row_key]) as $field_key){
      $header[$row_key][$field_key] = $form['header'][$row_key][$field_key]['#value'];
    }
  }

/////// BEGIN TABLE STYLING /////
// Build header
$arr_header = array();
$i=0;
foreach ($header as $row){
  $j=0;
  foreach ($row as $field){
    $arr_header[$i][$j] = array(
      'data' => $field,
      'id' => 'cell_' . $i . "_" . $j,
      );

    if($i<4 && $j==0){
      $arr_header[$i][$j]['class'] = 'app_selected_04_0';
      $arr_header[$i][$j]['colspan'] = 5;
    }
    elseif($i==0 && $j>0){
      $arr_header[$i][$j]['class'] = 'app_selected_center';
    }
    elseif($i>0 && $i<4 && $j>0){
      if($field<0){
        $arr_header[$i][$j]['class'] = 'app_selected_right_negative';
      }
      else{
        $arr_header[$i][$j]['class'] = 'app_selected_right';
      }
    }
    elseif($i==4 && $j==0){
      $arr_header[$i][$j]['class'] = 'app_selected_4_0';
    }
    elseif($i==4 && $j==1){
      $arr_header[$i][$j]['class'] = 'app_selected_4_1';
    }
    elseif($i==4 && $j==2){
      $arr_header[$i][$j]['class'] = 'app_selected_4_2';
    }
    elseif($i==4 && $j==3){
      $arr_header[$i][$j]['class'] = 'app_selected_4_3';
    }
    elseif($i==4 && $j==4){
      $arr_header[$i][$j]['class'] = 'app_selected_4_4';
    }
    elseif($i==4 && $j==5){
      $arr_header[$i][$j]['class'] = 'app_selected_center';
      $arr_header[$i][$j]['colspan'] = count($header[0]);
    }
    else{
      $arr_header[$i][$j]['class'] = 'app_selected_right';
    }
    $j++;
  }
  $i++;
}

// Build rows
$arr_rows = array();
$i = 0;
foreach ($rows as $row){
  // Create each row
  $row_data = array();
  // Use score to determine row color
  $score = $row[4];
//   kpr($score);
  $j = 0;
  foreach ($row as $field){
    $row_index = $i+5;
    // Create each field
    $field_to_add = array(
        'data' => $field,
        'id' => 'cell_' . $row_index . '_' . $j,
        'class' => 'app_selected_right',
        );

      // White background
    if($score >= 0 ){
      if($j==0){
        $field_to_add['class'] = 'app_selected_grey_right';
      }
      elseif($j==1 || $j==2){
        $field_to_add['class'] = 'app_selected_grey_left';
      }
      elseif($j==3){
        $field_to_add['class'] = 'app_selected_grey_center_right';
      }
      elseif($j==4){
        $field_to_add['class'] = 'app_selected_grey_center';
      }
      else{
        $field_to_add['class'] = 'app_selected_grey_right';
      }
    }

      //// Green background
    //if($score >= 4 ){
      //if($j==0){
        //$field_to_add['class'] = 'app_selected_green_right';
      //}
      //elseif($j==1 || $j==2){
        //$field_to_add['class'] = 'app_selected_green_left';
      //}
      //elseif($j==3){
        //$field_to_add['class'] = 'app_selected_green_center_right';
      //}
      //elseif($j==4){
        //$field_to_add['class'] = 'app_selected_green_center';
      //}
      //else{
        //$field_to_add['class'] = 'app_selected_green_right';
      //}
    //}
    //// Red background
    //elseif($score < 3){
      //if($j==0){
        //$field_to_add['class'] = 'app_selected_red_right';
      //}
      //elseif($j==1 || $j==2){
        //$field_to_add['class'] = 'app_selected_red_left';
      //}
      //elseif($j==3){
        //$field_to_add['class'] = 'app_selected_red_center_right';
      //}
      //elseif($j==4){
        //$field_to_add['class'] = 'app_selected_red_center';
      //}
      //else{
        //$field_to_add['class'] = 'app_selected_red_right';
      //}
    //}
    //// Yellow background
    //else{
      //if($j==0){
        //$field_to_add['class'] = 'app_selected_yellow_right';
      //}
      //elseif($j==1 || $j==2){
        //$field_to_add['class'] = 'app_selected_yellow_left';
      //}
      //elseif($j==3){
        //$field_to_add['class'] = 'app_selected_yellow_center_right';
      //}
      //elseif($j==4){
        //$field_to_add['class'] = 'app_selected_yellow_center';
      //}
      //else{
        //$field_to_add['class'] = 'app_selected_yellow_right';
      //}
    //}

    // Add each field to rows
    $row_data[$j] = $field_to_add;
    $j++;
  }
  $arr_rows[$i] = array('data' => $row_data, 'id' => 'R' . $row_index, 'class' => array());
  $i++;
}
////////// END TABLE STYLING /////////////////

//   $output = theme('table', $header, $rows);
  $table = array(
      'header' => $arr_header,
      'rows' => $arr_rows,
      'attributes' => array(
          'class' => '',
          'width' => '',
          'id' => 'application_selection_table',
          ),
      'sticky' => TRUE,
      'empty' => 'No applications fulfill the filter for this page.',
      'colgroups' => array(),
      'caption' => '',
      'rows_multiple' => TRUE,
      );
//   $output = theme_table($table);
  $output = drupal_render($form['title']);
  $output .= mkb_eval_table($table);
  return $output . drupal_render_children($form);
}


function array_sort_by_column(&$arr, $col, $dir = SORT_ASC) {
  $sort_col = array();
  foreach ($arr as $key=> $row) {
      $sort_col[$key] = $row[$col];
  }

  array_multisort($sort_col, $dir, $arr);
}
