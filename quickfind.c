#include <stdio.h>

int Particione (int A[], int p, int r) {
   int x = A[r];
   int i = p - 1;
   int j;
   for (j = p; j <= r - 1; j++) {
      if (A[j] <= x) {
          i += 1;
          int tmp = A[j];
          A[j] = A[i];
          A[i] = tmp;
      }
   }
   A[r] = A[i + 1];
   A[i + 1] = x;
   return i + 1;
}

void QuickFind (int A[], int p, int r, int k) {
  if (p <= r) {
     int q = Particione (A, p, r);
     if (q == k) {
        printf("Elemento: %d\n", A[q]);
        return; 
     }
     else if (q < k)
            QuickFind (A, q+1, r, k); 
     	  else
            QuickFind (A, p, q-1, k);
  }
}


int main (){
    int i, p = 0, r = 7;

    int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
 
    printf("Elementos de entrada: \n");
    for (i = 0; i <= r; i++) {
       printf("%d ", A[i]);
    }

    QuickFind (A, p, r, 7);
    
    printf("\n");
    return 0;
}
