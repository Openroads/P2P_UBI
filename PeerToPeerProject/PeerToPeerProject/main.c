#include <stdio.h>
#include "LoadFile.h"

struct MyFile
{
	int Users;
	int Files;
	int Transactions;
};


int main()
{
	struct MyFile myHeader;
	double s;
	myHeader = GetHeader("Dupa.txt");
	printf("%d\n", myHeader.Users);
	


}