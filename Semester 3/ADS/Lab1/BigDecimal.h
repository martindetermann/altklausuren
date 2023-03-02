#ifndef HEADER_BIGDECIMAL
#define HEADER_BIGDECIMAL

typedef struct LNodeStruct LNode;

struct LNodeStruct
{
 unsigned char value; // used range: 0-9; 255 means digit not set
 LNode* next;
 LNode* prev;
};

/* Erstellt einen neuen leeren Listenknoten, indem der erforderliche 
Speicher auf dem Heap reserviert wird, (value=255, next und prev jeweils 
NULL) und gibt Zeiger darauf zurück. */
LNode* create_lnode(void);

/* Läuft zum Anfang der Liste und gibt den gesamten Speicher für den 
Listenanfang und alle Nachfolger wieder frei. */
void delete_list(LNode* node);

/* Läuft zum Anfang der Liste und gibt die gesamte Liste auf der 
Standardausgabe aus (von links nach rechts), beginnend mit dem ersten 
Element (least significant digit). */
void print(LNode* node);

/* Läuft zum Ende der Liste und gibt die gesamte Liste auf der 
Standardausgabe aus (von links nach rechts), beginnend mit dem letzten 
Element (most significant digit). Hinweis: dies ist die Ausgabeform, die 
Sie bei Dezimalzahlen normalerweise erwarten! */
void print_reverse(LNode* node);

/* Läuft zum ersten (least significant digit) Listenknoten (sofern 
vorhanden), erzeugt unter Verwendung von create_list einen neuen 
Listenknoten, setzt value auf val und hängt diesen neuen Listenknoten 
vor den bisherigen ersten ein. Beachten Sie, dass dies auch der erste 
Knoten in der Liste sein kann (Übergabeparameter node == NULL)! 
Rückgabewert ist ein Zeiger auf den neu erzeugten ersten Listenknoten
(neue least significant digit). */
LNode* prepend_val(LNode* node, unsigned char val);

/* Läuft zum letzten (most significant digit) Listenknoten (sofern 
vorhanden), erzeugt unter Verwendung von create_list einen neuen 
Listenknoten, setzt value auf val und hängt diesen neuen Listenknoten 
hinter den bisherigen letzten ein. Beachten Sie, dass dies auch der 
5 von 6
erste Knoten in der Liste sein kann (Übergabeparameter node == NULL)! 
Rückgabewert ist ein Zeiger auf den neu erzeugten letzten Listenknoten
(neue most significant digit).*/
LNode* append_val(LNode* node, unsigned char val);

/*
    Gibt die Node an der angegebenen Stelle(ind) an.
*/
LNode* get_at_LSD(LNode* node, unsigned int ind);

/*
    Fügt ein Node an der angegeben Stelle hinzu. 0 = kein problem 1 = out of range.
*/
unsigned int set_at_LSD(LNode* node, unsigned int ind, unsigned char val);

/*
    Gibt die Laenge der Liste wider ab dem node in Richtung MSD.
*/
unsigned int len_list(LNode* node);

/*
    Addiert zwei Zahlen. Return = LSD
*/
LNode* add_list(LNode* node, LNode* node2);

/*
    Gibt LSD zurück
*/
LNode* get_LSD(LNode* node);

/*
    Gibt die Laenge der gesamten Liste wider ab LSD in Richtung MSD.
*/
unsigned int len_list_from_LSD(LNode* node);

/*
    Gibt MSD zurück
*/
LNode* get_MSD(LNode* node);

#endif