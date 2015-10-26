<?php
/**
 * @file
 * mkb_groups.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function mkb_groups_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_work_space_forum';
  $page->task = 'page';
  $page->admin_title = 'Groups work space forum';
  $page->admin_description = 'Work space forum content';
  $page->path = 'groups/workspace/forum/%node';
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
  $handler->name = 'page_groups_work_space_forum_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_work_space_forum';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Forum',
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
      'iprojects_group_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5e2de0ed-d00f-45d6-a176-d1cbae5fefd5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-c00cff8a-6dfe-44cb-9b61-f4ab76e5c225';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'groups_ws_forum-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c00cff8a-6dfe-44cb-9b61-f4ab76e5c225';
    $display->content['new-c00cff8a-6dfe-44cb-9b61-f4ab76e5c225'] = $pane;
    $display->panels['center'][0] = 'new-c00cff8a-6dfe-44cb-9b61-f4ab76e5c225';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_work_space_forum'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_work_space_members';
  $page->task = 'page';
  $page->admin_title = 'Groups work space members';
  $page->admin_description = 'Administer iproject members';
  $page->path = 'groups/workspace/members/%node';
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
  $handler->name = 'page_groups_work_space_members_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_work_space_members';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Members',
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
      'iprojects_group_sidebar' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '6d64553a-8de4-4148-8f14-fcdadedf26f4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-12b767ca-02f7-4b5c-a1d2-753322e10523';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'groups_ws_members-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '12b767ca-02f7-4b5c-a1d2-753322e10523';
    $display->content['new-12b767ca-02f7-4b5c-a1d2-753322e10523'] = $pane;
    $display->panels['center'][0] = 'new-12b767ca-02f7-4b5c-a1d2-753322e10523';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_work_space_members'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'groups_workspace_user_profiles';
  $page->task = 'page';
  $page->admin_title = 'Groups workspace user-profiles';
  $page->admin_description = 'Panel for showing the view user-profiles in application workspace';
  $page->path = 'groups/workspace/user-profiles';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_groups_workspace_user_profiles_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'groups_workspace_user_profiles';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
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
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3ee15603-35a6-459a-90f9-aa13c8411f39';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-24f45a43-2e62-4ea0-ba8e-504c612acf26';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'user_profiles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '20',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '24f45a43-2e62-4ea0-ba8e-504c612acf26';
    $display->content['new-24f45a43-2e62-4ea0-ba8e-504c612acf26'] = $pane;
    $display->panels['middle'][0] = 'new-24f45a43-2e62-4ea0-ba8e-504c612acf26';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-24f45a43-2e62-4ea0-ba8e-504c612acf26';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['groups_workspace_user_profiles'] = $page;

  return $pages;

}
