// Direttiva del oreprocessore: include serve per predenre un file e aggiungerlo nel testo del file C qui presente
// Dentro stdio.h ci sono tutte le intestazioni di tutte le funzioni che vengono usate nel programma (e.g. printf)
// File di intestazione (header) al cui interno si trovano le funzioni che possiamo usare e i vari parametri
// I file .h contengono sempre sorgente C e lo posso includere in diversi file .c tramite il preprocessore
#include <stdio.h>

// Prototipo della funzione printf: Se uncommento questa riga e commento l'include tutto funziona comunque
// anche senza sapere il contenuto interno e come funziona la funzione, al compilatore basta sapere il prototipo
// int printf(const char * restrict format, ...);

int main(void) {
  // Al posto dell'include verrà messo il testo di file.c
  #include "file.c"
  // printf è una funzione che non è parte del linguaggio stesso ma definita nella libreria di C
  printf("Hello world!\n");
  return 0;
}