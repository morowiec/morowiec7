<?php

/**
 * Implements hook_views_data().
 */

function views_content_type_filter_views_data() {
	$data = array();
	
	// Better content type filter.
	$data['node']['views_content_type_filter'] = array(
		'group' => t('Custom'),
		'real field'  => 'type',
		'title' => t('Content type'),
		'help' => t('Show only this content type with user can edit.'),
		'filter' => array(
			'handler' => 'views_content_type_filter_handler'
		),
	); 

	return $data;
}

?>
