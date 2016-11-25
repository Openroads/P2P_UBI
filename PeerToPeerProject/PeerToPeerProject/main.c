#include <stdio.h>
#include "LoadFile.h"


int main()
{
	struct MyFile myHeader;
	double s;
	myHeader = getHeader("Dupa.txt");
	printf("%d\n", myHeader.Users);
	


}