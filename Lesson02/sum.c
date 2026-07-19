#include <stdio.h>

// La funzione sum ritorna un intero e prendere come input un intero a e un intero b
// int a e int b sono parametri mentre i valori 10 e 20 sono argomenti
int sum(int a, int b) {
  // return fa ritornare la funzione immediatamente al chiamante 
  return a + b;
}

// Usassimo questa funzione, il compilatore prima chiama ed esegue sum, e poi quando ho ottenuto il valore della somma,
// chiamo anche la printf, questo è anche visibile dal codice assembly di questo file C
// La funzione crea 3 variabili locali, a e b a cui vengono assegnati direttamente gli argomenti 
// int sum(int a, int b) {
//   c viene creato inizialmente vuoto
//   int c;

//   c = a + b;
//   In questo caso quando la funzione sum ritorna, vengono distrutte tre variabili locali: a (argomento), b (argomento), c (variabile locale d'appoggio)
//   return c;
// }

// int è il valore di ritorno che viene messo prima del nome della funzione
// tra le parentesi ci sono gli argomenti di input che la funzione main accetta
// Nel C moderno si può anche non scrivere niente
// main è il punto di partenza di ogni tipo di programma C che quindi non deve essere chiamata e deve essere sempre presente
int main(void) {
  // Definizione di variabili locali con anche inizializzazione
  int a = 10;
  int b = 20;
  // Inizializzazione tramite espressione
  int c = a + b;

  // Posso anche scrivere: prima creo le variabili
  // int a, b, c;

  // Non è più un'inizializzazione visto che non siamo nella definizione delle variabili
  // a = 10;
  // a = 11;
  // a = 5 + 7;
  // b = 20;
  // c = a + b;

  printf("Ciao: %d\n", c);
  // abbreviazione di print formatted: è una funzione variatica, cioè che prende un 
  // numero di argomenti di input variabile
  // Nel formato della stringa da printare, il %d ci dice che ci deve essere un intero
  // %d indica che a seguire ci deve essere un intero come argomento
  printf("Hello World! %d %d\n", sum(10, 20), 50);
  // Se non passo il numero di argomenti che è dato dal numero di %d, per problemi di memoria potrebbe stampare qualsiasi cosa

  // Nonostante c sia stato creato nella prima chiamata di sum da parte della prima printf, 
  // da quando viene fatto il return e viene ripassato il controllo alla funzione main, la variabile c non esiste più
  printf("Hello World! %d %d\n", sum(10, 20), 50);
  // Il valore di ritorno di main serve per segnalare al sistema operativo se il programma ha avuto buon esito o meno
  // 0 = esito positivo, valore diverso da 0 = ha avuto un problema e la sua esecuzione è fallita
  return 0;
}