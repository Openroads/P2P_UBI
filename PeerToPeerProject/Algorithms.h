#pragma once
struct UserFile
{
	int user;
	int *files;
	int fileAmount;
};


int dfs(int **matrix, int size, int begin, int file, struct UserFile *userFile);
void bfs(int **matrix, int size, int user, int file);

