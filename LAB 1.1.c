#include <stdio.h>
#include <string.h>

void main()
{
    char bit_stream1[10], bit_stream2[10], bit_stream3[10], bit_stream4[10], bit_stream5[10];
    char *streams[] = {bit_stream1, bit_stream2, bit_stream3, bit_stream4, bit_stream5};
    char col_parities[5] = {0, 0, 0, 0, 0};
    char row_parities[7] = {0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 5; i++)
    {
        printf("enter the bit stream %d (max 7 bits): ", i + 1);
        scanf("%9s", streams[i]);
        printf("you entered %9s\n", streams[i]);
        if (strlen(streams[i]) > 7)
        {
            printf("max 7 bits ");
            return;
        }
        int k = strlen(streams[i]);
        for (int j = 0; j < k; j++)
        {
            if (streams[i][j] - '0' == 1)
            {
                col_parities[i]++;
                row_parities[j]++;
            }
            else if (streams[i][j] - '0' != 0)
            {
                printf("enter only '0' or '1' please ");
            }
        }
    }
    char row_par[10] = "";
    int par = 0;
    for (int i = 0; i < 7; i++)
    {
        if (row_parities[i] % 2 == 0)
        {
            (strcat(row_par, "0"));
        }
        else
        {
            strcat(row_par, "1");
            par++;
        };
    }

    for (int i = 0; i < 5; i++)
    {
        (col_parities[i] % 2 == 0) ? (strcat(streams[i], "0")) : (strcat(streams[i], "1"));
        printf("data = %.7s,column parity = %c \n", streams[i], streams[i][7]);
    }

    ((par % 2 == 0) ? (strcat(row_par, "0")) : (strcat(row_par, "1")));
    printf("row parities  = %.7s,column parity of row parity = %c \n", row_par, row_par[7]);
    printf("final transmitted data is\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s", streams[i]);
    }
    printf("%s", row_par);
    printf("\n");
}


