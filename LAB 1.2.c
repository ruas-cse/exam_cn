#include <stdio.h>
#include <string.h>
void main()
{
    char input[100];
    printf("give data bro: ");
    scanf("%s", input);
    int n = strlen(input);
    int partiy = 0;
    for (int i = 0; i < n; i++)
    {
        int k = input[i] - '0';
        if (k == 1)
        {
            partiy++;
        }
        else if (k != 0)
        {
            printf("why bro, Enter '0' or '1' only \n");
            return;
        }
    }
    char parity[2] = "";
    if (partiy % 2 == 0)
    {
        parity[0] = '0';
    }
    else
    {
         parity[0] = '1';
    }
    printf("data = %s\n", input);
    printf("Parity = %s\n", parity);
    strcat(input, parity);
    printf("data with parity is %s\n", input);
}




