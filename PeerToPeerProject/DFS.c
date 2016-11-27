#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"

//typedef enum { false, true } bool;

int *visited;

int visit(int v, int size, int **matrix, int file, struct UserFile *userFile, int counter)
{
    visited[v] = 1;
    int k;
    for(k = 0; k < size; k++)
    {
        if(userFile[k].user == v)
        {
            int j;
            for(j = 0; j < userFile[k].fileAmount; j++)
            {
                if(userFile[k].files[j] == file)
                {
                    return counter;
                }
            }
        }
    } 

    int i;
    for(i = size - 1; i >= 0; i--)
    {
        if(matrix[v][i] && !visited[i])
        {
            return visit(i, size, matrix, file, userFile, counter + 1);
        }
            
    }

    //return 0;

}

int dfs(int **matrix, int size, int begin, int file,  struct UserFile *userFile)
{
    visited = malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
    {
        visited[i] = 0;
    }

    return visit(begin, size, matrix, file, userFile, 1); 
}