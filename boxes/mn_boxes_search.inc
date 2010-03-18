<?php

class mn_boxes_default implements boxes_content {
  /**
   * Implementation of boxes_content::options_defaults().
   */
  public function options_defaults() {
    return array(
      'body' => '',
      'format' => FILTER_FORMAT_DEFAULT,
    );
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function options_form($values) {
    if (filter_access($values['format'])) {
      $form = array();
      $form['body'] = array(
        '#type' => 'textarea',
        '#title' => t('Box body'),
        '#default_value' => $values['body'],
        '#rows' => 6,
        '#description' => t('The content of the block as shown to the user.'),
      );
      $form['format'] = filter_form($values['format']);
      return $form;
    }
  }

  /**
   * Implementation of boxes_content::options_form().
   */
  public function render($options) {
    if (!empty($options['body']) && !empty($options['format'])) {
      return check_markup($options['body'], $options['format'], FALSE);
    }
    return '';
  }
}