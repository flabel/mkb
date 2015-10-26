<div class="expert_pages">
<?php
$table = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '50%',
        ),
    'sticky' => FALSE,
    'empty' => 'There are no expert evaluation types for this call.',
    'colgroups' => array(),
    'caption' => 'Click on an call to assign evaluation experts',
    );
print theme_table($table);
?>
</div>
