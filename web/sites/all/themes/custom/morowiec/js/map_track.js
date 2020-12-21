// JavaScript Document
// https://groups.google.com/forum/?fromgroups=#!topic/google-maps-js-api-v3/-0Pex3qfHPM

var map;

var kmlLayer = new Array();
var layerControlId = new Array();
var currentLayer = null;
var ts = Math.round(new Date().getTime() / 1000);

var markers = new Array();

function initializeMap(target_id, start_x, start_y) {
    jQuery(document).ready(function() {
        var myLatlng = new google.maps.LatLng(start_y, start_x);
        var myOptions = {
            zoom: 8,
            center: myLatlng,
            mapTypeId: google.maps.MapTypeId.ROADMAP
        }
        map = new google.maps.Map(document.getElementById(target_id), myOptions);

    });
}

function addKmlFile(delta, url) {
    jQuery(document).ready(function() {
        url += '?ts=' + ts;

        layerControlId['layer_' + delta] = delta;
        kmlLayer[delta] = new google.maps.KmlLayer({
          url: url,
          map: map
        });
        
        kmlLayer[delta].setMap(map);
        jQuery('#layerControl_' + delta).on('change', function() {
            if (jQuery(this).is(':checked')) {
                kmlLayer[delta].setMap(map);
            } else {
                kmlLayer[delta].setMap(null);
            }
        });
    });
}

function addNewPoint(lat, lng, title, content) {
    jQuery(document).ready(function() {
        //alert(lat+" - "+lng);
        var pointLatlng = new google.maps.LatLng(lat, lng);

        var marker = new google.maps.Marker({
            position: pointLatlng,
            map: map,
            title: title
        });

        markers.push(marker);

        var infowindow = new google.maps.InfoWindow({
            content: content
        });

        google.maps.event.addListener(marker, 'click', function() {
            infowindow.open(map, marker);
        });

    });
}

function disableControls() {
    jQuery('#map_controls').hide();
}

function autoCenter() {
    var limits = new google.maps.LatLngBounds();
    jQuery.each(markers, function(index, marker) {
        limits.extend(marker.position);
    });
    map.fitBounds(limits);
}

//function initializeMapOld(target_id, url, start_x, start_y) {
//    //alert(target_id+' '+url+' '+start_x+' '+start_y);
//    jQuery(document).ready(function() {
//        var myLatlng = new google.maps.LatLng(start_y, start_x);
//        var myOptions = {
//            zoom: 8,
//            center: myLatlng,
//            mapTypeId: google.maps.MapTypeId.ROADMAP
//        }
//        map = new google.maps.Map(document.getElementById(target_id), myOptions);
//
//        // Wczytywanie mapy za kazdym razem
//        url += '?ts=' + ts;
//
//        kmlLayer[0] = new google.maps.KmlLayer(url);
//        kmlLayer[0].setMap(map);
//        //currentLayer = kmlLayer[0];
//    });
//
//}
