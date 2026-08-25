#include <stdio.h>

void incr(int *p) {
  *p = *p + 1;
  // Analogia puntatori array
  p[0] = p[0] + 1;
}

int main(void) {
  int x = 5;
  // Puntatore ad un tipo intero, solo y è un puntatore, z è un intero
  // Un puntatore inizializzato a 0 è punta ad un indirizzo nullo.
  // y non è largo quanto un intero ma quanto un intptr_t, in questo caso 8 byte
  int *y = 0, z = 4;
  // int *y = NULL;
  printf("%d\n", x);
  printf("%p\n", y);

  /* L'operatore & prima del nome di una variabile significa 
   * non voglio il valore della variabile ma l'indirizzo di memoria
   * alla quale la variabile è registrata, il puntatore alla variabile */
  y = &x;
  printf("x is stored at the address: %p\n", y);

  /* Il puntatore punta all'indirizzo di memoria 10 */
  // y = 10;
  /* All'indirizzo di memoria contenuto in y, assegna il valore 10, per questo
   * serve dichiarare il tipo del puntatore, così siamo sicuri che la variabile 
   * puntata da y sia un intero e sono sicuro già durante la compilazione di non 
   * avere errori di tipo */
  *y = 10;
  // La riga precedente può essere scritta anche cosi y[0] = 10; visto che y
  // punta ad un solo valore
  printf("x now is: %d\n", x);

  incr(y);
  incr(&x);
  printf("x now is: %d\n", x);
  return 0;
}