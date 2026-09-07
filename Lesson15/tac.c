#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct line {
  char *s;
  // Puntatore allo stesso tipo che sto dichiarando che punta
  // al prossimo nodo della struttura
  struct line *next;
};

/* La main può ricevere un numero di argomenti/parametri
 * passati da command line e un array di stringhe che sono gli
 * argomenti che passo al mio programma. Il primo argomento
 * passato al programma è il nome del programma stesso. */
int main(int argc, char**argv) {
  for (int i = 0; i < argc; ++i) {
    printf("%d: %s\n", i, argv[i]);
  }

  if (argc != 2) {
    printf("Missing file name\n");
    return 1;
  }

  // fopen ha bisogno di 2 parametri, la stringa contenente il
  // nome del file e il metodo di apertura del file
  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL) { 
    printf("File does not exist\n");
  }

  char buf[1024];
  struct line *head = NULL;
  // fgets ritorna o NUll o il puntatore a buf
  while (fgets(buf, sizeof(buf), fp) != NULL) {
    struct line *l = malloc(sizeof(struct line));
    size_t linelen = strlen(buf);
    // strlen ritorna la lunghezza della stringa cercando il 
    // primo carattere a 0 che trova, + 1 per il terminatore
    l->s = malloc(linelen + 1);
    for (size_t j = 0; j <= linelen; ++j) {
      l->s[j] = buf[j];
    }
    l->next = head;
    head = l;
  }

  fclose(fp);

  while(head) {
    printf("%s", head->s);
    head = head->next;
  }
  return 0;
}