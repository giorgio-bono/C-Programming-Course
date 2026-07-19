#include <stdio.h>

int main(void) {
  // char c = 10;
  // In C gli apici possono contenere un carattere singolo e verrà espanso al numero che rappresenta la posizione di quel carattere nello standard ascii
  // Anche quelli tra apici sono visti come interi, e il char è un tipo letterale
  char c = 'A'; // 65
  // Array di 5 elementi e si usano le graffe per inizializzare ai valori che io voglio
  int a[5] = {10, 5, 50, 100, 7};
  // Lo zero, chiamato terminatore nullo (null terminator), indica al C quando la stringa è finita, è un carattere speciale
  char str[6] = {'H', 'e', 'l', 'l', 'o', 0}; // La stringa è un array di interi di tipo char, 8 bit ciascuno
  // Anche lasciassi più spazio di quello che serve, il compilatore non darà warning
  char str2[8] = "hello"; // Possiamo dichiarare e inizializzare una stringa pure cosi
  // Posso anche non mettere niente e il compilatore capirà da solo il numero di caratteri
  char str3[] = "hello";
  str3[3] = 'X';
  str3[2] = 65;
  str3[2]++;
  // char x = 10;
  // char str4[] = {'a', 'b'};
  // char y = 20;
  // Il primo argomento è una stringa di formato: caratteri stampati cosi come sono, dei segnaposto che iniziano con la percentuale
  // che indicano cosa daremo alla printf come argomenti
  // Nelle funzioni con un numero di argomenti variabile i char e short vengono promossi al tipo intero
  printf("Hello World: %d\n", c); 
  // Anche la stringa è un tipo letterale
  printf("[%s]\n", "Hello World!"); 

  printf("[%c%c%c%c]\n", 65, 'B', 67, 68);

  printf("%d %d %d\n", a[0], a[1], a[2]);

  printf("%s\n", str);

  int i = 0;
  while(str[i] != 0) {
    printf("%c", str[i]);
    i++;
  }
  printf("\n");

  printf("%s World! %s\n", str, str2);
  // sizeof è un operatore che nel momento della compilazione (non accade a runtime), sostituisce la chiamata con la dimensione della variabile
  printf("sizeof: %lu\n", sizeof(str3));
  printf("%s\n", str3);
  // printf("%s\n", str4);
  return 0;
}