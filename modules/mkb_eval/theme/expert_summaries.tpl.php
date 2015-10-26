<?php
print '<div class="evaluation_pages">';
drupal_set_title('Expert evaluation summaries');

$table = array(
    'header' => $variables['header'],
    'rows' => $variables['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => TRUE,
    'empty' => 'There are no proposals that have passed formality and eligibility check.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);

print '</div>';
?>


