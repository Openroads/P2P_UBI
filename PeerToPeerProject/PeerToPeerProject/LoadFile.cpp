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
	errno_t err;
	plik = fopen(filename, "r");

	char a[100];
	int b;


	char buff[255];

	int i = 0;
	while(fscanf(plik, "%s", &buff) != EOF)
	{
		if (i == 0)
		{
			myFile.Users = atoi(buff);
			printf("%d\n", myFile.Users);
		}

		if (i == 2)
		{
			myFile.Files = atoi(buff);
			printf("%d\n", myFile.Files);
		}
		
		if (i == 4)
		{
			myFile.Transactions = atoi(buff);
			printf("%d\n", myFile.Transactions);
		}
		
		i = i + 1;
		
	}

	return myFile;

}