#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LoadFile.h"


struct MyFile 
{
	int Users;
	int Files;
	int Transactions;
};


struct MyFile GetHeader(char *filename)
{
	MyFile myFile;
	FILE *plik;
	plik = fopen(filename, "r");
	char buff[255];

	int i = 0;
	while(fscanf(plik, "%s", &buff) != EOF)
	{
		if (i == 0)
		{
			myFile.Users = atoi(buff);
		}

		if (i == 2)
		{
			myFile.Files = atoi(buff);
		}
		
		if (i == 4)
		{
			myFile.Transactions = atoi(buff);
			break;
		}
		
		i = i + 1;
		
	}

	return myFile;

}