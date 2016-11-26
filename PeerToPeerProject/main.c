#include <stdio.h>
#include <stdlib.h>
#include "LoadFile.h"



int main()
{
	char fileName[10]  ="test.txt";
	struct MyFile myHeader;
	myHeader = getHeader(fileName);
	int startLineUserFile = 17+myHeader.Users+1;
	int userFileLineAmount =countLineAmount(fileName,startLineUserFile);
	int *userFileArray = malloc( sizeof(int)*userFileLineAmount*2);
	getUserFile(userFileArray,fileName,startLineUserFile);

	int startConnectionLine = startLineUserFile + userFileLineAmount + 1;
	int *userConnectionArray = malloc(sizeof(int) * myHeader.Transactions*2);
	int endConnectLine = startConnectionLine+myHeader.Transactions;
	getUserConnections(userConnectionArray, fileName,startConnectionLine,startConnectionLine+myHeader.Transactions);
	printf("%d \n",endConnectLine );
	printf("Header: \n");
	printf("Users: %d \n",myHeader.Users);
	printf("Files: %d \n",myHeader.Files);
	printf("Transactions: %d\n",myHeader.Transactions);
	int i =0;
	printf("User- File array: \n");
	for(i;i<userFileLineAmount*2;++i)
	{
		if(i%2==0) printf("User: %d ",userFileArray[i] );
		else printf("File: %d \n",userFileArray[i]);
	}
	printf("\n");
	printf("User1-User2 connections array\n");
	for (i = 0; i < myHeader.Transactions*2; ++i)
	{
		if(i%2==0) printf("User: %d connected with ", userConnectionArray[i] );
		else printf("user: %d \n",userConnectionArray[i] );
	}


}
