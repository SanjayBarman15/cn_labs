
#include <stdio.h>

int main()
{
    int n, i, j;
    int data[20], sum = 0, check;

    printf("Enter number of 8-bit blocks: ");
    scanf("%d", &n);

    printf("Enter decimal values of blocks (0-255): ");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &data[i]);
        sum += data[i];

        while(sum > 255)
            sum = (sum & 255) + (sum >> 8);
    }

    check = 255 - sum;

    printf("Checksum: ");

    for(i = 7; i >= 0; i--)
        printf("%d", (check >> i) & 1);

    printf("\n");

    // Receiver side
    sum += check;

    while(sum > 255)
        sum = (sum & 255) + (sum >> 8);

    if(sum == 255)
        printf("No Error Detected");
    else
        printf("Error Detected");

    return 0;
}
