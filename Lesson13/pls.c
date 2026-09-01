#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> // Per avere tipi come uint32_t, uint16_t

/* Initialize a prefixed length string with the specified 
 * string in 'init' of length 'len'
 *
 * Warning: this function does not check for buffer overflows. */
void ps_init(char *s, char *init, int len) {
  unsigned char *lenptr = (unsigned char*)s;
  *lenptr = len;
  for (int j = 0; j < len; ++j) {
    s[j+1] = init[j];
  }
}

/* Display the string 's' on the screen. */
void ps_print(char *s) {
  uint32_t *lenptr = (uint32_t*)(s-4);
  for (int j = 0; j < *lenptr; ++j) {
    putchar(s[j]);
  }
  putchar('\n');
}


/* Initialize a prefixed length string with the specified 
 * string in 'init' of length 'len'
 *
 * The created strings have the following layout:
 *
 * +----+----+-----------\\\
 * |LLLL|CCCC|My string here
 * +----+----+-----------\\\
 *
 * Where LLLL is 4 byte stating the total length of the string.
 * Thus this strings are binary safe: zero bytes are permitted in the middle.
 *
 * Warning: this function does not check for buffer overflows. */
char* ps_create(char *init, int len) {
  char *s = malloc(4+len+1);
  uint32_t *lenptr = (uint32_t*)s;
  uint32_t *count = (uint32_t*)(s+4);
  *lenptr = len;

  s += 8;
  for (int j = 0; j < len; ++j) {
    s[j] = init[j]; // We should use memcpy() here.
  }
  s[len] = 0;
  // Cosi ritorniamo la stringa a partire da dove iniziano i caratteri,
  // salto i primi 4 byte della lunghezza
  return s;
}

/* Free a previously created PS string. */
void ps_free(char *s) {
  free(s-4);
}

/* Return the length of the string in O(1) time. */
uint32_t ps_len(char *s) {
  uint32_t *lenptr = (uint32_t*)(s-4);
  return *lenptr;
}

char *global_string;


int main(void) {
  char *mystr = ps_create("Hello WorldHello WorldHello World", 33);
  // Ho due variabili che puntano alla stessa stringa
  global_string = mystr;
  ps_print(mystr);
  ps_print(mystr);
  // Cast a int per non impelagarsi con gli specificatori di tipo per la
  // printf per uint32_t.
  printf("%s %d\n", mystr, (int)ps_len(mystr));
  // Dopo aver liberato la stringa, ho ancora la variabile global_string che 
  // punta alla stessa zona di memoria
  ps_free(mystr);
  // ps_free(mystr); // Il compilatore di C dovrebbero essere in grado di accorgersi
  // che non si può fare la free due volte della stessa variabile

  printf("%s\n", global_string);
  return 0;
}