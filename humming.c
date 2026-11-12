
#include <stdio.h>

int main()
{
    int a[8], i, error;
    int s1, s2, s4;

    printf("Enter 4 data bits: ");

    for(i = 1; i <= 7; i++)
        a[i] = 0;

    scanf("%d%d%d%d", &a[3], &a[5], &a[6], &a[7]);

    // Calculate parity bits
    a[1] = a[3] ^ a[5] ^ a[7];
    a[2] = a[3] ^ a[6] ^ a[7];
    a[4] = a[5] ^ a[6] ^ a[7];

    printf("Hamming Code: ");

    for(i = 1; i <= 7; i++)
        printf("%d", a[i]);

    printf("\nEnter received 7 bits: ");

    for(i = 1; i <= 7; i++)
        scanf("%d", &a[i]);

    // Calculate syndrome
    s1 = a[1] ^ a[3] ^ a[5] ^ a[7];
    s2 = a[2] ^ a[3] ^ a[6] ^ a[7];
    s4 = a[4] ^ a[5] ^ a[6] ^ a[7];

    error = s1 + (s2 * 2) + (s4 * 4);

    printf("Error Position: %d\n", error);

    if(error != 0)
    {
        a[error] = a[error] ^ 1;
        printf("Error Corrected\n");
    }
    else
        printf("No Error\n");

    printf("Corrected Code: ");

    for(i = 1; i <= 7; i++)
        printf("%d", a[i]);

    return 0;
}
