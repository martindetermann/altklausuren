#include "Huffman.h"

int main(int argc, char **argv){
	if(argc != 2){
		printf("Keine Datei angegeben!");
		return 1;
	}

	//Anzeigen der eizulesenden Datei
	printf("Zu oeffnende Datei: %s\n", argv[1]);

	//File zum lesen öffnen
	FILE* readFile = fopen(argv[1], "r");

	//Abfangen des Fehlers einer nicht existierenden Datei
	if(readFile == NULL){
		printf("Die angegebene Datei existiert nicht");
		return 1;
	}

	//Anzahl an Zeichen in der Datei feststellen
	int size = 0;
	while(fgetc(readFile) != EOF){
		size++;
	}
	fseek(readFile, 0, SEEK_SET);

	//Bei leerer Datei Programm beenden
	if(size == 0){
		printf("Die Datei: %s ist leer\n", argv[1]);
		return 1;
	}

	//Einlesen Datei der Datei und Ausgabe der ASCII-Zeichen als Hex-Code
	unsigned char* bytes = malloc(size);
	for(int i = 0; i < size; i++){
		bytes[i] = fgetc(readFile);
		printf("%0x", bytes[i]);
	}
	printf("\n");

	//Aufrufen der Huffman-Kodierung
	char* encoded = huffman_encode(bytes, size);

	//Ausgabe der kodierten Datei
	printf("%s\n", encoded);

	fflush(stdout);

	//Freigabe des Speicherplatzes von Code-Wörterbuch, original eingelesenen Zeichen und de huffman-codierten Testes
	free(huffmanDict);
	free(encoded);
	free(bytes);

	fclose(readFile);

	return 0;
}
