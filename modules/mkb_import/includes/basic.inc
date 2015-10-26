<?php
abstract class mkb_import_Basic_Migration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    ini_set('auto_detect_line_endings', TRUE);
  }
}