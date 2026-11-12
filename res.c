
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main()
{
    AES_KEY enc_key, dec_key;

    unsigned char key[16] = "0123456789abcdef";

    unsigned char text[100] = {0};
    unsigned char encrypted[112] = {0};
    unsigned char decrypted[112] = {0};

    printf("Enter message: ");
    fgets((char *)text, sizeof(text), stdin);

    text[strcspn((char *)text, "\n")] = '\0';

    int len = strlen((char *)text);
    int padded = ((len + 15) / 16) * 16;

    // AES key setup
    AES_set_encrypt_key(key, 128, &enc_key);
    AES_set_decrypt_key(key, 128, &dec_key);

    // Encryption
    for(int i = 0; i < padded; i += 16)
        AES_encrypt(text + i, encrypted + i, &enc_key);

    printf("Encrypted: ");

    for(int i = 0; i < padded; i++)
        printf("%02X ", encrypted[i]);

    // Decryption
    for(int i = 0; i < padded; i += 16)
        AES_decrypt(encrypted + i, decrypted + i, &dec_key);

    decrypted[len] = '\0';

    printf("\nDecrypted: %s", decrypted);

    return 0;
}
