#include <stdio.h>
int multiply(int arr1[3][3],int arr2[3][3],int arr3[3][3]);

int main() {
    int A[3][3], B[3][3], C[3][3];

   
    printf("Enter the elements of the first matrix (A):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    
    printf("Enter the elements of the second matrix (B):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = 0;
        }
    }
    multiply(A,B,C);
}
int multiply(int arr1[3][3],int arr2[3][3],int arr3[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                arr3[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    
    printf("Multiplication of matrix A and B is:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
}