#include <stdio.h>
#include "LoadFile.h"


int main()
{
	char fileName[10]  ="Dupa.txt";
	struct MyFile myHeader;
	double s;
	myHeader = getHeader(fileName);
	printf("%d\n", myHeader.Users);
	getUserFile(fileName,myHeader);
	


}