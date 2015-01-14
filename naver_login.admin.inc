<?php

/**
 * @file
 * Administrative page callbacks for the module.
 */

/**
 * Administration settings form.
 *
 * @see system_settings_form()
 */
function naver_login_settings_form($form, &$form_state) {

  $form['naver_login_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Naver Login Client ID'),
    '#default_value' => variable_get('naver_login_client_id', ''),
    '#description' => t('Visit <a href="https://developer.naver.com/openapi/register.nhn" target="_blank">https://developer.naver.com/openapi/register.nhn</a> to obtain Naver Login Service Credential.'),
    '#required' => TRUE,
    '#size' => 20,
  );

  $form['naver_login_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Naver Login Client Secret'),
    '#default_value' => variable_get('naver_login_client_secret', ''),
    //'#description' => t('Visit <a href="https://developer.naver.com/openapi/register.nhn" target="_blank">https://developer.naver.com/openapi/register.nhn</a> to obtain Naver Login Client_ID.'),
    '#required' => TRUE,
    '#size' => 10,
  );

  $form['naver_login_callback_uri'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Callback URL'),
    '#default_value' => $GLOBALS['base_url'] . '/naver_login/auth/retrieve',
  //  '#default_value' => variable_get('naver_login_callback_uri', 'naver_login/register/create'),
    '#description' => t('You should write this Callback URL in Your Naver Application config page.'),
    '#required' => TRUE,
    '#attributes' => array('readonly' => 'readonly'),
    '#size' => 40,
  );
  
  return system_settings_form($form);
}