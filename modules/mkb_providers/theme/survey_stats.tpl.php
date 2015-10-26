<?php

$response_type = $variables['response_type'];
$response_count = $variables['response_count'];
$response_stats = $variables['response_stats'];

print '<h1>' . t('ICT provider survey statistics on ') . $response_type . '</h1>';
print '<p>' . t('Number of responses: ') . $response_count . '</p>';
foreach($response_stats as $field_name => $field) {
// Group headers
  switch($field_name) {
    case 'field_provider_pcf': print '<h3>' . 'In what area of agriculture is your ICT product/service being used?' . '</h3>'; 
	break;
    case 'field_provider_pcf_2': print '<h3>' . 'What does your product/service provide?' . '</h3>'; 
	break;
  }
// Table headers
  switch($field_name) {
    case 'field_provider_pcf': 
    case 'field_provider_pcf_2': $header = array('Precision Crop Farming', 'N');
	break;
    case 'field_provider_plf': 
    case 'field_provider_plf_2': $header = array('Precision Livestock Farming', 'N');
	break;
    case 'field_provider_acc': 
    case 'field_provider_acc_2': $header = array('Automated Climate Control', 'N');
	break;
    case 'field_provider_aqc': 
    case 'field_provider_aqc_2': $header = array('Automated Quality Control', 'N');
	break;
    case 'field_provider_fmis': 
    case 'field_provider_fmis_2': $header = array('Farm Management Information Systems', 'N');
	break;
	default: $header = array($field['description'], 'N');
  }
  $rows = array();
  foreach ($field['allowed_values'] as $i => $option) {
    if ($response_type == 'profile') $label = l($option, 'survey_responses/' . $field_name . '/' . $i);
	else $label = $option;
    $row = array($label, $field['counts'][$i]);
    $rows[] = $row;
  }
  // Render and print table
  $table = array(
      'header' => $header,
      'rows' => $rows,
      'attributes' => array(
          'class' => array('provider-survey-table'),
          ),
      'sticky' => FALSE,
      'empty' => 'Nothing',
      'colgroups' => array(),
      'caption' => '',
      );
  print theme_table($table);
}

