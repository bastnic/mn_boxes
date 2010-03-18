<?php

class mn_boxes_feed extends mn_boxes_default implements boxes_content {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults($values);
    $options['feed'] = 0;
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form($values) {
    $result = db_query(db_rewrite_sql("SELECT nid, title FROM {node} WHERE type = 'feed' ORDER BY title"));
    $feeds = array(0 => '<'. t('All feeds') .'>');
    while ($row = db_fetch_array($result)) {
      $feeds[$row['nid']] = $row['title'];
    }
    $form['feed'] = array(
      '#type' => 'select',
      '#title' => t('Feed'),
      '#options' => $feeds,
      '#default_value' => $values['feed']
    );
    $form += parent::options_form($values);
    return $form;
  }
  
  /**
   * Implementation of boxes_content::render().
   */
  public function render($options) {
    $view = views_get_view('mn_news');

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

    if ($options['feed']) {
      $view->set_arguments(array($options['feed']));
    }
    $output = $view->execute_display();
    return $output['content'];
  }

}