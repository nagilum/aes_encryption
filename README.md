# aes_encryption (AES Encryption)

This module provides easy functions to encrypt and decrypt data using the AES (rijndael) algorithm.

The two main functions aes_encryption_encrypt and aes_encryption_decrypt, shorthanded by aes_encrypt and aes_decrypt, are easy to call, and as default only requires the data to encrypt/decrypt.

With both functions you can provide your own cipher, key, and initialization vector. If no key and IV is specified, the default key is loaded from the Drupal variable-system. If no key is found in the Drupal system, a new key is automatically generated and stored there, encrypted of course.

You can also specify if the encrypted data is to be base64encoded, for ease of transport. By default both the encryption and decryption functions assumes the data is to be/is base64 encoded.
