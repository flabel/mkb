<?php
print '<div class="evaluation_pages">';
drupal_set_title('Proposals by funding agency');
$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'There are no funding agencies for this call.',
    'colgroups' => array(),
    'caption' => $variables['description'],
    );
print theme_table($table);

print '</div>';
?>

