#ifndef HUFFMAN
#define HUFFMAN

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

//Binäre Baumstruktur zur Erzeugung des Huffmancodes
typedef struct heapNodeStruct heapNode;
struct heapNodeStruct
{
	//Alle Zeichen aller Kinder
	char* val;
	//Gemeinsame Haeufigkeit der Kinder
	unsigned int frequency;
	//Kinder
	heapNode* lChild;
	heapNode* rChild;
};

//List die in Kombination mit der Heapstrucktur für die Bildung des Huffmancodes verantwortlich ist
typedef struct listNodeStruct listNode;
struct listNodeStruct
{
	//Zeichen
	char val;
	//Haeufigkeit des Zeichens
	unsigned int frequency;
	//Naechster Listeneintrag
	listNode* nodenext;

	//Liste besteht entweder aus Listenknoten oder Teilbaeumen
	//Am Anfang gibt es viele Listenknoten
	//Die Liste hat am Ende nur noch ein Element mit einem Teilbaum in dem alle Elemente der Liste enthalten sind
    heapNode* heap;
};

//Woerterbucheintrag 
typedef struct tupelStruct tupel;
struct tupelStruct{
	//Zu  codierendes Zeichen
	char val;
	//Code fuer Zeichen
	char* code;
};

//Woerterbuch global zur Verfügung stellen falls weiterdamit gearbeitet werdeb soll
extern tupel* huffmanDict;
//Groesse des Wörterbuchs
extern int dictionarySize;

//Ausgabe der Haeufigkeiten aller ASCII-Zeichen innerhalb der Datei
void printFrequency(unsigned int* frequency);

//Zaehlt die Haeufigkeiten aller Zeichen der eingelesenen Datei
unsigned int* countChars(unsigned char* bytes, int size);

//Fuegt neue Listenelemente bestehend aus ASCII-Zeichen und Haeufigkeit in eine Liste ein
//Das neue Element wird anheand seiner Haeufigkeit in Liste eingeordnet
void frequencyListInsert(char val, unsigned int frequency, listNode** list);

//Ordnet alle ASCII-Zeichen, die in der eingelesenen Datei enthalten sind in eine Liste ein
listNode* frequencyListCreate(unsigned int* frequency);

//Baut aus der Haeufigkeiten-Liste den Huffmantree
heapNode* buildHeap(listNode* frequncyList);

//Gibt den Speicherplatz, der von der Liste auf dem Heap belegt wuird wieder frei
void destroylist(listNode* list);

//Gibt die uebergene Liste aus
void printlist(listNode* list);

//Erzeugt einen Baum-Knoten aus dem uebergebenen Listenelement
heapNode* getHeapNodefromList(listNode* list);

//Die ersten zwei knoten werden aus der Liste gelöscht
listNode* setNext(listNode* frequencyList);

//Ermittelt die Laenge der Liste
int getListLen(listNode* list);

//Gibt das Element am angegeben Index wieder
listNode* getListAt(listNode* list, int index);

//codiert die übergene Bytefolge mit dem Huffman-Alghoritmus
char* huffman_encode(unsigned char* bytes, int size);

//Ueberprueft einen String auf ein Zeichen
int testString(char* string, char test);

//Findet ein Element aus dem Woerterbuch anhand des ASCII-Zeichens
tupel* getDictionary(tupel* dictionary, int dictSize, char wanted);

//Fuegt zwei Strings zusammen
char* appendString(char* finalString, char* append);

//Gibt den Speicherplatz frei, der durch den Huffmanbaum belegt wird
void destroyheap(heapNode* heap);

//Gibt ein Element aus dem Woerterbuch aus
void printTupel(tupel* tup);

//Fuegt einen teilbaum in die Liste ein
void frequencyListInsertListNode(listNode* list, listNode** frequencyList);

//Geneiert aus dem Huffmantree den dazugehoerigen Code
tupel* generateCode(heapNode* heapRoot, int sizeChars);

#endif /* HUFFMAN */