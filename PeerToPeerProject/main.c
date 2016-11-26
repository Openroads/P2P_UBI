#include <stdio.h>
#include <stdlib.h>
#include "LoadFile.h"

void makeAdjacencyMatrix(int **matrixArray, int *connectionArray,int *fileArray,int userFileSize ,int connectionSize,int matrixSize);
void resetMatrix(int **matix,int size);
void showAdjacencyMatrix(int **matrix,int size);

int main()
{
	char fileName[10]  ="test.txt";
	struct MyFile myHeader;
	myHeader = getHeader(fileName);
	int startLineUserFile = 17+myHeader.Users+1;
	int userFileLineAmount =countLineAmount(fileName,startLineUserFile);
	int userFileArraySize = userFileLineAmount*2;
	int *userFileArray = malloc( sizeof(int)*userFileArraySize);
	getUserFile(userFileArray,fileName,startLineUserFile);

	int startConnectionLine = startLineUserFile + userFileLineAmount + 1;
	int connectionArraySize = myHeader.Transactions*2;
	int *userConnectionArray = malloc(sizeof(int) * connectionArraySize);
	int endConnectLine = startConnectionLine+myHeader.Transactions;
	getUserConnections(userConnectionArray, fileName,startConnectionLine,startConnectionLine+myHeader.Transactions);
	printf("%d \n",endConnectLine );
	printf("Header: \n");
	printf("Users: %d \n", myHeader.Users);
	printf("Files: %d \n", myHeader.Files);
	printf("Transactions: %d\n", myHeader.Transactions);
	int i =0;
	printf("User- File array: \n");
	for(i; i < userFileArraySize ;++i)
	{
		if(i%2==0) printf("User: %d ",userFileArray[i] );
		else printf("File: %d \n",userFileArray[i]);
	}
	printf("\n");
	printf("User1-User2 connections array\n");
	for (i = 0; i < connectionArraySize; ++i)
	{
		if(i%2==0) printf("User: %d connected with ", userConnectionArray[i] );
		else printf("user: %d \n",userConnectionArray[i] );
	}
	/* Making matric UsersxUsers*/
	int adjancencyMatrixSize = myHeader.Users;
	int **adjacencyMatrix = (int**)malloc(sizeof(int*) * adjancencyMatrixSize);
	if(adjacencyMatrix)
	{
		for(i=0; i < adjancencyMatrixSize;++i)
		{
			adjacencyMatrix[i] = (int *)malloc (sizeof(int)*adjancencyMatrixSize);
		}
	}
	resetMatrix(adjacencyMatrix,adjancencyMatrixSize);
	showAdjacencyMatrix(adjacencyMatrix,adjancencyMatrixSize);
	makeAdjacencyMatrix(adjacencyMatrix,userConnectionArray,userFileArray,userFileArraySize,connectionArraySize,adjancencyMatrixSize);

}

void makeAdjacencyMatrix(int **matrixArray, int *connectionArray,int *fileArray,int matrixSize,int userFileSize ,int connectionSize)
{
	int i,j, k ;
	int a = i = j = k = 0;
	int border = connectionSize-1;
	int user,file;
	user=file=0;
	for(a; a < border; a+=2)
	{
		user = connectionArray[a];  file = connectionArray[a+1];

		for(i=1; i < userFileSize; i+=2)
		{
			if(fileArray[i] == file)
		}


	}

}

void resetMatrix(int **matrix,int size)
{
	int i=0; int j =0;
	for(i; i < size; i++)
	{
		for(j=0; j < size; j++)
		{
			matrix[i][j] = 0;
		}
	}
}
void showAdjacencyMatrix(int **matrix,int size)
{
	int i=0; int j =0;
	for(i; i < size; i++)
	{
		for(j=0; j < size; j++)
		{
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}
