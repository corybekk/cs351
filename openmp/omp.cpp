#include <cstdlib>
#include <iostream>
#include <omp.h>
#define NUM_THREADS 4
using namespace std;

const int LARGENUM = 10000000;
//const int LARGENUM = 100;  // test the small version first

void InitArray(int* arr);
void PrintArray(int* arr); 
void IncrementElements(int* arr_src, int* arr_dst);
int FindMaxElement(int* arr);

bool spawned[NUM_THREADS];

int main( ) {

  omp_set_num_threads(NUM_THREADS);
  
  #pragma omp parallel for
  
  for(int i = 0; i<NUM_THREADS; i++){
    spawned[i] = false;
    
  }

   int* A = new int[LARGENUM];
   int* B = new int[LARGENUM];

   InitArray(A);
   cout << "Original array = \n";
   //PrintArray(A);

   IncrementElements(A, B);
   cout << "Incremented array = \n";
   //PrintArray(B);

   int max_element = FindMaxElement(A);
   cout << "Max = " << max_element << endl; 
   
   
 
   for(int i = 0; i  < NUM_THREADS; i++){
     cout << spawned[i] << endl;
   }
  
   delete [] A;
   delete [] B;
  
   
}

void InitArray(int* arr) {
  #pragma omp parallel for  
 for (int i=0; i < LARGENUM; i++)
      arr[i] = rand() % 1000;
 //arr[i] = true;
}

void PrintArray(int* arr) {
   for (int i=0; i < LARGENUM; i++)
      cout << arr[i] << '\t';
   cout << endl;
}


void IncrementElements(int* arr_src, int* arr_dst) {
  #pragma omp parallel for 
  for (int i=0; i < LARGENUM; i++){
      arr_dst[i] = arr_src[i]+1;
      spawned[omp_get_thread_num()] = true;
      //cout << omp_get_thread_num() << endl;
  }

}
 
int FindMaxElement(int* arr) {
   int max = arr[0];
   for (int i=1; i < LARGENUM; i++)
      max = max > arr[i] ? max : arr[i];
   return max;
}
