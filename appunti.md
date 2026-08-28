# Lesson 1
Il C è un linguaggio **compilato**.
Il programma .c non può essere eseguito in maniera diretta cioè cambiandogli i permessi da terminale con chmod. Per compilarlo devo usare il **compilatore C** che è un programma scritto in C.

## Comando per compilare il file
gcc <nome-file>
ritornerà a.out che potrà essere eseguito

## Comando per ottenere il file in linguaggio assembly
gcc -S <nome-file>
ritornerà nome-file.s

## Ottimizzazione di livello 2 
Ottimizzazione con stesso comportamento del linguaggio originale ma molto più ottimizzato
gcc -O2 -S <nome-file>

## puts vs printf
`printf` non scrive da solo il carattere a capo mentre `puts` si.

## Direttive del preprocessore in C
Le direttive del preprocessore iniziano col cancelletto. Prima di compilare il programma, il compilatore chiama un altro programma che spesso è parte del compilatore stesso o un programma distinto e processa le direttive. Viene compilata in una fase precedente alla compilazione dal preprocessore che fa come se fossero delle trasformazioni del testo, nel sorgente stesso del programma in C.

`include` serve per predenre un file e aggiungerlo nel file C in cui viene incluso per creare un nuovo file che è la somma del contenuto dei due.

Dentro `stdio.h` ci sono tutte le intestazioni di tutte le funzioni che vengono usate nel programma (e.g. printf). Ci sono tutte le funzioni della libreria standard di C che si occupano di input/output.
Il **file di intestazione** (header) è il file al cui interno si trovano le funzioni che possiamo usare e i vari parametri
I file **.h** contengono sempre sorgente C e lo posso includere in diversi file .c tramite il preprocessore

## Prototipo di una funziona
Il prototipo di una funzione serve per poter dire gli argomenti della funzione e il tipo di ritorno della funzione 

---

# Lesson 2: funzione sum, variabili locali
gcc -O2 -W -Wall <nome-file>
comando per compilare il file c in modo ottimizzato e controllare anche se ci sono warning tramite le due opzioni -W e -Wall che li abilitano

## printf
È l'abbreviazione di print formatted: è una funzione variatica cioè che prende un numero di argomenti di input variabile

`%d` indica che a seguire ci deve essere un intero come argomento

## Funzione main
`main` è il punto di partenza di ogni tipo di programma C che quindi non deve essere chiamata. Se al posto di main scrivessi una funzione con un nome diversa, otterremo un errore

## Le variabili in linguaggio C
Le variabili in C si devono dichiarare tutte e bisogna anche dichiarare il tipo. Non si può scrivere a = 10 e C capisce da solo l'inferenza di tipo cioè qual è il tipo della variabile. Vuole i tipi espliciti.
Nell'inizializzazione, l'assegnazione del valore viene fatto durante la definizione della variabile

### La variabile locale
La variabile locale viene creata quando la funzione viene chiamata, per tutto il tempo di esecuzione della funzione la variabile locale esiste e può essere usata. Quando la funzione ritorna, non ci sarà più la variabile.

## la keyword return
Il valore di ritorno di main serve per segnalare al sistema operativo se il programma ha avuto buon esito o meno

0 = esito positivo, valore diverso da 0 = ha avuto un problema e la sua esecuzione è fallita

Viene messo ad esempio un return a valore diverso da 0 e poi quando bisogna eseguire il codice viene eseguito con altri comandi in and (&&) perché in quel modo quando uno dei programmi in esecuzione del comando ritorna un valore diverso da zero, tutti i programmi successivi non verranno eseguiti.

## I microprocessori
I microprocessori hanno un set di registri (piccole variabili velocissime che possono contenere solo numeri, interi o virgola mobile, e sono dentro il core del processore) e delle istruzioni che muovono i contenuti di una data locazione della ram ad un registro o da un registro alla ram. I microprocessori CISC hanno anche un set di istruzioni molto ampio con anche istruzioni complicate. Queste sono le due modalità con cui il processore può salvare/caricare memoria.

---

# Lesson 3: funzione incr, variabili globali, statiche, passaggi per valore e altri tipi delle variabili

## Passaggi per valore e per riferimento
Gli argomenti passati ad una funzione sono passati per valore cioè sono copiati, anche nel caso si usasse il passaggio per riferimento, in realtà viene fatta una copia del puntatore.

## printf
Nella printf, %d è per gli interi, %f per i float, %x %X per i numeri in esadecimale visualizzati in minuscolo o maiuscolo rispettivamente, %lu per long unsigned int.

# Lesson 4: i tipi in C
Un dato tipo intero ha un determinato numero di bit, un valore minimo e massimo che sono fissi. 
Il C doveva essere compatibile con tutti i sistemi: da quelli a 8 bit a 64 bit.
Quindi l'int varia da piattaforma a piattaformama in entrambi i casi può rappresentare sia numeri positivi che negativi.

## Casting
Mettere prima di una qualsiasi espressione C, tra parentesi un tipo significa convertire l'espressione in quel tipo.

## printf e fflush
La printf invece di scrivere sul terminale, accumula in un buffer interno nella memoria fino a quando non vede un new line o finché non si vede fflush per ottimizzare le chiamate a i/o.

# Lesson 5
In C gli apici possono contenere un carattere singolo e verrà espanso al numero che rappresenta la posizione di quel carattere nello standard ascii

## Le stringhe
Lo zero, chiamato terminatore nullo, indica al compilatore C quando la stringa è finita

# Lesson 6

## if/else e blocchi
`!` è l'operatore logico `not` che nega la condizione dell'if, se una cosa è 0, la fa diventare 1, se una cosa è un numero diverso da 0, la fa diventare 0. Questo perché, come abbiamo detto più volte, il C gestisce solo numeri.
Il ramo else si può evitare. Il codice tra le graffe si chiama **blocco**.
Se all'interno del blocco if ho una singola istruzione, le graffe non sono obbligatoriamente necessarie.
*Le variabili dichiarate all'interno del blocco, non saranno visibili al suo esterno.*

È possibile creare un blocco anche senza l'if o qualsiasi altra keyword
```
  {
    <codice>
  }
```

Possiamo anche dichiarare due variabili con lo stesso nome ma in blocchi diversi e saranno viste come due variabili diverse. Anche nel caso in cui *un blocco sia dentro l'altro*, continueremo a avere due variabili diverse ma con lo stesso nome.

Le variabili vengono istanziate nello stack e liberate quando viene chiuso il blocco.

## Primo approccio con i puntatori con la printf
Nella printf per poter stampare nel terminale un puntatore uso `%p`. Mentre `%zu` è usato per `size_t`.

## goto keyword
```
etichetta:
  <codice>
  ...

  goto etichetta;
```
**L'etichetta deve iniziare con una lettera**.

## while loop
Il while è la struttura di ciclo che esegue un blocco di codice fin quando la condizione è vera.

## Funzione ricorsiva
È stata usata per non dover usare goto o while per creare un loop di conteggio. Ogni volta che viene richiamata la funzione, viene creato di nuovo lo stack frame e vengono creati nuovamente nuovi parametri.

# Lesson 7


# Lesson 9
Per dichiarare un puntatore devo aggiungere * prima del nome della variabile. Quindi la variabile si chiamerà solo col nome che troviamo successivamente ad *.
Un puntatore inizializzato a 0 è punta ad un indirizzo nullo.

# Lesson 10
Dato il puntatore `p`, le operazioni `*p` o `p[0]` si chiamano **deferenziazione di p**. Deferenziare significa accedere ad un valore attraverso il suo indirizzo di memoria, quest'operazione può essere fatta sia in lettura che in scrittura.
Il tipo ritornato dalla deferenziazione è relativo al modo in cui è stato dichiarato il puntatore.

# Lesson 12
I puntatori di tipo void sono puntatori a indirizzi di memoria generici che non sono legati ad alcun tipo di oggetto o struttura. Sono puntatori che posso assegnare a qualsiasi tipo di puntatore.