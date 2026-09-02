#include <stdio.h>
#include <stdint.h>
#include <stdlib.h> // malloc

struct pls {
  uint32_t len;
  uint32_t refcount;
  char str[0];
};

/* Internal layout; 
 *
 * +----+----+
 * |num |den |
 * +----+----+
 */
struct fract {
  int num;
  int den;
};

/* Internal layout; 
 *
 * +----+----+----+
 * |c   |num |den |
 * +----+----+----+
 * Questo dovrebbe essere 9 byte ma in realtà è di 12 perché le strutture
 * di default garantiscono che ogni membro della struttura sia registrato
 * ad un multiplo della dimensione del suo tipo. e.g. int sarà ad un multiplo
 * di 4. unsigned char sarà un byte di dato e 3 di padding. La struttura 
 * deve essere allineata al tipo più grande che c'è al suo interno.*/
struct fract_c {
  unsigned char color;
  int num;
  int den;
};

/* Internal layout; 
 *
 * +----+----+----+
 * |num |den |c   |
 * +----+----+----+
 * Anche questa ha la stessa dimensione, pur cambiando la posizione di c. */
struct fract2 {
  int num;
  int den;
  unsigned char color;
};

/* Internal layout; 
 *
 * +----+----+----+
 * |num |den |abcd|
 * +----+----+----+
 * Questo però è ancora 12 byte senza buchi lasciati in memoria. */
struct fract3 {
  int num;
  int den;
  unsigned char a;
  unsigned char b;
  unsigned char c;
  unsigned char d;
};

/* Internal layout; 
 *
 * +----+----+----+----+----+
 * |a   |num |b   |den |cd  |
 * +----+----+----+----+----+
 * Questo invece è 20 byte. */
struct fract4 {
  unsigned char a;
  int num;
  unsigned char b;
  int den;
  unsigned char c;
  unsigned char d;
};

void set_fraction(int *f, int num, int den) {
  f[0] = num;
  f[1] = den;
}

void print_fraction(int *f) {
  printf("%d/%d\n", f[0], f[1]);
}

void print_fraction_struct(struct fract *f) {
  printf("%d/%d\n", f->num, f->den);
}

/* Create a new fraction, setting num and den as the numerator
 * and denominator of the fraction.
 * The function returns NULL on out of memory, otherwise the 
 * fraction object is returned. */
int *create_fraction(int num, int den) {
  int *f = malloc(sizeof(int)*2);
  if(f == NULL) return NULL; // malloc error checking
  f[0] = num;
  f[1] = den;
  return f;
}

struct fract *create_fraction_struct(int num, int den) {
  struct fract *f = malloc(sizeof(struct fract)*2); // sizeof(*f)
  if(f == NULL) return NULL; // malloc error checking
  f->num = num;
  f->den = den;
  return f;
}

struct fract create_fraction_struct_no_pointer(int num, int den) {
  struct fract f;
  f.num = num;
  f.den = den;
  return f;
}

/* Simplify the provided fraction. */
void simplify_fraction(int *f) {
  for (int d = 2; d <= f[0] && d <= f[1]; ++d) {
    while (f[0] % d == 0 &&
           f[1] % d == 0) {
        f[0] /= d;
        f[1] /= d;
       }
  }
}

/* Simplify the provided fraction. */
void simplify_fraction_struct(struct fract *f) {
  for (int d = 2; d <= f->num && d <= f->den; ++d) {
    while (f->num % d == 0 &&
           f->den % d == 0) {
        f->num /= d;
        f->den /= d;
       }
  }
}


int main(void) {
// Modo per commentare un blocco di codice tramite il preprocessore del C
// che può avere delle condizionali e visto che 0 è sempre falso, è un commento
#if 0
  // Puntatore alla frazione (numeratore + denominatore)
  int *f1 = malloc(sizeof(int)*2);

  /* |1111|2222| 
   *  f[0] f[1] */

   set_fraction(f1, 1, 2);
   print_fraction(f1);

   int *f2 = create_fraction(3, 4);
   print_fraction(f2);

   set_fraction(f1, 10, 20);
   print_fraction(f1);
   simplify_fraction(f1);
   print_fraction(f1);
   return 0;
#endif

  printf("%d\n", sizeof(struct fract));
  // struct fract è il nome del tipo, a è il nome della variabile
  struct fract a;
  struct fract *b = &a; // Puntatore ad una struttura

  // Posso usare l'operatore . per accedere ai diversi campi della struttura
  a.num = 1;
  a.den = 2;
  printf("%d %d\n", a.num, a.den);

  // Quando uso i puntatori a struct si usa l'operatore -> per readability
  b->num = 3;
  b->den = 4;
  printf("%d %d\n", b->num, b->den);
  printf("%d %d\n", a.num, a.den);

  // Il problema di non tornare un puntatore a struttura ma una struttura,
  // fa si che il C va a fare un'operazione di copia dei byte dalla funzione
  // al main mentre con il puntatore non c'è nessuna copia implicita.
  struct fract f1 = create_fraction_struct_no_pointer(10, 20);
  struct fract f2 = create_fraction_struct_no_pointer(3, 4);

  simplify_fraction_struct(&f1);
  print_fraction_struct(&f1);
  print_fraction_struct(&f2);
  return 0;
}