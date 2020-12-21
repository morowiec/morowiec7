<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
        <div id="player<?php print $delta; ?>" class="flowplayer"></div>

        <?php flowplayer_add('#player'.$delta, array('clip' => array('url' => $item['#markup']))); ?>

    <?php endforeach; ?>
  </div>
</div>