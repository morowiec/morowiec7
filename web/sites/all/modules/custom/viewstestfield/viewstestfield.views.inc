<?php

/**
 * Implements hook_views_data().
 */

function viewstestfield_views_data() {
	$data = array();


	$data['testtable']['table']['group'] = t('Custom');
	$data['testtable']['table']['join'] = array(
		// #global is a special flag which let's a table appear all the time.
		'#global' => array(),
	);

	$data['testtable']['testfield'] = array(
		'group' => t('Custom'),
		'title' => t('Testfield'),
		'help' => t('Show only this content type with user can edit.'),
		'field' => array( 
//			'help' => t('The aliased path to this content.'), 
			'handler' => 'viewstestfield_handler_testfield', 
		),
		'filter' => array(
			'handler' => 'viewstestfield_filter_handler'
		),
	); 

	return $data;
}

?>
