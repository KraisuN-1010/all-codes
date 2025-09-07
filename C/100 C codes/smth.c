
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
    int arr[n];
    int a,b,c;
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    int max1=0;
    int max2=0;
    int max3=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            a=arr[i]&arr[j];
            b=arr[i]|arr[j];
            c=arr[i]^arr[j];
            if(a<k && max1<a ){
                max1=a;
            }
            if(b<k && max2<b){
                max2=b;
            }
            if( c<k && max3<c){
                max3=c;
            }
        }
        
    }
    printf("%d",max1);
    printf("%d",max2);
    printf("%d",max3);
    
  
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
