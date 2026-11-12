
#include <stdio.h>
#include <string.h>

int main()
{
    char data[100], gen[20], msg[120];
    int i, j, n, len;

    printf("Enter data bits: ");
    scanf("%s", data);

    printf("Enter generator: ");
    scanf("%s", gen);

    n = strlen(gen);
    len = strlen(data);

    strcpy(msg, data);

    // Append zeros
    for(i = 0; i < n-1; i++)
        msg[len+i] = '0';

    msg[len+n-1] = '\0';

    // XOR division
    for(i = 0; i < len; i++)
    {
        if(msg[i] == '1')
        {
            for(j = 0; j < n; j++)
            {
                msg[i+j] = (msg[i+j] == gen[j]) ? '0' : '1';
            }
        }
    }

    printf("CRC Remainder: ");
    for(i = len; i < len+n-1; i++)
        printf("%c", msg[i]);

    printf("\nTransmitted Code: %s", data);

    for(i = len; i < len+n-1; i++)
        printf("%c", msg[i]);

    return 0;
}
