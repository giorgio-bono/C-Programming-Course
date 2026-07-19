#include <stdio.h>

// Definizione di una variabile globale: esisterà per tutto il tempo in cui il programma continua a girare
// Fino a quando il processo esiste, continua ad esistere
// int x = 0;

// Questa funzione non ritorna niente e non prende niente come input
// Questa funzione non processa dati perché non prende dati esterni e non ne restituisce
// Quindi non ha nessun effetto dal punto di vista della programmazione funzionale
// void incr(void) {
//   // Dichiara la variabile x e la inizializza a 1
//   // int x = 1;

//   // Variabile globale ma che viene vista solo dalla funzione incr
//   // La variabile è globale dal punto di vista della sua vita ma è locale dal punto di vista della visibilità (si vede solo in incr)
//   static int x = 0;

//   // Un solo = è trasferimento del valore a destra a sinistra
//   // Se non trova una variabile locale chiamata x, cerca tra le variabili globali
//   x = x + 1;
//   printf("%d\n", x);
// }

// In C gli argomenti vengono passati alle funzioni per default per valore e non per riferimento: gli viene data una copia e non un riferimento
int incr(int x) {
  // Questa variabile x ha il valore di a ma non è a quindi se incremento x, non incremento a, sono due variabili locali diverse
  x = x + 1;
  return x;
}

int main(void) {
  // incr();
  // incr();
  // incr();
  // incr();
  // la printf("%d", x); con static int x = 0; non funzionerebbe perché il main non vede x, la vede solo incr
  
  // intero positivo o negativo
  int a = 10;
  // intero senza segno
  unsigned int b = 20;
  // I float è standard in tutti i linguaggi di programmazione solitamente fp32 mentre i double sono a 64 bit fp64
  // La rappresentazione è formata da mantissa ed esponente e permette di rappresentare numeri molto piccoli e molto grandi
  float y = 1.234;
  // tipo di intero più piccolo da -128 a + 127 (un byte/8 bit)
  char c = 127;
  // Nelle espressioni i numeri più piccoli di int vengono convertiti in int e cosi non ho problemi di overflow con c
  // Altri linguaggi con regole più ferree non permettono espressioni tra variabili di tipo diverso
  int i = c + 1;
  // Incremento la variabile c
  c++;
  unsigned char uc = 254;
  uc++; printf("%d\n", uc);
  // Qua dovrebbe valere 256 e quindi dovrebbe andare in overflow e invece ho la garanzia che torna a 0
  uc++; printf("%d\n", uc);
  // short è da 16 bit/2 byte
  short s = 234;

  // Il valore di ritorno di incr viene ignorato
  incr(a);
  // Sta volta a sarà 11
  a = incr(a);

  printf("%d %.3f\n", a, y);

  // Se metto un float dove va int e viceversa mi becco dei warning ma tutto compila comunque anche se si vedono dei valori sbagliati
  // ma il C permette comunque di compilare e eseguire
  printf("%d %.3f\n", y, a);

  // Il C ha delle regole di promozione automatiche: se passo ad una funzione variatica un numero intero che è più piccolo di un int (e.g. short),
  // il C lo converte a int prima di passarlo alla funzione printf
  // La conversione implicita dei float è a double
  printf("%d %.3f\n", s, y);

  // In C il wrapping con overflow è garantito solo negli interi con segno, per quelli senza segno no, è un undefined behavior
  printf("%d %.3f\n", c, y);

  printf("%d %.3f\n", i, y);
  return 0;
}