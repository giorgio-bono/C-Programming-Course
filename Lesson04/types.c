#include <stdio.h>
#include <limits.h>
// tipi avanzati del C per int
#include <stdint.h>

void clear(void) {
  // Esegue il comando clear di bash perché [H riporta il cursore in alto,
  // [2J cancella lo schermo visibile e [3J cancella lo scrollback mentre
  // \033 o \x1b indicano il carattere di escape (esc) in ottale e esadecimale
  printf("\033[H\033[2J");
  // printf("\x1b[H\x1b[2J\x1b[3J");
  // fflush(stdout);
}

int main(void) {
  // uint64_t, int64_t, size_t: tipo che può rappresentare una grandezza in base al target del processore che sta compilando il codice
  // intptr_t: intero della grandezza di un indirizzo di memoria (puntatore), con segno per poter sottrarre gli indirizzi di memoria
  // uintptr_t: intero senza segno della grandezza di un indirizzo di memoria (puntatore)
  char c = 1; // intero a 8 bit, 1 byte: modo in cui vengono rappresentate le stringhe
  short s = 2000; // 16 bit, 2 byte
  int x = 5; // 4 byte, 32 bit
  long l = 10; // 8 byte, 64 bit solitamente è della stessa grandezza della parola del microprocessore
  // Chiamata a funzione
  clear();
  // Questo Hello World è un insieme di tipi char
  printf("Hello World!\n");

  printf("Hello World: int is %d bytes!\n", (int)sizeof(x));
  printf("Hello World: int is %lu bytes!\n", sizeof(x));
  // Il preprocessore trasformerà INT_MIN nell'intero minimo che può essere processato in questa piattaforma dal tipo int
  printf("Hello World: int min: %d int max: %d\n", INT_MIN, INT_MAX);
  printf("Hello World: long is %lu bytes!\n", sizeof(l));
  return 0;
}