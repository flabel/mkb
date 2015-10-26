<?php

module_load_include('inc', 'mkb_tools', 'includes/mkb_tools.helper');

/**
 * Generates content for views_usage template.
 *
 * @return template
 *   Views usage template.
 */
function mkb_tools_views_usage_function(){
  $variables = array();

  // Mapped
  $m_header = array('View', 'Tag', 'Menu', 'Path', 'Hidden');
  $m_rows = array();

  // Unmapped
  $u_header = array('View', 'Tag', 'Description');
  $u_rows = array();

  // Get all views
  $views = views_get_all_views();
//   dpm($views);
  // Run through views and and add to rows if view path is in use in menu_link table
  $menu_links = mkb_tools_get_menu_links();
  foreach ($views as $machine_name => $view){
    if(isset($view->display['page'])){
      $page = $view->display['page'];
      $view_path = $page->display_options['path'];
      $view_added = FALSE;
      foreach ($menu_links as $menu_link){
        $menu_link_paths = explode('/', $menu_link->link_path);
        if(in_array($view_path, $menu_link_paths)){
          $m_rows[$machine_name] = array(
              'machine_name' => $machine_name,
              'tag' => $view->tag,
              'menu_name' => $menu_link->menu_name,
              'menu_path' => $menu_link->link_path,
              'hidden' => $menu_link->hidden,
              );
          $view_added = TRUE;
        }
//         if(strpos($menu_link->link_path, $view_path) !== FALSE){
//           $m_rows[$machine_name] = array(
//               'machine_name' => $machine_name,
//               'tag' => $view->tag,
//               'menu_name' => $menu_link->menu_name,
//               'menu_path' => $menu_link->link_path,
//               'hidden' => $menu_link->hidden,
//               );
//           $view_added = TRUE;
//         }
      }
      if($view_added == FALSE){
        $u_rows[$machine_name] = array(
            'machine_name' => $machine_name,
            'tag' => $view->tag,
            'description' => $view->description,
            );
      }
    }
  }

  // Sort by menu-name
  mkb_tools_field_sort($m_rows, 'menu_name', $order='asc');

  $variables['m_header'] = $m_header;
  $variables['m_rows'] = $m_rows;
  $variables['u_header'] = $u_header;
  $variables['u_rows'] = $u_rows;
  return theme('views_usage_template', $variables);
}

function mkb_tools_get_menu_links(){
  $standard_menus = array('management', 'user-menu', 'navigation', 'devel');
  $query = db_select("menu_links", "m");
  $query ->addField("m", "menu_name", "menu_name");
  $query ->addField("m", "link_path", "link_path");
  $query ->addField("m", "hidden", "hidden");
  $query
  ->condition("m.menu_name", $standard_menus, 'NOT IN');
  $result = $query->execute()->fetchAll();
  return $result;
}
