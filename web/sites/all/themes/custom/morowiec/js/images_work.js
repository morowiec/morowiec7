// JavaScript Document

function BZ_addImageTitle(type) {
    jQuery(document).ready(function() {
        switch (type) {
            case 'centeredWithTitle':
                //jQuery('.centeredWithTitle').css("border","3px solid red");
                jQuery('img.centeredWithTitle').wrap('<div class="imageCenteringBox" />');
                jQuery('img.centeredWithTitle').wrap('<div class="imageBox" />');
                jQuery('.imageBox').append('<div class="imageBoxTitle" />');

                jQuery('.imageBoxTitle').each(function() {
                    if (jQuery(this).parent('.imageBox').children('img.centeredWithTitle').attr("title")) {
                        jQuery(this).html('<p>' + jQuery(this).parent('.imageBox').children('img.centeredWithTitle').attr("title") + '</p>');
                    }
                });
                //jQuery('.centeredWithTitle').after('</div>');
                break;
            case 'leftWithTitle':
                jQuery('img.leftWithTitle').wrap('<div class="imageLeftBox" />');
                jQuery('img.leftWithTitle').wrap('<div class="imageBox" />');
                jQuery('.imageBox').append('<div class="imageBoxTitle" />');

                jQuery('.imageLeftBox .imageBoxTitle').each(function() {
                    if (jQuery(this).parent('.imageBox').children('img.leftWithTitle').attr("title")) {
                        jQuery(this).html('<p>' + jQuery(this).parent('.imageBox').children('img.leftWithTitle').attr("title") + '</p>');
                    }
                });
                break;
            case 'rightWithTitle':
                jQuery('img.rightWithTitle').wrap('<div class="imageRightBox" />');
                jQuery('img.rightWithTitle').wrap('<div class="imageBox" />');
                jQuery('.imageBox').append('<div class="imageBoxTitle" />');

                jQuery('.imageRightBox .imageBoxTitle').each(function() {
                    if (jQuery(this).parent('.imageBox').children('img.rightWithTitle').attr("title")) {
                        jQuery(this).html('<p>' + jQuery(this).parent('.imageBox').children('img.rightWithTitle').attr("title") + '</p>');
                    }
                });
                break;

        }
    });
}
