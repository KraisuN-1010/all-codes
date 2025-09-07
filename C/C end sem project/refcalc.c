
// Online C compiler to run C program online
#include <stdio.h>
void printMatrix(int m, int n, float matrix[m][n]);
 void rowMultiply(int row, int m, int n, float matrix[m][n], float k);
 void addRow(int m, int n, float matrix[m][n], int row1, int row2, float alpha);

int main() {
    float a, b, c, d;
   printf("Enter a : ");
   scanf("%f",&a);
   printf("Enter b : ");
   scanf("%f",&b);
   printf("Enter c : ");
   scanf("%f",&c);
   printf("Enter d : ");
   scanf("%f",&d);
   
   int m = 2; 
   int n = 2;
   
   float matrix[2][2]={{a, b},{c, d}};
   printMatrix(m,n, matrix);
   rowMultiply(0, m, n, matrix, a);
   printMatrix(m, n, matrix);
   
   if (a*c < 0)
   {
       addRow(m, n, matrix, 1, 0, a);
       printMatrix(m, n, matrix);
   }
   else if (a*c > 0)
   {
       addRow(m, n, matrix, 1, 0,-c);
       printMatrix(m, n, matrix);
   }
   
   rowMultiply(1, m, n, matrix, matrix[1][1]);
   printMatrix(m, n, matrix);
   
    return 0;
}

void printMatrix(int m, int n, float matrix[m][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            printf("%.1f   ", matrix[i][j]);
        } printf("\n");
    }
}
    
  void rowMultiply(int row, int m, int n, float matrix[m][n], float k) {
      for (int j = 0; j < n; j++) {
          matrix [row][j] /= k;
      }
    
}

void addRow(int m, int n, float matrix[m][n], int row1, int row2, float alpha) {
    for (int j = 0; j < n; j++) {
        matrix[row1][j] += (alpha*matrix [row2][j]);
    }
}