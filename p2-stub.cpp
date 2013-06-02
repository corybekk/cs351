#include <iostream>
#include "p2-stub.h"

using namespace std;

// Your basic matrix multiply
void matmult0(float** A, float** B, float** C);

// Row and column traversals of a 2D array
void traverse_row(float** a);
void traverse_column(float ** a);

// Use this to check the correctness of your
// matmult code
void check_matmult(float** a, float** b, float** c);

int main() {
 /* Need to dynamically allocate these matrices
  * because they are too large for the stack.
  *
  * To dynamically allocate a 2D matrix,
  * you start by allocating an array of pointers...
  */  
    float** a = new float*[DIM];
    float** b = new float*[DIM];
    float** c = new float*[DIM];

  /* ...and then you dynamically allocate
   * an array of floats to each of those pointers
   */
    for (int i=0; i < DIM ; i++) {
        a[i] = new float[DIM];
        b[i] = new float[DIM];
        c[i] = new float[DIM];
    }

   /* Call ONE of the following functions: */
   // traverse_row(a);
   // traverse_column(a);
   matmult0(a, b, c);
   // matmult1(a, b, c);
   // matmult2(a, b, c);
   // matmult3(a, b, c);
   // matmult4(a, b, c);

   // Use this to check your matrix multiply correctness
   //check_matmult(a, b, c);

   return 0;
}

/* Multiply C = B * A 
 * Don't change this one */
void matmult0(float** A, float** B, float** C) {
   // First: initialize C to 0
   for (int i = 0; i < DIM; i++)
       for (int j=0; j < DIM; j++)
           C[i][j] = 0;
   for (int i = 0; i < DIM; i++)
       for (int j=0; j < DIM; j++)
          for (int k=0; k < DIM; k++)
              C[i][j] += A[i][k] * B[k][j];
}


/* Traverse the array by rows */
void traverse_row(float ** a) {    
    for (int i=0; i < DIM; i++)
      for (int j=0; j < DIM; j++)
            a[i][j] = 2 * a[i][j];
}

/* Traverse the array by columns */
void traverse_column(float ** a) {    
    for (int j=0; j < DIM; j++)
      for (int i=0; i < DIM; i++)
            a[i][j] = 2 * a[i][j];
}

/* Check the correctness of a matmult function
 * Parameters: A and B (the two matrices to multiply)
 *    and C (the "result" matrix)
 * Will call matmult0 to recompute the result
 * and compare it to C.
 */
void check_matmult(float** a, float** b, float** c) {
    bool correct = true;

    float** d = new float*[DIM];
    for (int i=0; i < DIM; i++)
        d[i] = new float[DIM];
    matmult0(a, b, d); // get correct result
    for (int i=0; i < DIM; i++)
       for (int j=0; j < DIM; j++)
           if (c[i][j] != d[i][j]) correct = false;

    cout << "Correctness checker result: " << correct << endl;
}        
