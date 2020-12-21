<?php

	//drupal_add_js('https://maps.googleapis.com/maps/api/js?key=AIzaSyDE8Fy74TrhIL_ahmZSImg1XFmf2EP5_ps&sensor=false', array('scope' => 'header','weight' => '14'));
	drupal_add_js(drupal_get_path('theme', 'morowiec') . '/js/map_track.js', array('scope' => 'header', 'weight' => '15'));
	drupal_add_js(drupal_get_path('theme', 'morowiec') . '/js/images_work.js', array('scope' => 'header', 'weight' => '16'));

?>