<?php

class mn_boxes_search extends mn_boxes_default implements boxes_content {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    $options = parent::options_defaults($values);
    $options['search_terms'] = '';
    return $options;
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form($values) {
    $form['search_terms'] = array(
      '#type' => 'textfield',
      '#title' => t('Search terms'),
      '#default_value' => $values['search_terms']
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
    if (!empty($options['search_terms'])) {
      $view->set_exposed_input(array('search' => $options['search_terms']));
    }
    $output = $view->execute_display();
    return $output['content'];
  }

}