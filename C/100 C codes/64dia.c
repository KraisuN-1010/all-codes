#include <stdio.h>
int main()
{
    int rows, i, s, j, ROWS, a;
    printf("Enter rows:");
    scanf("%d", &rows);
    i = 1;
    ROWS = rows;
    while (rows > 0)
    {
        s = rows;
        while (s > 0)
        {
            printf(" ");
            s--;
        }
        j = 2;
        while (j <= i)
        {
            printf("* ");
            j++;
        }
        printf("\n");
        i++;
        rows--;
    }
    i = ROWS;
    a = ROWS + 1;
    while (ROWS > 0)
    {
        j = 1;
        while (j <= i)
        {
            printf("* ");
            j++;
        }
        printf("\n");
        s = a - ROWS;
        while (s != 0)
        {
            printf(" ");
            s--;
        }
        i--;
       ROWS--;
}
}