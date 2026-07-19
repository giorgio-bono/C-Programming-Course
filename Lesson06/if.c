#include <stdio.h>

int main(void) {
  int i = 2;

  if (i > 3) {
    printf("i > 3\n");
  } else {
    printf("i <= 3\n");
  }

  if (i == 3) printf("i == 3\n");

  // Questo è un blocco, le variabili definite al suo interno non sono visibili al suo esterno
  {
    int i = 5;
    printf("i is %d\n", i);
    // %p è usato per i puntatori
    printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);
  }

  {
    int i = 5;
    printf("i is %d\n", i);
    // Viene riciclato lo stesso puntatore
    printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);
  }

  // Non posso avere questa riga di codice se non ho anche una i fuori perché a è locale al blocco precedente
  printf("i is %d\n", i);
  // Questo secondo i è salvato a 4 byte di distanza dall'altro i
  printf("i (%zu bytes) is stored at %p\n", sizeof(i), &i);
  
  return 0;
}