#include <stdio.h>

// Funzione ricorsiva: vengono eseguite istruzioni con i parametri attuali e poi richiama se stessa con il resto della computazione ancora da fare
void count_vanilla(int start, int end) {
  if (start > end) return;
  printf("%d\n",start);
  count_vanilla(start+1, end);
}

void count(int start, int end) {
iterate:
  if (start > end) return;
  // In questo caso non usiamo memoria in più, è sempre al stessa funzione e le stesse variabili
  printf("%d %p \n",start, &start);
  start = start+1;
  goto iterate;
}

int main(void) {
  int i = 0;

  while (i < 10) {
    printf("%d\n", i);
    i++;
  }

  // Il for è possibile scriverlo anche uguale come ciclo while
  for (i = 0; i < 10; ++i) {
    printf("%d\n", i);
  }

  i = 0;
  // Siccome la variabile i era già dichiarata e inizializzata a 0, è possibile anche omettere l'inizializzazione
  for (; i < 10; ++i) {
    printf("%d\n", i);
  }

  i = 0;
  // È possibile anche omettere la condizione di test
  for (; ; ++i) {
    if (i >= 10) break;
    printf("%d\n", i);
  }

  i = 0;
  for (; ; ) {
    // Il break funziona bene per uscire da un ciclo annidato
    if (i >= 10) break;
    printf("%d\n", i);
    i++;
  }

  // Questo è un ciclo infinito che corrisponde anche ad avere for ( ; ; ). 1 perché la condizione è sempre vera
  // 0 = false, != 0 = true
  // while(1) {...}

  for (int j = 0; j < 10; ++j) printf("%d\n", j);
  // Questa riga da un errore di compilazione perché j non esiste al di fuori del blocco for
  // printf("%d\n", j);

  int a[] = {1, 5, 8, 4, 9, 0};
  for (i = 0; a[i] != 0; ++i) {
    if (a[i] == 8) break;
    printf("%d\n", a[i]);
  }
  if(a[i] == 0) printf("Non trovato\n");
  else printf("Trovato\n");

  // do {
  //
  // } while ();

  i = 5;
  // Nello switch non si possono dichiarare variabili a meno che non si crei un blocco
  switch (i) {
    case 5: printf("È un cinque\n"); // break;
    case 7: 
    {
      int j = 10;
      printf("È un sette (%d)\n", j); 
      break;
    }
    default: printf("Qualche altro numero\n"); break;
  }

  // Lo switch è come questo ma con in più il break, se non lo metto quando entro in un case, che può avere più
  // di un'istruzione,una volta finito, si entra nel case successivo finché non si trova un break. 
  // if (i == 5) {
  //   ...
  // } else if (i == 7) {
  //   ...
  // } else {

  // }

  // count(0, 9);
  return 0;
}