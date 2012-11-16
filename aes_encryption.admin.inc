<?php

/**
 * @file
 * Provides admin configuration for the AES Encryption module.
 */

/**
 * Presents the settings for the AES Encryption module.
 */
function aes_encryption_config() {
  $form = array();

  $ciphers = array(
    'rijndael-128' => 'Rijndael 128',
    'rijndael-192' => 'Rijndael 192',
    'rijndael-256' => 'Rijndael 256',
  );
  $ciphers_default_value = variable_get('aes_encryption_cipher', 'rijndael-128');
  $key = variable_get('aes_encryption_key', '');

  $form['cipher'] = array(
    '#type'          => 'select',
    '#title'         => t('Cipher strength'),
    '#description'   => t('Select the cipher strength.'),
    '#options'       => $ciphers,
    '#default_value' => $ciphers_default_value,
  );

  $form['key'] = array(
    '#type'        => 'password',
    '#title'       => t('Encryption key'),
    '#description' => t('The encryption key. If none is specified (default), then a key is automatically generated.'),
    '#value'       => $key,
  );

  $original = t('The quick brown fox jumped over some fences and stuff. If you can read this, the module is working perfectly.');
  $form['verification'] = array(
    '#type'   => 'markup',
    '#markup' => '<strong>' . t('Verification of Module') . '</strong><br />' . t('If this module is installed, and working properly, the two lines below should be identical:') . '<br />&bull; ' . $original . '<br />&bull; ' . aes_decrypt(aes_encrypt($original)) . '<br />',
    '#prefix' => '<div>',
    '#suffix' => '</div>',
  );

  return system_settings_form($form);
}

/**
 * Implements hook_validate().
 */
function aes_encryption_config_validate($form, &$form_state) {
  variable_set('aes_encryption_cipher', $form_state['values']['cipher']);
  variable_set('aes_encryption_key', $form_state['values']['key']);
}
