#include <stdio.h>
#include <stdlib.h>

typedef enum { false, true } bool;

bool *visited;

void visit(int v, int size, int **matrix)
{
    visited[v] = true;
    printf("%d ", v);

    int i;
    for(i = size; i >= 0; i--)
    {
        if(matrix[v][i] && !visited[i])
            visit(i, size, matrix);
    }

}

void dfs(int **matrix, int size, int begin)
{
    visited = malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++)
    {
        visited[i] = false;
    }

    visit(begin, size, matrix); 
}