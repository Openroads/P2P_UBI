#pragma once
struct MyFile
{
	int Users;
	int Files;
	int Transactions;
};
struct MyFile getHeader(char *filename);

void getUserFile(int *readArray, char *filename,int startLine);
void getUserConnections(int *readArray,char *filename,int startLine,int endLine);
int countLineAmount(char *filename,int startLine);