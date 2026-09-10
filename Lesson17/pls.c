#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

struct pls {
  uint32_t len;
  uint32_t refcount;
#ifdef PLS_DEBUG
  uint32_t magic;
#endif
  char str[]; 
};

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
  struct pls *p = s - sizeof(*p);
  for (int j = 0; j < p->len; ++j) {
    putchar(p->str[j]);
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
  struct pls *p = malloc(sizeof(struct pls) + len + 1);
  p->len = len;
  p->refcount = 1;
#ifdef PLS_DEBUG
  p->magic = 0xDEADBEEF;
#endif
  for (int j = 0; j < len; ++j) {
    p->str[j] = init[j]; 
  }
  p->str[len] = 0;
  return p->str;
}

/* Free a previously created PS string. */
void ps_free(char *s) {
  free(s - sizeof(struct pls));
}

/* Validate that a ps string looks valid */
void ps_validate(struct pls *p) {
  if (p->magic != 0xDEADBEEF) {
    printf("Invalid string: Aborting\n");
    exit(1);
  }
}

/* Drop the reference count of the string object by one
 * and frees the object if the refcount reached 0. */
void ps_release(char *s) {
  struct pls *p = (struct pls*)(s - sizeof(*p));
  ps_validate(p);
  p->refcount--;
  if (p->refcount == 0) {
    p->magic = 0;
    ps_free(s);
  }
}

/* Increase the reference count of the string object. */
void ps_retain(char *s) {
  struct pls *p = (struct pls*)(s - sizeof(*p));
  if (p->refcount == 0) {
    printf("Aborted on retain of illegal string\n");
    exit(1);
  }
  p->refcount++;
}

/* Return the length of the string in O(1) time. */
uint32_t ps_len(char *s) {
  struct pls *p = (struct pls*)(s - sizeof(*p));
  return p->len;
}

char *global_string;


int main(void) {
  char *mystr = ps_create("Hello WorldHello WorldHello World", 33);

  global_string = mystr;
  ps_retain(mystr);

  ps_print(mystr);
  printf("%s %d\n", mystr, (int)ps_len(mystr));
  ps_release(mystr);

  printf("%s\n", global_string);
  ps_release(mystr);
  // ps_release(mystr);
  return 0;
}