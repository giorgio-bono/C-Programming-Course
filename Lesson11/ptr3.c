#include <stdio.h>

/*
 * |76543210| 
 *  00010110  Numero a 8 bit (char)
 *
 *
 *  01 01 Essendo in esadecimale, ogni coppia vale un valore da 0 a 255 e se messi assieme
 *        devo moltiplicare la seconda coppia per 256
 */

int main(void) {
  char str[] = "aabb";
  short *s = (short*)str;
  printf("%d %d\n", s[0], s[1]);

  {
    char str[] = {1, 1, 2, 2};
    short *s = (short*)str;
    printf("%d %d\n", s[0], s[1]);
  }

  {
    // \000 è il carattere ascii 0 in ottale e quindi quando lo incontra il ciclo si ferma
    // \017 è il numero 15 in base 8
    // Questa è una prefixed length string: una stringa dove non ho il null term alla fine
    // Ma ho la lunghezza della stringa come primo carattere
    char str[] = "\017Hello00\000000123";
    char *p = str;
    printf("My string len is %d\n", p[0]);

    // Prendo il primo valore di p e poi incremento p
    int len = *p++;
    // Fino a quando ho un valore che non è zero, sto dentro al ciclo
    while(*p) {
      putchar(*p);
      p++;
    }
    putchar('\n');

    p = str;
    while(*p) {
      printf("%d ", *p);
      p++;
    }
    putchar('\n');

    p = str;
    for (int j = 0; j < len; ++j) {
      putchar(p[j]);
    }
    putchar('\n');
  }
}