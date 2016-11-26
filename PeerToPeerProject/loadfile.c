#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LoadFile.h"


struct MyFile getHeader(char *filename)
{
	struct MyFile myFile;
	FILE *plik;
	plik = fopen(filename, "r");
	char buff[255];

	int i = 0;
	while(fscanf(plik, "%s", buff) != EOF)
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
void getUserFile(int *readArray,char *filename,struct MyFile header)
{	
	int startLine = 17+header.Users+1;
	FILE *f;
	f = fopen(filename, "r");
	char buff[100];
	int n =100;
	int iterator=0;
	int counter =0;
	while(counter<startLine)
	{
		fgets(buff,n,f);
		counter++;
	}

	int a =0;
	int i =0;

	char bu[6];
	char bf[6];
	int user=0;
	int file=0;

	fgets(buff,n,f);
	while(buff[0] == '(')
	{	
		
		while(buff[i+1] != ',' )
		{
			bu[a] = buff[i+1];
			i++;
			a++;
		}
		bu[a]=' ';
		i++;
		a=0;
		while(buff[i+1] != ',')
		{
			bf[a] = buff[i+1];
			i++;
			a++; 
		}
		bf[a]=' ';
		i=0;
		a=0;
		
		user = atoi(bu);
		file = atoi(bf);
		readArray[iterator++] = user;
		readArray[iterator++] = file;

		fgets(buff,n,f);

	}
	printf("%d\n",iterator );
	fclose(f);

}
int countFileCopies(char *filename,int startLine)
{
	FILE *file;
	file = fopen(filename, "r");
	char buff[100];
	int amount =0;
	int counter=0;
	int n=100;

	while(counter < startLine)
	{
		fgets(buff,n,file);
		counter++;
	}

	do{

		fgets(buff,n,file);
		amount++;

	}while(buff[0] != '\n');

	fclose(file);
	return amount-1;
	
}