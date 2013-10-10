#include <stdio.h>

/*Algoritmo que faz uma busca no vetor simulando as funções do QuickSort*/

/*Função que particiona o vetor em pedaços, recebe o vetor, e as suas pontas(inicio e fim)*/
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

/*função que identifica o valor passado no vetor*/
void QuickFind (int A[], int p, int r, int k) {
  if (p <= r) {
     int q = Particione (A, p, r); /*divide o vetor em 2 e retorna uma "chave"*/
     if (q == k) { /*verifica se o valor de retorno é igual passado. Achou!*/
        printf("Elemento: %d\n", A[q]);
        return; 
     }
     else if (q < k) /*Se for menor percorre a direita do vetor*/
            QuickFind (A, q+1, r, k); 
     	  else /*Se for maior percorre a esquerda do vetor*/
            QuickFind (A, p, q-1, k);
  }
}


int main (){
   /*variáveis*/
    int i, p = 0, r = 7;
    int A[] = {7, 1, 3, 10, 17, 2, 21, 9};
 
    /*Mostra os elementos do vetor*/
    printf("Elementos de entrada: \n");
    for (i = 0; i <= r; i++) {
       printf("%d ", A[i]);
    }

    /*chamada da função*/
    QuickFind (A, p, r, 7);
    
    printf("\n");
    return 0;
}
