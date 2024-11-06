#include"encrypt.h"
#include <iostream>

int main()
{
	int decision;
	const char* srcPath("c:\\temp\\file1.txt");

	const char* destPath("c:\\temp\\file2.txt");
	encrypt encrypt(srcPath, destPath);
	printf("Enter 1 for Encrypt or 2 for Decrypt: "); 
	scanf_s("%d", &decision);
	if (decision == 1) {
		encrypt.frencrypt();
		printf("success");
	}
	else if (decision == 2) {
		encrypt.decrypt();
		printf("success");
	}
	else {
		printf("can u not read or what");
	}
	encrypt.~encrypt();



}
