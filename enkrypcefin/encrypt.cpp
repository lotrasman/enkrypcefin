#include "encrypt.h"
#include <cstdio>
//konstruktor
encrypt::encrypt (const char* srcFile, const char* destFile)
//inicializace
    : sourceFile(srcFile), destinationFile(destFile),
	p_file(nullptr), p_file2(nullptr) {
    fopen_s(&p_file, sourceFile, "r");
    fopen_s(&p_file2, destinationFile, "w");
}
//destruktor
encrypt::~encrypt() {
    fclose(p_file);
    fclose(p_file2);
}
void encrypt::frencrypt() {
    unsigned char uchReadBuffer;
    int lintCount;
	do {
		// Cteni bytu 
		lintCount = fread_s(&uchReadBuffer, 1, 1, 1, p_file);
		// Zasifrovat / if aby se nepridaval znak nakonci
		if(lintCount!=0){
		uchReadBuffer = uchReadBuffer + 1;
		// Z�pis bytu 
		fwrite(&uchReadBuffer, 1, 1, p_file2);
		}
	} while (lintCount != 0);
}

void encrypt::decrypt() {
	unsigned char uchReadBuffer;
	int lintCount;
	do {
		// Cteni bytu 
		lintCount = fread_s(&uchReadBuffer, 1, 1, 1, p_file);
		// odsifrovat 
		if (lintCount != 0) {
			uchReadBuffer = uchReadBuffer -1;
			// Z�pis bytu 
			fwrite(&uchReadBuffer, 1, 1, p_file2);
		}
	} while (lintCount != 0);
}