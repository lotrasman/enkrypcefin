#include"encrypt.h"
#include <iostream>
#include <stdlib.h> 
#include <time.h>

int main()
{
	LPCWSTR filePath = L"c:\\temp\\file1.txt";
	unsigned int seed = 12345;
	

	
	
	encrypt encrypt(filePath, seed);

	encrypt.fileopen();

	encrypt.Krypt();

	encrypt.Test();

	encrypt.fileclose();
	
	
	



}
  