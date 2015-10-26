<?php

/**
 * Sort function.
 *
 * @param $array
 *   Array to be sorted.
 * @param $key
 *   Key to sort by.
 * @param $order
 *   Sort direction. (optional)
 * @return $output
 *   Rendered output.
 */

function mkb_tools_field_sort (&$array, $sort_key, $order='asc') {
    $sorter=array();
    $new_sorted=array();
    reset($array);
    foreach ($array as $ii => $values) {
        $sorter[$ii]=$values[$sort_key];
    }
    if ($order=='asc') asort($sorter);
    if ($order=='desc') arsort($sorter);
    foreach ($sorter as $ii => $values) {
        $new_sorted[$ii]=$array[$ii];
    }
    $array=$new_sorted;
}
