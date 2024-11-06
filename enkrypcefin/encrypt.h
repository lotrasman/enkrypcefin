#pragma once
#include <cstdio>
class encrypt
{
public:
	
	encrypt(const char* srcFile, const char* destFile);
	~encrypt();
	void frencrypt();
	void decrypt();



private:
	
	const char* sourceFile;
	const char* destinationFile;

	FILE* p_file;
	FILE* p_file2;


};

