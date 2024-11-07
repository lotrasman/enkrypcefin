#include "encrypt.h"
#include <cstdio>
#include <windows.h>
#include <stdlib.h> 
#include <time.h>
#include <cstdlib>
#include <ctime>
//konstruktor
encrypt::encrypt(LPCWSTR srcFile, unsigned int seed): sourceFile(srcFile), hFile(NULL), hFileMapping(NULL), p_mSourceFirstByte(NULL), fileSize(0)
{
	
}
	
//destruktor
encrypt::~encrypt() {
	
}
void encrypt::fileopen() {
    hFile = CreateFile(sourceFile, GENERIC_WRITE | GENERIC_READ,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, NULL);

	p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	fileSize = GetFileSize(hFile, 0);

	
	/*if (hFile || hFileMapping == INVALID_HANDLE_VALUE) {
		return 1;
	}*/
	
}

void encrypt::fileclose() {
	
	FlushViewOfFile(p_mSourceFirstByte, 0);

	UnmapViewOfFile(p_mSourceFirstByte);

	CloseHandle(hFile);
	CloseHandle(hFileMapping);
	
	
}
void encrypt::Krypt()
{
	srand(seed);
	for (DWORD i = 0; i < fileSize; i++) {
		p_mSourceFirstByte[i] = p_mSourceFirstByte[i] ^ (rand() % 255);
	}
	
}
void encrypt::Test()
{
	for (DWORD y = 0; y <fileSize; y++) {
		printf("%c", p_mSourceFirstByte[y]);
	}
}
