#include <stdio.h>
#include <math.h>
void printMatrix(int m, int n, float matrix[m][n]); //Prints matrix
void inputMatrix(int m, int n, float matrix[m][n]); //Takes matrix input
void divideRow(int m, int n, float matrix[m][n], int row, float k); //Divides the given row by a scalar
void subtractRow(int m, int n, float matrix[m][n], int row1, int row2, float z); //To add/subtract rows
void interchangeRow(int m, int n, float matrix[m][n], int row1, int row2); //Interchange any two rows


int main()
{

    printf("---------------REF Form of a Matrix-------------\n");
    int m,n;
    printf("Enter rows :\t");
    scanf("%d", &m);
    printf("Enter cols :\t");
    scanf("%d", &n);
    float matrix[m][n];
    inputMatrix(m,n, matrix);
    printf("\nOriginal Matrix : \n");
    printMatrix(m,n, matrix);

    int col = 0; //column of the matrix with which the code would operate
    for (int r = 0; r < m; r++)
    {
        if (col >= n) {
            break; //Completed pivoting all columns
        }

        int i = r;

        //Find a non-zero pivot
        while (matrix [i][col] == 0)
        {
            i++;
            if (i == m) {
                i=r;
                col++;
                if (col == n) {
                    break;
                }
            }
        }
         if (col == n) {
                break;
            }

        // Swap current row (r) with the row containing the non-zero pivot (i)
        if (i != r) {
            printf("\nR%d swap R%d\n", r + 1, i + 1);
            interchangeRow(m,n, matrix, r, i);
            printMatrix(m,n,matrix);
        }

        // Make the leading entry in the current row 1 (optional but standard for RREF)
        float pivot = matrix[r][col];
        if ( pivot != 0 && pivot != 1) {
            printf("\nR%d = (1/%.2f)R%d\n", r+1, pivot, r+1);
            divideRow(m,n,matrix,r,pivot);
            printMatrix(m,n,matrix);
        }

        //Eliminate all the remaining entries in the column below pivot
        for (int i = r+1; i < m; i++)
        {
            if (matrix[i][col] != 0) {
                printf("\nR%d = R%d - (%.2f)*R%d\n", i + 1, i + 1, matrix[i][col], r + 1);
                subtractRow(m,n,matrix,i,r,matrix[i][col]);
                printMatrix(m,n,matrix);

            }
        }

        col++;

    }

    printf("\nRow Echelon Form (REF):\n");
    printMatrix(m, n, matrix);


    return 0;

}

void printMatrix(int m, int n, float matrix[m][n])
{
    printf("\n");
    for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        printf("%.2f\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(int m, int n, float matrix[m][n])
{
    for (int i = 0; i < m; i++) {
     for (int j = 0; j < n; j++) {
    printf("Enter a%d%d :\t", i+1, j+1);
    scanf("%f", &matrix[i][j]);
        }
    }
}

void divideRow(int m, int n, float matrix[m][n], int row, float k)
{
    for (int j = 0; j < n; j++) {
       matrix[row][j] /= k;
    }
}

void subtractRow(int m, int n, float matrix[m][n], int row1, int row2, float z) 
{ 
    for (int j = 0; j < n; j++) {
       matrix[row1][j] -= (z*matrix[row2][j]);}
}
   
void interchangeRow(int m, int n, float matrix[m][n], int row1, int row2) 
{
       for (int j = 0; j < n; j++) {
     matrix[row1][j] += matrix[row2][j];
     matrix[row2][j] = matrix[row1][j] - matrix[row2][j];
     matrix[row1][j] -= matrix[row2][j];
       }
}
   
   