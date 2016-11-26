#pragma once
struct MyFile
{
	int Users;
	int Files;
	int Transactions;
};
struct MyFile getHeader(char *filename);

void getUserFile(int *readArray, char *filename,struct MyFile header);