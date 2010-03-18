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
    $form = parent::options_form($values);
    $form['search_terms'] = array(
      '#type' => 'textfield',
      '#title' => t('Search terms'),
      '#default_value' => $values['search_terms']
    );
    return $form;
  }
  
  /**
   * Implementation of boxes_content::render().
   */
  public function render($options) {
    // var_dump($options);
  }

}