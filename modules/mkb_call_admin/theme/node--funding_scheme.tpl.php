<?php
print drupal_render($content['field_call_id']);
print drupal_render($content['field_funder_page']);
print drupal_render($content['field_fun_schc']);


print "<br/>";
print "<label class='mkb_label'>Budget settings</label>";
print "<table class='table_trimmed'>";
  print "<tbody>";
    //Header
    print "<tr>";
      print "<th>Cost item</th>";
      for($i=0; $i<count($variables['field_budget_categories'][0]); $i++){
        print "<th class='td_align_center'>" . $variables['field_budget_categories'][0][$i]['value'] . "</th>";
      }
    print "</tr>";
    $row_names = array('pm', 'pc', 'ts', 'cs', 'eq', 'sc', 'oc', 'ic');
    //Checkboxes
    for($i=0; $i<count($row_names); $i++){
      $row_name = "field_fun_" . $row_names[$i];
      print "<tr>";
        print "<td>" . $content[$row_name]['#title'] . "</td>";
        $checked = array(FALSE, FALSE, FALSE);
        for($j=0; $j<3; $j++){
          if(isset($variables[$row_name][$j]['value'])){
            $checked[$variables[$row_name][$j]['value']-1] = TRUE;
          }
        }
        for($k=0; $k<count($variables['field_budget_categories'][0]); $k++){
          if($checked[$k]){
            print "<td class='td_align_center'><input type='checkbox' disabled='disabled' checked='true'></td>";
          }
          else{
            print "<td class='td_align_center'><input type='checkbox' disabled='disabled'></td>";
        }
      }
      print "</tr>";
    }
    print "<tr>";
    //Request max
    print "<td>" . $content['field_fun_rm']['#title'] . "</td>";
    for($i=0; $i<count($variables['field_budget_categories'][0]); $i++){
      if(isset($variables['field_fun_rm'][$i]['value'])){
        print "<td class='td_align_center'>" . $variables['field_fun_rm'][$i]['value'] . "</td>";
      }
      else{
        print "<td>&nbsp;</td>";
      }
    }
    print "</tr>";
  print "</tbody>";
print "</table>";
print "<br/>";
?>





