// #include<stdio.h>
// int main(){
//     int j;
//     int arr[]={1,2,3,4,5};
//     int size=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0;i<size;i++){
//         printf("Element %d is %d\n",i+1,arr[i]);
//     }
//     printf("Which element do you wanna delete:");
//     scanf("%d",&j);
//     arr[j]=0;
//     for(int i=0;i<size;i++){
//         printf("Element %d is %d\n",i+1,arr[i]);
//     }
// }
#include <stdio.h>
int main()
{
    int del[] = {5, 3, 4, 2, 1};
    int n;
    int new[4];
    for (int i = 0; i < 5; i++)
    {
        printf(" %d", del[i]);
    }
    printf("\nEnter the index that you want deleted:");
    scanf("%d", &n);
    int j = 0;
    for (int i = 0; i < 5; i++)
    {
        if (del[i] != del[n])
        {
            new[j] = del[i];
            j++;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        printf(" %d", new[i]);
    
}
}