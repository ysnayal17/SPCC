#include <stdio.h>
#include <string.h>

int main()
{
    int rem, dec = 0, i = 1, tmp, j = 0, x;
    char hex[100];
    long int bin = 10000;
    while (bin != 0)
    {
        rem = bin % 10;
        dec = dec + rem * i;
        i = i * 2;
        bin = bin / 10;
    }
    printf("%d", dec);
    while (dec != 0)
    {
        tmp = dec % 16;
        if (tmp < 10)
        {
            hex[j] = tmp + 48;
            j++;
        }
        else
        {
            hex[j] = tmp + 55;
            j++;
        }
        dec /= 16;
    }
    printf("\n");
    for (x = strlen(hex) - 1; x > -1; x--)
    {
        printf("%c", hex[x]);
    }
    return 0;
}