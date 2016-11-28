#pragma once
struct UserFile
{
	int user;
	int *files;
	int fileAmount;
};


int dfs(int **matrix, int size, int begin, int file, struct UserFile *userFile);
int bfs(int **matrix, int size, int user, int file, struct UserFile *userFile);

