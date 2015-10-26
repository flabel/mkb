<?php
module_load_include('inc', 'mkb_eval', 'includes/mkb_eval.helper');
module_load_include('inc', 'mkb_eval', 'includes/pages/mkb_eval.evaluation_overview');
module_load_include('inc', 'mkb_eval', 'includes/pages/mkb_eval.list_evaluations');
module_load_include('inc', 'mkb_eval', 'includes/pages/mkb_eval.proposal_budgets');

/**
 * Generates content for paths template.
 *
 * @return template
 *   The template paths is called with $content.
 */
function mkb_eval_paths(){
  $variables = array();

  $header = array('#', 'Path', 'Arguments', 'Title', 'Description');
  $rows = array();

  //Get evaluation menu paths
  $menu_items = mkb_eval_menu();

  // Build rows
  $i = 0;
  foreach ($menu_items as $path => $menu_item){
    // No. and path
    $rows[$i][] = $i;
    $rows[$i][] = $path;

    // Arguments
    $p = explode('|', $menu_item['page callback']);
    $call_back = $p[0];
    $args = get_func_argNames($call_back);
    $items = array();
    foreach($args as $arg){
        $items[] = $arg;
    }
    $rows[$i][] = theme_item_list(array('items' => $items, 'title' => '', 'type' => 'ol', 'attributes' => array()));
    
    // Title and Decription
    $rows[$i][] = $menu_item['title'];
    $rows[$i][] = $menu_item['description'];

    $i++;
  }
  

  $variables['header'] = $header;
  $variables['rows'] = $rows;
  return theme('paths', $variables);
}

function get_func_argNames($funcName) {
    $f = new ReflectionFunction($funcName);
    $result = array();
    foreach ($f->getParameters() as $param) {
        $result[] = $param->name;   
    }
    return $result;
}
