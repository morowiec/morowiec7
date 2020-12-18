<?php
/**
 *
 */
// This file must be at viewstestfield/views directory.

/*
Links:
http://stackoverflow.com/questions/7891518/drupal-7-custom-view-with-custom-table-no-data-showing-up
https://www.drupal.org/sandbox/Gajendrasharma/1996980
http://drupal.stackexchange.com/questions/80203/custom-views-handler-without-table
https://gist.github.com/juampy72/5816530

 
/**
 * @file
 * Definition of viewstestfield_handler_testfield.
 */
 
/**
 * Description of what my handler does.
 */
class viewstestfield_handler_testfield extends views_handler_field {
  /**
   * Add some required fields needed on render().
   */
 
/* 
  function construct() {
    parent::construct();
    $this->additional_fields['field_something'] = array(
      'table' => 'field_data_field_something',
      'field' => 'field_something_value',
    );
  }
*/
 
  /**
   * Loads additional fields.
   */

  function query() {
//    $this->ensure_my_table();
//    $this->add_additional_fields();
  }
  /**
   * Default options form.
   */

  function option_definition() {
     $options = parent::option_definition();

     // Override the alter text option to always alter the text.
     $options['alter']['contains']['alter_text'] = array('default' => TRUE);
     return $options;
  }
 
  /**
   * Creates the form item for the options added.
   */

   function options_form(&$form, &$form_state) {
     parent::options_form($form, $form_state);

     // Remove the checkbox
     unset($form['alter']['alter_text']);
     unset($form['alter']['text']['#dependency']);
     unset($form['alter']['text']['#process']);
   }





  /**
   * Renders the field handler.
   */
  function render($values) {
	  
	  
	  return $values->nid;
/*
    return format_string('<div class="@option_a" data-tag="@field_something" data-follow_name="@option_b"></div>', array(
      '@field_something' => $values->field_data_field_something_field_something_value,
      '@option_a' => $this->options['option_a'],
      '@option_b' => $this->options['option_b'],
    ));
*/	
  }
}

?>