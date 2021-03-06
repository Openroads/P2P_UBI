#include <stdio.h>
#include <stdlib.h>
#include "LoadFile.h"
#include "Algorithms.h"
#include <time.h>
//#include <sys/queue.h>


void makeAdjacencyMatrix(int **matrixArray, int *connectionArray,int *fileArray,int userFileSize ,int connectionSize,int matrixSize);
void resetMatrix(int **matix,int size);
void showAdjacencyMatrix(int **matrix,int size);
void makeUserFileStruct(struct UserFile *array,int sizeS,int *userFileArray,int sizeUFA);


int main()
{
	char fileName[15]  =  "test.txt";

	struct MyFile myHeader;
	myHeader = getHeader(fileName);
	/******************** Load data from file ****************************/
	int startLineUserFile  		= 17+myHeader.Users+1;
	int userFileLineAmount 		= countLineAmount(fileName,startLineUserFile);
	int userFileArraySize  		= userFileLineAmount*2;
	int *userFileArray     		= malloc( sizeof(int)*userFileArraySize);
	getUserFile(userFileArray,fileName,startLineUserFile);
	int startConnectionLine 	= startLineUserFile + userFileLineAmount + 1;
	int connectionArraySize 	= myHeader.Transactions*2;
	int *userConnectionArray 	= malloc(sizeof(int) * connectionArraySize);
	int endConnectLine 			= startConnectionLine+myHeader.Transactions;
	getUserConnections(userConnectionArray, fileName,startConnectionLine,endConnectLine);
	/************************************************************************/

	/************ Making array with Users and files which user has **********/
	struct UserFile *userFile = (struct UserFile*)malloc(sizeof(struct UserFile)*myHeader.Users);
	makeUserFileStruct(userFile,myHeader.Users,userFileArray,userFileArraySize);
	/************************************************************************/
	
	/******************* Print out data *************************************/
	printf("Header: \n");
	printf("Users: %d \n", myHeader.Users);
	printf("Files: %d \n", myHeader.Files);
	printf("Transactions: %d\n", myHeader.Transactions);
	int i =0;
	printf("User- File array: \n");
	for(i=0; i < userFileArraySize ;++i)
	{
		if(i%2==0) printf("User: %d ",userFileArray[i] );
		else printf("File: %d \n",userFileArray[i]);
	}
	printf("\n");
	printf("User1-User2 connections array\n");
	for (i = 0; i < connectionArraySize; ++i)
	{
		if(i%2==0) printf("User: %d wants file:", userConnectionArray[i] );
		else printf(" %d \n",userConnectionArray[i] );
	}
	/* Making matrix UsersxUsers*/
	int adjancencyMatrixSize = myHeader.Users;
	int **adjacencyMatrix = (int**)malloc(sizeof(int*) * adjancencyMatrixSize);
	if(adjacencyMatrix)
	{
		for(i=0; i < adjancencyMatrixSize;++i)
		{
			adjacencyMatrix[i] = (int *)malloc (sizeof(int)*adjancencyMatrixSize);
		}
	}
	/*********************************************************************/
	
	/************* Print files which each user has **********************/
	//printf("\nUser  -> files\n");
	int j;
	for(i=0 ; i < myHeader.Users;++i)
	{
		printf("%d -> ",userFile[i].user);
		for(j=0; j < userFile[i].fileAmount; ++j)
			{
				printf("%d, ",userFile[i].files[j]);
			}
		printf("\n");
	}
	/***** for debugging *********/
	int START_USER =11;
	int FILE_TO_FIND=12;
	clock_t start;
	clock_t stop;
	float time;

	/**************Making and printing adjacency Matrix between users ****/
	resetMatrix(adjacencyMatrix,adjancencyMatrixSize);
	makeAdjacencyMatrix(adjacencyMatrix,userConnectionArray,userFileArray,adjancencyMatrixSize,userFileArraySize,connectionArraySize);
	showAdjacencyMatrix(adjacencyMatrix,adjancencyMatrixSize);
	/****************          Algorithms             **********************/
	printf("Algorithm: 		Path length:		Time:\n");
	/********          BFS           **********/
	start = clock();
	int bfsPathLength = bfs(adjacencyMatrix,myHeader.Users,START_USER,FILE_TO_FIND,userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("BFS 				   	%d 		%f\n",bfsPathLength,time);


	/********          DFS           **********/
	start = clock();
	int dfsPathLength = dfs(adjacencyMatrix, adjancencyMatrixSize, START_USER, FILE_TO_FIND, userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("DFS 				   	%d 		%f\n", dfsPathLength,time);
	/********          Belman Ford   **********/
	start =clock();
	int BFPathLength = belmanFord(adjacencyMatrix, adjancencyMatrixSize, START_USER, FILE_TO_FIND, userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("Bellman Ford  			        %d 		%f\n",BFPathLength,time);

	/********      		Prim         *********/
	start = clock();
	int primPathLength = prim(adjacencyMatrix, adjancencyMatrixSize, START_USER, FILE_TO_FIND, userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("Prim 				        %d  		%f\n", primPathLength, time);

	/********          Dijkstra           **********/
	start = clock();
	int dijkstraPathLength = dijkstra(adjacencyMatrix, adjancencyMatrixSize, START_USER, FILE_TO_FIND, userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("Dijkstra  			        %d 		%f\n", dijkstraPathLength, time);

	/********          Kruskal          **********/
	start = clock();
	int kruskalPathLength = kruskal(adjacencyMatrix, adjancencyMatrixSize, START_USER, FILE_TO_FIND, userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("Kruskal  			        %d 		%f\n", kruskalPathLength, time);

	/********          Floyd Warshall          **********/
	start = clock();
	int floydPath = floydWarshall(adjacencyMatrix, adjancencyMatrixSize, START_USER, FILE_TO_FIND, userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("Floyd Warshall  		        %d 		%f\n", floydPath, time);
	
	/********          A star          **********/
	start = clock();
	int astarPath = astar(adjacencyMatrix, adjancencyMatrixSize, START_USER, FILE_TO_FIND, userFile);
	stop = clock();
	time = (float)(stop - start) / CLOCKS_PER_SEC;
	printf("A star  		       		%d 		%f\n", astarPath, time);

	/***************** Free memory *********************/
	free(userFileArray);
	free(userConnectionArray);
	free(userFile);
	for(i=0; i < adjancencyMatrixSize; ++i)
		free(adjacencyMatrix[i]);
	free(adjacencyMatrix);

	return 0;



}

void makeAdjacencyMatrix(int **matrixArray, int *connectionArray,int *fileArray,int matrixSize,int userFileSize ,int connectionSize)
{
	int i,j, k ;
	int a = i = j = k = 0;
	int border = connectionSize-1;
	int user,file;
	user=file=0;
	
	for(a=0 ; a < border; a+=2)
	{
		user = connectionArray[a];  file = connectionArray[a+1];
		for(i=1; i < userFileSize; i+=2)
		{
			if(fileArray[i] == file)
			{
				j = fileArray[i-1];
				k = user;
				matrixArray[j][k] = 1;
				matrixArray[k][j] = 1;
			}
		}
	}
}

void resetMatrix(int **matrix,int size)
{
	int i=0; int j =0;
	for(i=0; i < size; i++)
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
	printf("\n");
	for(i=0; i < size; i++)
	{
		if(i<=9) printf("\n  %d  ",i);
		else printf("\n %d  ",i);
		for(j=0; j < size; j++)
		{
			printf("%d ",matrix[i][j]);
		}
	}
	printf("\n");
}

void makeUserFileStruct(struct UserFile *array,int sizeS,int *userFileArray,int sizeUFA)
{
	int counter = 0;
	int u,i,j;
	for(u=0 ; u < sizeS;++u)
	{
		array[u].user = u;
		for(i =0; i<sizeUFA-1; i+=2)
		{
			if(u == userFileArray[i]) counter++;

		}
		array[u].fileAmount = counter;
		array[u].files = malloc( sizeof(int)*counter );
		counter=0;
		j=0;
		for(i =0; i<sizeUFA; i+=2)
		{
			if(u == userFileArray[i])
			{
				array[u].files[j] = userFileArray[i+1];
				j++;
			}
		}
	}
}
