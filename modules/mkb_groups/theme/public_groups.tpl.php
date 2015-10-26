<div class="groups_table">
<h2 class="block-title">Public groups</h2>
</br>
<?php
drupal_add_js('misc/form.js');
drupal_add_js('misc/collapse.js');

foreach($variables['groups']['public']['rows'] as $key => $row) {
  $group = $row['group'];
  $max_length = 300;
  $tr_group = truncate_utf8($group, $max_length, $wordsafe = TRUE, $add_ellipsis = TRUE, $min_wordsafe_length = 50);
  $variables['groups']['public']['rows'][$key]['group'] = $tr_group;

  if (strlen($group) > strlen($tr_group)) {
    $full = array(
      '#attributes' => array('class' => array('collapsible', 'collapsed'),),
      '#title' => '<strong>Read all</strong>',
  	  '#description' => '',
      '#children' => $group,
      );
    $all = theme('fieldset', array('element' => $full));
    $variables['groups']['public']['rows'][$key]['group'] .= $all;
  }
}


// Public groups
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
    'empty' => 'There are no public groups.',
    'colgroups' => array(),
    'caption' => '',
    );
print theme_table($table);
?>
</div>

