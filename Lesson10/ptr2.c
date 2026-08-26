#include <stdio.h>

void incr(int *p) {
  printf("Before incr: %d\n", *p);
  *p = *p + 1;
}
void printstr(char *p) {
  while(*p != 0) {
    putchar(*p);
    p++;
  }
  putchar('\n');
}

int main(void) {
  // x essendo una variabile locale dovrebbe essere solo visibile nel main
  int x = 5;
  int *y = &x;
  // Questo è un puntatore ad un puntatore di una variabile di tipo intero
  int **z = &y;
  // Tutti i puntatori saranno sempre dei numeri della dimensione del bus di indirizzi 
  // del processore

  printf("x is stored in %p and its value is %d\n", y, x);
  printf("x is stored in %p and its value is %d\n", &x, x);
  printf("x is stored in %p and its value is %d\n", &x, *y);
  printf("x is stored in %p and y is stored in %p\n", y, z);
  // la parentesi col tipo è il casting che dice al valore di ritorno alla destra della 
  // parentesi di essere convertita in tipo intero in questo caso
  printf("%d %d %d\n", (int)sizeof(x), (int)sizeof(y), (int)sizeof(z));

  *y = 10;
  printf("x now is: %d\n", x);

  incr(y);
  incr(&x);
  printf("x now is: %d\n", x);

  printf("\n/**********/\n");
  printf("/* String */\n");
  printf("/**********/\n\n");

  char mystr[] = "Hello World";

  // Questo p può contenere l'indirizzo di memoria di un carattere
  // Scrivere = &mystr sarebbe un errore perché il nome stesso dell'array è il puntatore
  // all'array
  char *p = mystr; 

  printf("At %p I can see: %s\n", mystr, mystr);
  printf("At %p I can see: %s\n", p, p);

  // Con *p posso accedere solo al primo degli elementi a meno che non faccia la somma
  // di puntatori, mentre con la notazione con le quadre, scelgo io a quale elemento accedere
  printf("%c%c\n", p[0], p[1]);
  printf("%c%c\n", *p, *(p+1));

  {
    char mystr[] = "AABBCCDDEEFF";
    short *p = (short*)mystr;
    // output: 16705 che è AA (65 e 65) nel numero a 16 bit che rappresentano
    printf("%d\n", *p);
    // Questo incremento ha spostato avanti di uno short e non di un carattere
    // Cioè l'incremento di 1 viene moltiplicato per la grandezza del tipo del puntatore
    p++;
    printf("%d\n", *p); // output: 16962 
    p += 3;
    printf("%d\n", *p); // output: 17733
    // Si può scrivere anche printf("%d\n", p[4]); // output: 17733 
  }

  {
    char mystr[] = "AABBCCDDEEFF";
    char *p = mystr;
    printf("At the beginning p is %p\n", p);
    printstr(p);
    printstr(mystr);
    printstr(mystr+3);
    printf("At the end p is %p\n", p);
  }
  return 0;
}