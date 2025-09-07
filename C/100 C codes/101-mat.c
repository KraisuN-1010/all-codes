#include<stdio.h>
int store(int,int,int arr[2][2],int arr1[3][3]);

int main(){
    int arr[2][2];
    int x,y;
    int main_arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int u=1;
    int sum=0;
    for(int y=0;y<3;y++){
        store(y,1,arr,main_arr);
        u=main_arr[y][1]*((arr[0][0]*arr[1][1])-(arr[0][1]*arr[1][0]));
       
        if(y==1){
            sum=sum-u;
        }
        else{
            sum+=u;
        }
    }
    
    printf("\n%d",sum);  
}
int store(int a,int b,int arr[2][2],int arr1[3][3]){ 
    int k=0,l=0;
    for(int i=0;i<3;i++){   
        if(i==a){
            continue;
        }
        l=0;
        for(int j=0;j<3;j++){   
            if(j==b){
                continue;
            }
            arr[k][l]=arr1[i][j];
            l++;
        }
        k++;
    }
   
}

    
