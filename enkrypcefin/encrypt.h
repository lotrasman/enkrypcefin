#pragma once
#include <cstdio>
#include <windows.h>
#include <stdlib.h> 
#include <time.h>
class encrypt
{
public:
	
	encrypt(LPCWSTR srcFile, unsigned int seed);
	~encrypt();
	void fileopen();
	void fileclose();
	void Krypt();
	void Test();


private:

	LPCWSTR sourceFile;
	unsigned int seed;
	

	

	
	HANDLE hFile;
	HANDLE hFileMapping;
	PBYTE p_mSourceFirstByte;
	DWORD fileSize;

};

