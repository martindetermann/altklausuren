#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void arrayOut(int count, int* arr){
    for(int i = 0; i < count; i++){
        printf("Zahl%d: %d\n", i, arr[i]);
    }
}

unsigned int rand32BitInt(){
    int result;

    int lower = rand();     //untere 15 Bits
    int middle = rand();    //mittlere 15 Bits
    int upper = rand();     //obere 2 Bits

    //Masken anlegen 
    lower = lower & 0x7FFF;
    middle = middle & 0x7FFF;
    upper = upper & 0x0003;

    //Veroderung zum Zusammenfügen der Zahlenteile
    result = lower | (middle << 15) | (upper << 30); 
    
    //  1010111
    //    1100000
    //  101111100

    return result;
}

int* createRandomValues(int minval, int maxval, int length){
    //Initialisierung des Rückgabepointers
    int* result;
    result = malloc(length * sizeof(int));

    //Durchschnitt und Differenz von min- und maxval berechnen
    double dDurchschnitt = ((double)minval + (double)maxval) / 2.0;
    double dDiff = ((double)maxval - (double)minval + 1.0) / 2.0;

    for(int i = 0; i < length; i++){
        //Zufälliger int
        int iRandom = rand32BitInt();

        //In den Space zwischen -1 und 1 bringen
        double dRandCliped = (double)iRandom / (int)0x7FFFFFFF;

        //Fals dRandCliped == 1, wird auf maxval + 1 gerundet
        if(dRandCliped != 1.0 && dRandCliped != -1.0){
            dRandCliped = dRandCliped * dDiff + dDurchschnitt;

            result[i] = round(dRandCliped);
        }
        else if(dRandCliped == -1.0){
            result[i] = minval;
        }
        else{
            result[i] = maxval;
        }
    }

    return result;
}

void selectionsort(int* values, int size){
    //Variable für aktuelle Vergleichszahl
    int smallest;

    for(int i = 0; i < size; i++){
        //Index des aktuellen Pivot´s setzen
        smallest = i;

        //Iteration durch den unsortierten Listenteil
        for(int j = i; j < size; j++){
            //Pivotindex neu zuweisen
            if(values[smallest] >= values[j]){
                smallest = j;
            }
        }

        //Kleinste Zahl der verbleibenden Teilliste an ertste Position dieser verschieben
        int remember = values[i];
        values[i] = values[smallest];
        values[smallest] = remember;
    }
}

void testSelectionsort(int valueCount, int minVal, int maxVal){
    //Speichervariable für Summe der Laufzeiten
    double sumt = 0.0;

    //3-maliges durchführen
    for(int k = 0; k < 3; k++){
        clock_t startClk, endClk;
        double time;

        //Zufallszahlen generieren
        int* zahlen = createRandomValues(minVal, maxVal, valueCount);

        //Startzeit speichern
        startClk = clock();

        //sortieren
        selectionsort(zahlen, valueCount);

        //Endzeit speichern
        endClk = clock();
        //Differenz von Start und Ende. Von ms in s konvertieren
        time = (double)(endClk - startClk) / (double)CLOCKS_PER_SEC;
        //Ausgabe der Laufzeit des aktuellen Durchlaufs
        printf("Zeit: %.5lf\n", (double)time);
        fflush(stdout);
        //aufsummieren der Laufzeiten
        sumt += time;

        //Freigeben des Speicherplatzes, der für die Zufallszahlen reserviert wurde
        free(zahlen);
    }

    //Durchschnittliche Laufzeit ermitteln und ausgeben
    double dDurchschnitt = sumt / 3.0;
    printf("Durchschnittliche Zeit: %.5lf\n", dDurchschnitt);
}

//Funktion, die die Summe über 2^n zurückgibt
int sum_pow_2_n(int n){
    if(n < 0){
        return 0;
    }

    int sum = 0;

    for(int i = 0; i <= n; i++){
        sum += pow(2, i);
    }

    return sum;
}

//Ausgabe des Heaps auf der Konsole
void print_heap(int* values, int size, int parent){
    printf("Current-node: %d\n", values[parent]);
    int i = 0;
    while(1){
        for(int j = sum_pow_2_n(i - 1); j < sum_pow_2_n(i); j++){
            if(j >= size){
                printf("\n\n");
                return;
            }
            printf("%d \t", values[j]);
        }
        printf("\n");

        i++;
    }
}

//Methode, die einen Parent und seine beiden children sortiert
void heapify(int* values, int size, int parent){
    //Bestimmen des linken Child
    int lChild = parent * 2 + 1;
    //Variable für neuen Parent
    int newParent = parent;

    //Feststellen ob linkes Kind neuer Parent wird
    if(lChild < size && values[lChild] > values[newParent]){
        newParent = lChild;
    }
    //Feststellen ob rechtes Kind neuer Parent wird
    if((lChild + 1) < size && values[lChild + 1] > values[newParent]){
        newParent = lChild + 1;
    }

    //Vergleich ob neuer und alter Parent derselbe sind, falls dies der Fall ist, ist dieser Ast fertig
    if(parent != newParent){
        //Parent mit child wechseln
        int remember = values[parent];
        values[parent] = values[newParent];
        values[newParent] = remember;

        //Heapify-Methode rekursiv aufrufen, denn der Ast ist noch nicht fertig
        heapify(values, size, newParent);
    }
}

//Analog zur heapify-Methode, jedoch ohne rekursiven Aufruf(Speicher- und Zeitoptimierung)
void heapifyNR(int* values, int size, int parent){
    while(1){
        int lChild = parent * 2 + 1;
        int newParent = parent;

        if(lChild < size && values[lChild] > values[newParent]){
            newParent = lChild;
        }
        if((lChild + 1) < size && values[lChild + 1] > values[newParent]){
            newParent = lChild + 1;
        }

        if(parent != newParent){
            int remember = values[parent];
            values[parent] = values[newParent];
            values[newParent] = remember;

            parent = newParent;
        }
        else{
            return;
        }
    }
}
    
//heapsort
void heapsort(int* values, int size){
    //Bei einem oder null Elementen gibt es nichts zu sortieren 
    if(size <= 1){
        return;
    }

    //Maxheap herstellen(Kein Child darf größer sein als sein Parent)
    for(int i = (size / 2); i >= 0; i--){
        heapifyNR(values, size, i);
    }

    //Downheap(Größtes Element steht an der Spitze und wird ans Ende gegeben. Dafür wird das letzte Element per heapify wieder neu in den Heap eingeordnet)
    for(int i = (size - 1); i > 0; i--){
        int remember = values[0];
        values[0] = values[i];
        values[i] = remember;

        heapifyNR(values, i, 0);
    }
}

void testHeapsort(int valueCount, int minVal, int maxVal){
    //Speichervariable für Summe der Laufzeiten
    double sumt = 0.0;

    //3-maliges durchführen
    for(int k = 0; k < 3; k++){
        clock_t startClk, endClk;
        double time;

        //Zufallszahlen generieren
        int* zahlen = createRandomValues(minVal, maxVal, valueCount);

        //Startzeit speichern
        startClk = clock();

        //sortieren
        heapsort(zahlen, valueCount);

        //Endzeit speichern
        endClk = clock();
        //Differenz von Start und Ende. Von ms in s konvertieren
        time = (double)(endClk - startClk) / (double)CLOCKS_PER_SEC;
        //Ausgabe der Laufzeit des aktuellen Durchlaufs
        printf("Zeit: %.5lf\n", (double)time);
        fflush(stdout);
        //aufsummieren der Laufzeiten
        sumt += time;

        //Freigeben des Speicherplatzes, der für die Zufallszahlen reserviert wurde
        free(zahlen);
    }

    //Durchschnittliche Laufzeit ermitteln und ausgeben
    double dDurchschnitt = sumt / 3.0;
    printf("Durchschnittliche Zeit: %.5lf\n", dDurchschnitt);
}

int main(int argc, char **arg){
    printf("Willkommen zum Zufall\n");

    srand(time(NULL));
    //Ausgabe des maximalen Zufallswertes
    printf("RAND_MAX: %d\n\n", RAND_MAX);

    //Ausgabe der 15Bit Zufalszahlen
    for(int i = 0; i < 10; i++){
        int iRandom = rand();
        printf("Zufallszahl %d: %d\n", i, iRandom);
    }

    printf("\n");

    //Ausgabe der 32Bit Zufalszahlen
    for(int i = 0; i < 10; i++){
        int iRandom = rand32BitInt();
        printf("Zufallszahl %d: %d\n", i, iRandom);
    }

    printf("\n");

    const int len = 10000;
    //Zufallszahlen in Array abspeichern
    int* zufallsZahlen = createRandomValues(-4, 5, len);
    //Auswertungsarry mit 0 initialsieren
    //Abspeichern der aufsummierten Häufigkeiten
    int auswertung[12];
    for(int i = 0; i < 12; i++){
        auswertung[i] = 0;
    }

    //Häufigkeiten der Zufallszahlen ermitteln
    for(int i = 0; i < len; i++){
        auswertung[5 + zufallsZahlen[i]]++;
    }

    //Ausgabe
    for(int i = 0; i < 12; i++){
        printf("Anzahl an Zahl%d: %d\n", (i - 5), auswertung[i]);
    }

    /*
    zufallsZahlen = createRandomValues(0, 100, 10);
    for(int i = 0; i < 10; i++){
        printf("Zahl%d: %d\n", i, zufallsZahlen[i]);
    }
    printf("\n");
    bottomUpHeapsort(zufallsZahlen, 10);
    for(int i = 0; i < 10; i++){
        printf("Zahl%d: %d\n", i, zufallsZahlen[i]);
    }
    //*/

    printf("Selectionsort: \n");
    /*
    printf("5000: \n");
    testSelectionsort(5000, 0, 1000000);

    printf("10000: \n");
    testSelectionsort(10000, 0, 1000000);

    printf("20000: \n");
    testSelectionsort(20000, 0, 1000000);

    printf("40000: \n");
    testSelectionsort(40000, 0, 1000000);

    printf("80000: \n");
    testSelectionsort(80000, 0, 1000000);
    //*/

    /*
    printf("5000: \n");
    testSelectionsort(5000, 0, 128000000);

    printf("10000: \n");
    testSelectionsort(10000, 0, 128000000);

    printf("20000: \n");
    testSelectionsort(20000, 0, 128000000);

    printf("40000: \n");
    testSelectionsort(40000, 0, 128000000);

    printf("80000: \n");
    testSelectionsort(80000, 0, 128000000);
    //*/


    printf("\n\nHeapsort: \n");
    /*
    printf("1000000: \n");
    testHeapsort(1000000, 0, 1000000);

    printf("2000000: \n");
    testHeapsort(2000000, 0, 1000000);

    printf("4000000: \n");
    testHeapsort(4000000, 0, 1000000);

    printf("8000000: \n");
    testHeapsort(8000000, 0, 1000000);

    printf("16000000: \n");
    testHeapsort(16000000, 0, 1000000);

    printf("32000000: \n");
    testHeapsort(32000000, 0, 1000000);
    //*/

    /*printf("64000000: \n");
    testHeapsort(64000000, 0, 1000000);*/

    /*printf("128000000: \n");
    testHeapsort(128000000, 0, 1000000);*/

    /*printf("256000000: \n");
    testHeapsort(256000000, 0, 1000000);*/

    /*printf("1024000000: \n");
    testHeapsort(1024000000, 0, 1000000);*/

    /*
    printf("1000000: \n");
    testHeapsort(1000000, 0, 128000000);

    printf("2000000: \n");
    testHeapsort(2000000, 0, 128000000);

    printf("4000000: \n");
    testHeapsort(4000000, 0, 128000000);

    printf("8000000: \n");
    testHeapsort(8000000, 0, 128000000);

    printf("16000000: \n");
    testHeapsort(16000000, 0, 128000000);

    printf("32000000: \n");
    testHeapsort(32000000, 0, 128000000);
    //*/

    return 0;
}
