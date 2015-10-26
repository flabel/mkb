<?php
/**
 * @file
 * mkb_call_admin.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function mkb_call_admin_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'call_description';
  $page->task = 'page';
  $page->admin_title = 'Call description';
  $page->admin_description = 'Information from call-main-page and call-funder-page';
  $page->path = 'call_description/%node';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array(
    'node' => array(
      'id' => 1,
      'identifier' => 'Node: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_call_description_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'call_description';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Call description',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '90224173-57bb-4d5e-82ab-9410ba9b91e6';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c1740cfe-2b50-4826-a3fb-a47922847245';
    $pane->panel = 'center';
    $pane->type = 'token';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c1740cfe-2b50-4826-a3fb-a47922847245';
    $display->content['new-c1740cfe-2b50-4826-a3fb-a47922847245'] = $pane;
    $display->panels['center'][0] = 'new-c1740cfe-2b50-4826-a3fb-a47922847245';
    $pane = new stdClass();
    $pane->pid = 'new-3f50bd97-31d1-494d-9c68-eff6d0cdb5fd';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'call_description_definition-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3f50bd97-31d1-494d-9c68-eff6d0cdb5fd';
    $display->content['new-3f50bd97-31d1-494d-9c68-eff6d0cdb5fd'] = $pane;
    $display->panels['center'][1] = 'new-3f50bd97-31d1-494d-9c68-eff6d0cdb5fd';
    $pane = new stdClass();
    $pane->pid = 'new-b25e1160-6db6-483d-a8e3-95575c5c22fe';
    $pane->panel = 'center';
    $pane->type = 'views';
    $pane->subtype = 'call_topics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'context' => array(
        0 => '',
      ),
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b25e1160-6db6-483d-a8e3-95575c5c22fe';
    $display->content['new-b25e1160-6db6-483d-a8e3-95575c5c22fe'] = $pane;
    $display->panels['center'][2] = 'new-b25e1160-6db6-483d-a8e3-95575c5c22fe';
    $pane = new stdClass();
    $pane->pid = 'new-9f8c0cb3-b255-437a-8011-5a34b27cd131';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'call_description_time-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '9f8c0cb3-b255-437a-8011-5a34b27cd131';
    $display->content['new-9f8c0cb3-b255-437a-8011-5a34b27cd131'] = $pane;
    $display->panels['center'][3] = 'new-9f8c0cb3-b255-437a-8011-5a34b27cd131';
    $pane = new stdClass();
    $pane->pid = 'new-c0c5b78f-3175-4507-be1d-5e59a2738a2c';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'call_description_funders-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'c0c5b78f-3175-4507-be1d-5e59a2738a2c';
    $display->content['new-c0c5b78f-3175-4507-be1d-5e59a2738a2c'] = $pane;
    $display->panels['center'][4] = 'new-c0c5b78f-3175-4507-be1d-5e59a2738a2c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['call_description'] = $page;

  return $pages;

}
