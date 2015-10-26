<?php
print '<div class="questionnaires">';
//drupal_set_title('Questionnaires for ' . $variables['acronym']);
drupal_set_title('Evaluations');
$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'There are no participants in this proposal. Please contact the administrator.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);
print '</div>';
?>

