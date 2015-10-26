<?php

/**
 * @param $cid
 *   Call-main-page node id
 * @return $funder_agencies
 *   Funding agencies for this call.
  */
function mkb_pm_get_all_funding_agency_names($cid){
  $query = db_select("field_data_field_call_id", "field_call_id");
  $query ->leftJoin("field_data_field_funding_agency", "field_funding_agency", "field_funding_agency.entity_id = field_call_id.entity_id");
  $query ->leftJoin("field_data_field_org_name", "field_org_name", "field_org_name.entity_id = field_funding_agency.field_funding_agency_target_id");
  $query ->leftJoin("field_data_field_country", "field_country", "field_country.entity_id = field_org_name.entity_id");
  $query ->addField("field_call_id", "entity_id", "funder_page_nid");
  $query ->addField("field_org_name", "field_org_name_value", "org_name");
  $query ->addField("field_country", "field_country_iso2", "iso2");
  $query
    ->condition("field_call_id.bundle", 'call_funder_page')
    ->condition("field_call_id.entity_type", 'node')
    ->condition("field_call_id.field_call_id_target_id", $cid)
    ->condition("field_funding_agency.bundle", 'call_funder_page')
    ->condition("field_country.bundle", 'organisation');
  $query ->orderBy('field_country_iso2', 'ASC');
  $result = $query->execute()->fetchAll();
  if($result !== FALSE){
    $funding_agencies = array();
    foreach ($result as $row){
      $funding_agencies[$row->funder_page_nid] = $row->org_name;
    }
    return $funding_agencies;
  }
  return $result;
}
