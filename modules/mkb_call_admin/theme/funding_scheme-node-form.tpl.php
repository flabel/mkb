<?php
print drupal_render($form['title']);
print drupal_render($form['field_call_id']);
print drupal_render($form['field_funder_page']);
print drupal_render($form['field_fun_schc']);

print "<br/>";
print "<label>Budget settings</label>";
print "<table border='2'>";
  print "<tbody>";
    //Header
    print "<tr>";
      print "<th>Cost item</th>";
      print "<th class='td_align_center'>RTD</th>";
      print "<th class='td_align_center'>Demonstration</th>";
      print "<th class='td_align_center'>Marketing</th>";
    print "</tr>";
    $row_names = array('categories', 'pm', 'pc', 'ts', 'cs', 'eq', 'sc', 'oc', 'ic');
    //Checkboxes
    for($i=0; $i<9; $i++){
      $row_name = "field_fun_" . $row_names[$i];
      print "<tr>";
        if($row_name == "field_fun_categories"){
          print "<td>" . "*" . $form[$row_name]['und']['#title'] . "</td>";
        }
        else{
          print "<td>" . $form[$row_name]['und']['#title'] . "</td>";
        }
        for($j=1; $j<4; $j++){
          $form[$row_name]['und'][$j]['#title'] = "";
          print "<td class='td_align_center'>" . drupal_render($form[$row_name]['und'][$j]) . "</td>";
        }
      print "</tr>";
    }
    print "<tr>";
    //Request max
    print "<td>" . "**" . $form['field_fun_rm']['und']['#title'] . " (%)" . "</td>";
    for($i=0; $i<3; $i++){
      hide($form['field_fun_rm']['und'][$i]['_weight']);
      print "<td>" . drupal_render($form['field_fun_rm']['und'][$i]) . "</td>";
    }
    print "</tr>";
  print "</tbody>";
print "</table>";
print "<br/>";

//Table notes
print "*" . $form['field_fun_categories']['und']['#description'];
print "<br/>";
print "**" . $form['field_fun_rm']['und']['#description'];
print "<br/>";

//Remove fields
hide($form['field_fun_rm']);
hide($form['field_fun_categories']);
hide($form['field_fun_pm']);
hide($form['field_fun_pc']);
hide($form['field_fun_ts']);
hide($form['field_fun_cs']);
hide($form['field_fun_eq']);
hide($form['field_fun_sc']);
hide($form['field_fun_oc']);
hide($form['field_fun_ic']);

print drupal_render_children($form);
?>





