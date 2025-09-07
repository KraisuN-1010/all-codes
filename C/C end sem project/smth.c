#include<stdio.h>
void main(){
    for(int i=6;i<20;i++){
        switch(i){
            case 0:i+=4;
            break;
            case 10:i+=2;
            case 5:i+=5;
            default:i+=4;
        
        }
        printf("%d\n",i);
    }
}
// void main(){
//     int i=0;
//         switch(i){
//             case 0:i+=5;
//             case 1:i+=2;
//             case 5:i+=5;
//             default:i+=4;

//         }
//         printf("%d\n",i);

// }