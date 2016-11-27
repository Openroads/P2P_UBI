#pragma once
struct UserFile
{
	int user;
	int *files;
	int fileAmount;
};

void dfs(int **matrix, int size, int begin, int file, UserFile *userFile);
void bfs(int **matrix, int size, int user, int file);
