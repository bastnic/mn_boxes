<?php

class mn_boxes_default implements boxes_content {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'type' => 'listing',
      'number_of_items' => 5,
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form($values) {
    if (filter_access($values['format'])) {
      $form['type'] = array(
        '#type' => 'radios',
        '#title' => t('Type'),
        '#default_value' => $values['type'],
        '#options' => array('listing' => t('Listing'), 'map' => t('Map'), 'graph' => t('Graph')),
      );
      $form['number_of_items'] = array(
        '#type' => 'textfield',
        '#title' => t('Number of items'),
        '#default_value' => $values['number_of_items'],
      );
      return $form;
    }
  }

  /**
   * Implementation of boxes_content::render().
   */
  public function render($options) {
    return '';
  }
}