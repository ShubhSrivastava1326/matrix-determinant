//Expt. 5.5 - Write a C program to calculate the determinant of a matrix

#include <stdio.h>

int det(int n, int *M);
int cofactor(int i, int j, int n, int *M);
int Pow(int b, int e);

int main() {
  
// Input dimension of square matrix
  int n;
  printf("\nEnter dimension of square matrix: ");
  scanf("%d", &n);

// Default statement
  if (n==0) return 0;

// Fills matrix
  int M[n][n];
  printf("\nEnter matrix M:\n\n");
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      scanf("%d", &M[i][j]);

// Prints result
  printf("\nDeterminant = %d\n\n", det(n, &M[0][0]));

  return 0;
}

// Calculates determinant of a matrix
int det(int n, int *M) {
    
  if (n==1) return *M;  // singleton matrix: |a| = a
  if (n==2) return *M * *(M+3) - *(M+1) * *(M+2);  // base case: 2x2 determinant

  int Det=0;
  for(int i=0; i<n; i++)
    Det += *(M+i) * cofactor(0,i,n,M);  // D = sum of aij*Aij (1st row here)

  return Det;
}

// Calculates cofactor of an element in a matrix
int cofactor(int i, int j, int n, int *M) {
  
  int minor[n-1][n-1];             // Generates minor matrix for aij
    for (int k=0,r=0; k<n; k++) {
      if(k==i) continue;           // Excludes i'th row
      for (int l=0,c=0; l<n; l++) {
        if(l==j) continue;         // Excludes j'th column
        minor[r][c++] = *(M + k*n +l);
      }
      r++;
    }

  return Pow(-1,i+j)*det(n-1, &minor[0][0]);  // Aij = (-1)^(i+j)*Mij
}

// Exponent function
int Pow(int b, int e) {
  int pro=1;
  for(int i=0; i<e; i++) pro*=b;
  return pro;
}