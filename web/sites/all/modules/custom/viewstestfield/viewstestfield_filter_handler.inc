<?php
/**
 *
 */

class viewstestfield_filter_handler extends views_handler_filter {
	// exposed filter options
	var $always_multiple = TRUE;

	/**
	* Provide some extra help to get the operator/value easier to use.
	*
	* This likely has to be overridden by filters which are more complex
	* than simple operator/value.
	*/
//	function init(&$view, &$options) {
//		parent::init($view, $options);
//	}

//    function options_form(&$form, &$form_state) {
//        parent::options_form($form, $form_state);
//    }
	
    function value_form(&$form, &$form_state) {
//		$options = array('All' => t('- Any -')); 

//		$options[64] = 64;		
//		$options[65] = 65;		
//		$options[66] = 66;		
		
		$form['value'] = array(
			'#type'		=> 'textfield',
//			'#options'	=> $options,
			'#default_value' => $this->value,
		);		

		if (!empty($form_state['exposed'])) {
			$identifier = $this->options['expose']['identifier'];
			if (!isset($form_state['input'][$identifier])) {
				$form_state['input'][$identifier] = $this->value;
			}
		}
    }

    function query() {
		dpm($this);
		dpm($this->view->base_table);
//        $this->ensure_my_table();
		
		$condition = db_or()->condition($this->view->base_table . '.' . $this->view->base_field, $this->value);
		$this->query->add_where(0, $condition);				
		
    }

};

?>