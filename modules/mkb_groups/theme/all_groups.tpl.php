<div class="groups_table">
<h2 class="block-title">All groups</h2>
</br>

<?php
// Private groups
foreach($variables['groups']['private']['rows'] as $key => $row) {
  $group = ltrim($row['group']);
  $max_length = 300;
  $tr_group = truncate_utf8($group, $max_length, $wordsafe = FALSE, $add_ellipsis = TRUE, $min_wordsafe_length = 50);
  $variables['groups']['private']['rows'][$key]['group'] = $tr_group;
}

$private_header = array();
$private_header[0] = array(
    'data' => $variables['groups']['private']['header'][0],
    'class' => 'groups_first_row',
    );
$private_header[1] = array(
    'data' => $variables['groups']['private']['header'][1],
    'class' => 'groups_second_row',
    );

$table = array(
    'header' => $private_header,
    'rows' => $variables['groups']['private']['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => FALSE,
    'empty' => 'No private groups.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);

print '</br>';

// Public groups
foreach($variables['groups']['public']['rows'] as $key => $row) {
  $group = ltrim($row['group']);
  $max_length = 300;
  $tr_group = truncate_utf8($group, $max_length, $wordsafe = FALSE, $add_ellipsis = TRUE, $min_wordsafe_length = 50);
  $variables['groups']['public']['rows'][$key]['group'] = $tr_group;
}

$public_header = array();
$public_header[0] = array(
    'data' => $variables['groups']['public']['header'][0],
    'class' => 'groups_first_row',
    );
$public_header[1] = array(
    'data' => $variables['groups']['public']['header'][1],
    'class' => 'groups_second_row',
    );

$table = array(
    'header' => $public_header,
    'rows' => $variables['groups']['public']['rows'],
    'attributes' => array(
        'class' => array('table_class'),
        'width' => '100%',
        ),
    'sticky' => FALSE,
    'empty' => 'No public groups.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);
?>
</div>

