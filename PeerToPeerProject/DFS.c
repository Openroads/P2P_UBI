#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"

//typedef enum { false, true } bool;

int *visited;

void visit(int v, int size, int **matrix, int file, UserFile *userFile)
{
    visited[v] = 1;
    printf("%d ", v);

    int i;
    for(i = size - 1; i >= 0; i--)
    {
        if(matrix[v][i] && !visited[i])
            visit(i, size, matrix);
    }

}

void dfs(int **matrix, int size, int begin, int file,  UserFile *userFile)
{
    visited = malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
    {
        visited[i] = 0;
        printf("Zeruje: %i\n", i);
    }

    visit(begin, size, matrix, file, userFile); 
}