<?php

/**
 * Implements hook_views_api().
 */
function mkb_webform_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'mkb_webform'),
    'template path' => drupal_get_path('module', 'mkb_webform') . '/views',
  );
}
