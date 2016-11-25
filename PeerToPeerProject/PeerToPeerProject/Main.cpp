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
	MyFile myHeader;
	double s;
	myHeader = GetHeader("Dupa.txt");

	scanf_s("lf", &s);


}