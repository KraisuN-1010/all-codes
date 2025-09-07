#include<stdio.h>
#include<string.h>
int main(){
    char tctac[][50]={"__","|"}
    ;
    for(int j=0;j<3;j++){
        if(j==2){
            for(int k=0;k<2;k++){
                printf("  ");
                printf("%s",tctac[1]);
                
            }
            break;
        }
        for(int i=0;i<3;i++){
            
            printf("%s",tctac[0]);
            if(i==2){
                break;
            }
            printf("%s",tctac[1]);
            
        }
        printf("\n");
    }
    
    

}