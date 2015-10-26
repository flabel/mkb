<?php
print "</br>";
print drupal_render($content['field_funder_page']);
print drupal_render($content['field_bud_funding_scheme']);

mkb_application_print_budget_table($variables['budget_table'][0]);

print drupal_render($content['field_bud_budget_info']);
print drupal_render($content['field_bud_documents']);
?>





