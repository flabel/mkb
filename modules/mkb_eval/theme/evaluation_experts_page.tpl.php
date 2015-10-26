<div class="expert_pages">
<?php
print '<table class="image_desc"><tr>';
print '<td><b>Conflict: </b>';
print '<ul class="no_style">';
print '<li>' . $variables['images']['con_missing_img'] . ' Missing</li>' ;
print '<li>' . $variables['images']['con_no_img'] . ' Declared no conflict</li>' ;
print '<li>' . $variables['images']['con_yes_img'] . ' Declared conflict</li>' ;
print '</ul></td>';

print '<td><b>Evaluation: </b>';
print '<ul class="no_style">';
print '<li>' . $variables['images']['eval_missing_img'] . ' Missing</li>' ;
print '<li>' . $variables['images']['eval_created_img'] . ' Complete</li>' ;
// print '<li>' . $variables['images']['eval_eval_approved_wc_img'] . ' Approved with conditions</li>' ;
print '<li>' . $variables['images']['eval_not_approved_img'] . ' Incomplete</li>' ;
print '</ul></td>';
print '</tr></table>';

$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('expert_evaluators_table'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'No applications have been submitted for this call stage.',
    'colgroups' => array(),
    'caption' => 'Number of applications: ' . $variables['count'],
    );
print theme_table($table);
?>
</div>
