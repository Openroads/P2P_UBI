#include <stdio.h>
#include <stdlib.h>
#include "LoadFile.h"


int main()
{
	char fileName[10]  ="Dupa.txt";
	struct MyFile myHeader;
	myHeader = getHeader(fileName);
	printf("%d\n", myHeader.Users);
	int startLine = 17+myHeader.Users+1;
	int arraySize =countFileCopies(fileName,startLine);
	int *userFileArray = malloc( sizeof(int)*arraySize*2);
	printf("%d \n",arraySize );
	getUserFile(userFileArray,fileName,myHeader);
	int i =0;
	for(i;i<3080;i++)
	{
		printf("%d ",userFileArray[i] );
		
	}


}