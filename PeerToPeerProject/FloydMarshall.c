#include "Algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#define INF 2147483647

int **d, **p;
int n, m;


void show(int **matrix, int size)
{
    int i, j;

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fWPath(int i, int j)
{
    if(i == j)
    {
        printf("%d ", i);
    }
    else if(p[i][j] == -1)
    {
        printf("No path\n");
    } 
    else
    {
        fWPath(i, p[i][j]);
        printf("%d ", j);
    }
}

void initialization(int **matrix, int size)
{
    d = (int**)malloc(sizeof(int*) * size);
    p = (int**)malloc(sizeof(int*) * size);
    int i, j;
    for(i = 0; i < size; i++)
    {
        d[i] = (int *)malloc(sizeof(int) * size);
        p[i] = (int *)malloc(sizeof(int) * size);
    }



    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(i == j)
            {
                d[i][j] == 0;
            }
            else if(matrix[i][j] == 0)
            {
                d[i][j] = INF;
            } 
            else
            {
                d[i][j] = matrix[i][j];
            }
            
            p[i][j] = -1;
        }
    }
}

int floydM(int size)
{
    int i, j, k, w;

    for(k = 0; k < size; k++)
    {
        for(i = 0; i < size; i++)
        {
            for(j = 0; j < size; j++)
            {
                if(d[i][k] == INF || (d[k][j] == INF)) continue;
                w = d[i][k] + d[k][j];
                if(d[i][j] > w)
                {
                    d[i][j] = w;
                    p[i][j] = p[k][j];
                }
            }
        }
    }

    for(i = 0; i < size; i++)
    {
        if(d[i][i] < 0) return 0;
    }
    return 1;
}


void floydMarshall(int **matrix, int size, int begin, int file, struct UserFile *userFile)
{
    initialization(matrix, size);
    //show(d, size);

    int i, j;
    if(floydM(size))
    {
        for(i = 0; i < size; i++)
        {
            printf("%d - %d: ", i, j);
            fWPath(i, j);
            if(d[i][j] < INF) printf("$ %d\n", d[i][j]);
        }
    }
    else
    {
        printf("Negative cycle found\n");
    }
}