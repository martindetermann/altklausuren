#include "Huffman.h"

//Erklaerung in Huffman.h
tupel* huffmanDict;
int dictionarySize;

void printFrequency(unsigned int* frequency){
    //Durchlaufen des Arrays
	for(int i = 0; i < 256; i++){
        //Ausgabe des Zahlenwertes und ASCII-Zeichen des aktuellen Listenelements und dessen Haeufigkeit
		printf("%d\t: %u\n", i, frequency[i]);
	}
}

unsigned int* countChars(unsigned char* bytes, int size){
    //Groesse des Arrays für das Zwischenspeichern der Haeufigkeiten reservieren
	unsigned int* res = malloc(sizeof(int) * 256);

    //Array auf Null initialsieren
	for(int i = 0; i < 256; i++){
		res[i] = 0;
	}

    //Durch den eingelesenen Text iterieren 
	for(int i = 0; i < size; i++){
        //Arraxy an der Stelle des aktuellen ASCII-Zeichen-Indexes inkrementieren
		res[(int)bytes[i]]++;
	}

	return res;
}

void frequencyListInsert(char val, unsigned int frequency, listNode** list){
    //Leere Liste = bisher keine Liste vorhanden
	if(*list == NULL){
        //Anlegen eines neuen Listenknoten und Liste neu adressieren
		*list = malloc(sizeof(listNode));
		(*list)->val = val;
		(*list)->frequency = frequency;
		(*list)->nodenext = NULL;
		(*list)->heap = NULL;
		return;
	}

    //Element soll vor das bisher erste Element eingefügt werden
    if((*list)->frequency > frequency){
        //Anlegen eines neuen Listenknoten und Liste neu adressieren
        listNode* nodeold = *list;
        *list = malloc(sizeof(listNode));
		(*list)->val = val;
		(*list)->frequency = frequency;
		(*list)->nodenext = nodeold;
		(*list)->heap = NULL;
		return;
    }

    //Bestimmen der Position des neuen Elements innerhalb der Liste
	listNode* node = *list;
	while(node->nodenext != NULL && node->nodenext->frequency < frequency){
		node = node->nodenext;
	}

    //Anlegen eines neuen Listenknoten
	listNode* newNode = malloc(sizeof(listNode));
	newNode->frequency = frequency;
	newNode->val = val;
	newNode->nodenext = node->nodenext;
    newNode->heap = NULL;
    //Naechste Adresse des alten Elements festlegen
	node->nodenext = newNode;
}

listNode* frequencyListCreate(unsigned int* frequencies){
    //Neue Liste anlegen
	listNode* frequencyList = NULL;
    //Iteration ueber alle ASCII-Zeichen
	for (int i = 0; i < 256; i++){
        //Nur Elemente, die mehr als einmal vorkommen in die Liste einfügen
        if(frequencies[i] != 0){
            frequencyListInsert(i, frequencies[i], &frequencyList);
        }
	}

	return frequencyList;
}

void destroylist(listNode* list){
    //Zwischenspeichern des naechsten Listenknotens
    listNode* node = list->nodenext;
    //Freigabe des aktuellen Listenknotens
    free(list);

    //Abbruchbedingung und rekursiever Aufruf
    if(node != NULL){
        destroylist(node);
    }
}

void printlist(listNode* list){
    //Gibt ASCII-Zeichen-Index und Haeufigkeit des aktuellen Elements aus
    printf("%d:\t%u\n", list->val, list->frequency);

    //Abbruchbedingung und rekursiever Aufruf
    if(list->nodenext != NULL){
        printlist(list->nodenext);
    }
}

heapNode* getHeapNodefromList(listNode* list){
    //Neuer Heap-Knoten
    heapNode* heap;
    //Falls das aktuelle Listenelement keinen Heapknoten enthält, wird ein neuer angelegt, sonst wird der Alte genutzt
    if(list->heap == NULL){
        heap = malloc(sizeof(heapNode));
        heap->lChild = NULL;
        heap->rChild = NULL;
        heap->frequency = list->frequency;
        heap->val = malloc(2);
        heap->val[0] = list->val;
        heap->val[1] = '\0';
    }
    else{
        heap = list->heap;
    }
    
    return heap;
}

void frequencyListInsertListNode(listNode* list, listNode** frequencyList){
    //Fuegt ein Element in die Liste ein, das vor dem Ersten kommt
    if((*frequencyList)->frequency > list->frequency){
        list->nodenext = *frequencyList;
        *frequencyList = list;
		return;
    }

    //Bestimmen der Position des neuen Elements innerhalb der Liste
	listNode* node = *frequencyList;
	while(node->nodenext != NULL && node->nodenext->frequency < list->frequency){
		node = node->nodenext;
	}

    //Einfuegen des neuen Knoten in die Liste
    list->nodenext = node->nodenext;
    node->nodenext = list;
}

listNode* setNext(listNode* frequencyList){
    //Die nächsten zwei ueberspringen
    frequencyList = frequencyList->nodenext->nodenext;
    return frequencyList;
}

heapNode* buildHeap(listNode* frequencyList){
    //Solange es mehr als einen Eintarg in der Liste gibt, wird die Schleife ausgeführt
    while(frequencyList->nodenext != NULL){
        //Kinder aus der Liste extrahieren
        //Klingt ein bisschen Martialisch ist aber so
        heapNode* lChild = getHeapNodefromList(frequencyList);
        heapNode* rChild = getHeapNodefromList(frequencyList->nodenext);

        //Ein Parent für beide Kinder anlegen
        heapNode* heap = malloc(sizeof(heapNode));
        heap->lChild = lChild;
        heap->rChild = rChild;
        heap->frequency = lChild->frequency + rChild->frequency;
        heap->val = malloc(strlen(lChild->val) + strlen(rChild->val) + 1);
        sprintf(heap->val, "%s%s", lChild->val, rChild->val);

        //Aus dem Heapknoten ein Listenelement bauen
        listNode* list = malloc(sizeof(listNode));
        list->heap = heap;
        list->frequency = heap->frequency;
        list->val = heap->val[0];
        list->nodenext = NULL;

        //Den neuen Knoten in die Liste an der richtigen Position einfuegen
        frequencyListInsertListNode(list, &frequencyList);

        //Die ersten zwei Elemente aus der Liste loeschen
        frequencyList = setNext(frequencyList);
        //printf("\n");
        //printlist(frequencyList);
    }

    return frequencyList->heap;
}

int getListLen(listNode* list){
    int res = 0;

    //Hochzählen, bis das letzte Element ereicht ist
    while(list != NULL){
        list = list->nodenext;
        res++;
    }

    return res;
}

listNode* getListAt(listNode* list, int index){
    //Weiterlaufen bis i == 0 ist
    while(index >= 0){
        index--;
        //Nicht das Ende der Liste ueberschreiten
        if(list->nodenext == NULL){
            break;
        }
        //Weiterlaufen
        else{
            list = list->nodenext;
        }
    }

    return list;
}

int testString(char* string, char test){
    int ind = 0;
    //Index hochzaehlen bis das Ende des Strings ereicht ist
    while(string[ind] != '\0'){
        //Falls es zu einem Treffer kommt 1 als RV
        if(string[ind] == test){
            return 1;
        }
        ind++;
    }
    //Falls kein Treffer dabei war RV = 0
    return 0;
}

tupel* generateCode(heapNode* heapRoot, int sizeChars){
    //Laenge des Woerterbuchs festlegen
    tupel* codeDictionary = malloc(sizeof(tupel) * sizeChars);

    for (int i = 0; i < sizeChars; i++){
        tupel tup;
        
        //Code als leeren String initalisieren
        tup.code = "";
        //Das aktuelle ASCII-Zeichen bestimmen
        tup.val = heapRoot->val[i];
        heapNode* parent = heapRoot;
        while(1){
            //Falls das unterste Blatt erreicht ist wird die Schleife abgebrochen
            if(strlen(parent->val) == 1){
                //Nur ein Blatt hat ein einzelnes Zeichen 
                break;
            }
            //Abstieg in linken Teilbaum
            else if(testString(parent->lChild->val, tup.val)){
                //0 an den Code anfuegen
                char* newCode = malloc(strlen(tup.code) + 2);
                sprintf(newCode, "%s0", tup.code);
                tup.code = newCode;

                parent = parent->lChild;
            }
            //Abstieg in rechten Teilbaum
            else if(testString(parent->rChild->val, tup.val)){
                //1 an den Code anfuegen
                char* newCode = malloc(strlen(tup.code) + 2);
                sprintf(newCode, "%s1", tup.code);
                tup.code = newCode;

                parent = parent->rChild;
            }
        }

        //Neuen Eintrag ins Woerterbuch uebernehmen
        codeDictionary[i] = tup;
    }

    return codeDictionary;
}

void printTupel(tupel* tup){
    //Ausgabe des ASCII-Zeichen-Indexes, ASCII-Zeichens und des entsprechenden Codes
    printf("%d\t%c:\t%s\n", tup->val, tup->val, tup->code);
}

tupel* getDictionary(tupel* dictionary, int dictSize, char wanted){
    int ind = 0;
    //Initalisierung des Pointers auf NULL falls nichts gefunden wird
    tupel* tup = NULL;
    //Durchlauf bis das Ende des Woerterbuchs erreicht ist
    while(ind < dictSize){
        //Bei Treffer wird das aktuelle Tupel zurück gegeben
        if(dictionary[ind].val == wanted){
            tup = &dictionary[ind];
        }
        ind++;
    }

    return tup;
}

char* appendString(char* finalString, char* append){
    //Zusammenfueren von zwei Strings mittels sprintf
    char* newString = malloc(strlen(finalString) + strlen(append) + 1);
    sprintf(newString, "%s%s", finalString, append);
    return newString;
}

void destroyheap(heapNode* heap){
    //Rekursiveraufruf bis in die Blätter
    if(heap->lChild != NULL){
        destroyheap(heap->lChild);
    }
    if(heap->rChild != NULL){
        destroyheap(heap->rChild);
    }
    
    //Freigabe des Codes und des Heap-Knotens
    free(heap->val);
    free(heap);
}

char* huffman_encode(unsigned char* bytes, int size){
    //Als leere Zeichenkette initalisieren
    char* encoded = "";

    //Array mit den Haeufigkeiten aller Listenelemente erstellen
    unsigned int* frequency = countChars(bytes, size);
	//printFrequency(frequency);

    //Liste aus dem erstellten Array erzeugen
	listNode* frequencyList = frequencyListCreate(frequency);

    //Falls die Datei weniger als zwei Zeichen hat bringt das kompriemieren wenig
    int sizeChars = getListLen(frequencyList);
    printf("Anzahl an Chars: %d\n", sizeChars);
    if(sizeChars < 2){
        encoded = malloc(frequencyList->frequency + 1);
        encoded[0] = '\0';
        for(int i = 0; i < frequencyList->frequency; i++){
            sprintf(encoded, "%s1", encoded);
        }
        free(frequency);
        destroylist(frequencyList);

        return encoded;
    }

    //Liste der Haeufigkeiten ausgeben
    printlist(frequencyList);

    //Huffmantree aus liste bauen
    buildHeap(frequencyList);

    fflush(stdout);

    //Woerterbuch aus Huffmantree erzeugen
    tupel* codeDictionary = generateCode(getListAt(frequencyList, getListLen(frequencyList))->heap, sizeChars);
    huffmanDict = codeDictionary;
    dictionarySize = sizeChars;

    //Ausgabe aller Woerterbucheintraege
    for(int i = 0; i < sizeChars; i++){
        printTupel(&codeDictionary[i]);
    }
    fflush(stdout);

    //Codierung der Ursprünglichen Datei
    for(int i = 0; i < size; i++){
        printf("%s ", getDictionary(codeDictionary, sizeChars, bytes[i])->code);
        encoded = appendString(encoded, getDictionary(codeDictionary, sizeChars, bytes[i])->code);
    }
    printf("\n");
     
    fflush(stdout);

    //Freigabe des Haeufigkeiten-Arrays, der Haeufigkeiten-Liste und des Huffmantrees
    free(frequency);
    destroyheap(getListAt(frequencyList, getListLen(frequencyList))->heap);
    destroylist(frequencyList);

    return encoded;
}