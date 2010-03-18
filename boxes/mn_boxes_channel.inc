<?php

class mn_boxes_channel extends mn_boxes_default implements boxes_content {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults($values);
    $options['channel'] = '';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form($values) {
    $form = parent::options_form($values);
    $result = db_query(db_rewrite_sql("SELECT nid, title FROM {node} WHERE type = 'channel' ORDER BY title"));
    while ($row = db_fetch_array($result)) {
      $channels[$row['nid']] = $row['title'];
    }
    $form = array();
    $form['channel'] = array(
      '#type' => 'select',
      '#title' => t('Channel'),
      '#options' => $channels,
      '#default_value' => $options['channel'],
    );
    $form += parent::options_form($values);
    return $form;
  }
  
  /**
   * Implementation of boxes_content::render().
   */
  public function render($options) {
    $view = views_get_view('mn_channels_news');

    switch ($options['type']) {
      case 'listing':
        $view->set_display('block_3');
        $view->display_handler->set_option('items_per_page', $options['number_of_items']);
        break;
      case 'map':
        $view->set_display('block_2');
        break;
      case 'graph':
        $view->set_display('block_1');
        break;
    }
    
    $view->set_arguments(array($options['channel']));
    $output = $view->execute_display();
    return $output['content'];
  }

}