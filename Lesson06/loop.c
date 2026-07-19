#include <stdio.h>

// Funzione ricorsiva
void count(int start, int end) {
  printf("%p %p\n", &start, &end);
  if (start > end) return;
  printf("%d\n",start);
  count(start+1, end);
}

int main(void) {
  int i = 0;

again:
  printf("%d\n", i);
  i++;
  if (i < 10) goto again;

  i = 0;

  while (i < 10) {
    printf("%d\n", i);
    i++;
  }

  i = 0;
loop:
  // if (!(i >= 10)) goto next;
  if (i >= 10) goto next;
  printf("%d\n", i);
  i++;
  goto loop;

next:

//   i = 0;
// loop:
//   if (i >= 10) goto enter_loop;
//   goto next;
// enter_loop:
//   printf("%d\n", i);
//   i++;
//   goto loop;

// next:

  count(0, 9);

  // l10: printf("ciao\n");
  // l20: goto l10;

  return 0;
}