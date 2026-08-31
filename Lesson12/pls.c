#include <stdio.h>
#include <stdlib.h>

/* Initialize a prefixed length string with the specified 
 * string in 'init' of length 'len'
 *
 * Warning: this function does not check for buffer overflows. */
void ps_init(char *s, char *init, int len) {
  // lenptr è sempre l'indirizzo di memoria a cui punta s ma con un tipo diverso
  unsigned char *lenptr = (unsigned char*)s;
  *lenptr = len;
  for (int j = 0; j < len; ++j) {
    s[j+1] = init[j];
  }
}

/* Display the string 's' on the screen. */
void ps_print(char *s) {
  unsigned char *lenptr = (unsigned char*)s;
  for (int j = 0; j < *lenptr; ++j) {
    putchar(s[j+1]);
  }
  putchar('\n');
}


/* Initialize a prefixed length string with the specified 
 * string in 'init' of length 'len'
 *
 * The created strings have the following layout:
 *
 * +-+-----------\\\
 * |L|My string here
 * +-+-----------\\\
 *
 * Where L is one unsigned byte stating the total length of the string.
 * Thus this strings are binary safe: zero bytes are permitted in the middle.
 *
 * Warning: this function does not check for buffer overflows. */
char* ps_create(char *init, int len) {
  // La memoria allocata con malloc è ancora valida quando la funzione ritorna perché
  // con malloc la memoria rimane valida finché non viene chiamata la free
  char *s = malloc(1+len+1);
  unsigned char *lenptr = (unsigned char*)s;
  *lenptr = len;
  for (int j = 0; j < len; ++j) {
    s[j+1] = init[j];
  }
  s[len+1] = 0;
  return s;
}

/* Return the pointer to the null terminated C string embedded 
 * inside our PS string 's'. */
char* ps_getc(char *s) {
  return s+1;
}

int main(void) {
  char buf[256];
  ps_init(buf, "Hello\000 World", 12);
  ps_print(buf);
  ps_print(buf);

  {
    char *mystr = ps_create("Hello WorldHello WorldHello World", 33);
    ps_print(mystr);
    ps_print(mystr);
    // Questa funzione qui non funzionerà correttamente perché il primo carattere è la 
    // lunghezza della stringa che però verrà stampata
    printf("%s\n", mystr);
    // La funzione scritta invece stampa correttamente la stringa
    printf("%s\n", ps_getc(mystr));
    free(mystr);
  }
  return 0;
}