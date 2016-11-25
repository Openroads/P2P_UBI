#pragma once
struct MyFile
{
	int Users;
	int Files;
	int Transactions;
};
struct MyFile getHeader(char *filename);

int * getUserFile(char *filename,struct MyFile header);