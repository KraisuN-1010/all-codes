#include <stdio.h>
int checkprime(int);
int main()
{
    int n, i,x,a;
    printf("Enter first number.");
    scanf("%d", &a);
    printf("Enter second number:");
    scanf("%d",&n);
     i=a;
    while ( i < n)
    {
        int y = 2;
        while (y < i)
        {
            if (i % y == 0)
            {
                x = 0;
                break;
            }

            else
            {
                x = 1;
            }
            y++;
        }
        if(i==2){
            printf("%d ",i);
        }
        if (x == 1){
            printf("%d ", i);
        }
        
         i++;       
        
    }
}

