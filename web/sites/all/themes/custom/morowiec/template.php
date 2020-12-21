<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
 

 
 /**
 * Override main menu.
 */
function morowiec_menu_tree__main_menu($variables) {
	return '<nav class="navigation"><ul id="main-menu" class="links inline clearfix main-menu">' . $variables['tree'] . '</ul></nav>';
}

function morowiec_menu_tree__menu_block__main_menu($variables) {
	return '<ul class="menu">' . $variables['tree'] . '</ul>';
}


function morowiec_menu_link__main_menu($variables) {
	$element = $variables['element'];

	$element['#attributes']['class'][] = 'menu-' . $element['#original_link']['mlid'];

	$output = l($element['#title'], $element['#href'], $element['#localized_options']);
	return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";	
}

 /**
 * Override main menu eng.
 */
function morowiec_menu_tree__menu_main_menu_eng($variables) {
	return '<nav class="navigation"><ul id="main-menu" class="links inline clearfix main-menu">' . $variables['tree'] . '</ul></nav>';
}

function morowiec_menu_link__menu_main_menu_eng($variables) {
	$element = $variables['element'];

	$element['#attributes']['class'][] = 'menu-' . $element['#original_link']['mlid'];

	$output = l($element['#title'], $element['#href'], $element['#localized_options']);
	return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . "</li>\n";	
}

 
 /**
 * Override of theme_breadcrumb().
 */
function morowiec_breadcrumb($variables) {
	$breadcrumb = $variables['breadcrumb'];

	if (!empty($breadcrumb)) {
		$breadcrumb[0] = preg_replace('/'.strip_tags($breadcrumb[0]).'/', t(strip_tags($breadcrumb[0])), $breadcrumb[0]);
		
		if(end($breadcrumb) == strip_tags(prev($breadcrumb))) {
			unset($breadcrumb[sizeof($breadcrumb)-2]);
		} elseif (preg_match('/<a.*?>(.*?)<\/a>/', end($breadcrumb), $matches)) {
			$breadcrumb[] = drupal_get_title();
		}
		
		$output = implode(' > ', $breadcrumb);
		return $output;
	}
	
} 

/**
 * Override preprocess_html.
 */
function morowiec_preprocess_html(&$variables) {
	$variables['attributes_array']['class'][] = ' bg-'.rand(1,17);
}

/**
 * Implementation hook_preprocess_field().
 */
function morowiec_preprocess_field(&$variables) {
	if($variables['element']['#field_name'] == 'field_kml') {
    if (variable_get('google_map_field_apikey', '') != '') {
      $element = array(
        '#type' => 'markup',
        '#markup' => '<script type="text/javascript" src="' . google_map_field_get_protocol() . 'maps.googleapis.com/maps/api/js?key=' . variable_get('google_map_field_apikey', '') . '"></script>',
      );
      drupal_add_html_head($element, 'google_maps_api');
    }
    else {
      drupal_add_js(google_map_field_get_protocol() . 'maps.googleapis.com/maps/api/js', 'external');
    }    
	}
}

/**
 * Override or insert variables into the page template.
 */
function morowiec_preprocess_page(&$variables) {

    if (!empty($variables['node'])) {
        $node = $variables['node'];

        if (!empty($node->type)) {
            switch ($node->type) {
                case 'place':
                    break;
            }
            switch ($node->type) {
                case 'travel_stage':
                    //dpm($node->type);
                    break;
            }
        }
    }
}