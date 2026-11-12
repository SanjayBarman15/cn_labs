
#include <stdio.h>
#include <string.h>
#include <openssl/des.h>

int main()
{
    DES_cblock key = "12345678";
    DES_key_schedule schedule;

    DES_set_key_unchecked(&key, &schedule);

    char text[100];
    char encrypted[100];
    char decrypted[100];

    printf("Enter message: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    int len = strlen(text);
    int padded = ((len + 7) / 8) * 8;

    char input[104] = {0};
    memcpy(input, text, len);

    // Encryption
    for(int i = 0; i < padded; i += 8)
    {
        DES_ecb_encrypt(
            (const_DES_cblock *)(input + i),
            (DES_cblock *)(encrypted + i),
            &schedule,
            DES_ENCRYPT
        );
    }

    printf("Encrypted: ");

    for(int i = 0; i < padded; i++)
        printf("%02X ", (unsigned char)encrypted[i]);

    // Decryption
    for(int i = 0; i < padded; i += 8)
    {
        DES_ecb_encrypt(
            (const_DES_cblock *)(encrypted + i),
            (DES_cblock *)(decrypted + i),
            &schedule,
            DES_DECRYPT
        );
    }

    decrypted[len] = '\0';

    printf("\nDecrypted: %s", decrypted);

    return 0;
}
