#include "Algorithms.h"
#include <stdlib.h>
#include <stdio.h>

int find(int i, int *parent)
{
	while (parent[i])
		i = parent[i];
	return i;
}
int uni(int i, int j, int *parent)
{
	if (i != j)
	{
		parent[j] = i;
		return 1;
	}
	return 0;
}

void kruskal(int **matrix, int size, int begin, int file, struct UserFile *userFile)
{
    int i, j, k, a, b, u, v, n = size, ne = 1;
    int min;
    int mincost = 0;
    int **cost;
    int *parent;

    int **resultMatrix;


    /**** Initialize ****/
    cost = (int **)malloc(sizeof(int*) * size);
    for(i = 0; i < size; i++)
    {
        cost[i] = (int *)malloc(sizeof(int) * size);
    }

    resultMatrix = (int **)malloc(sizeof(int*) * size);
    for(i = 0; i < 3; i++)
    {
        resultMatrix[i] = (int *)malloc(sizeof(int) * size);
    }

    parent = malloc(sizeof(int) * size);

    for(i = 0; i < size; i++)
    {
        for(j = 0; j < size; j++)
        {
            if(matrix[i][j] == 0)
            {
                cost[i][j] = 999;
            }
            else
            {
                cost[i][j] = matrix[i][j];
            }
        }
    }



    /**** Let's go ****/

    
    while(ne < size)
    {
        for(i = 0, min = 999; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u, parent);
        v = find(v, parent);

        if(uni(u, v, parent))
        {
            printf("\n%d edge (%d, %d) = %d\n", ne, a, b, min);
            resultMatrix[0][ne] = a;
            resultMatrix[1][ne] = b;
            resultMatrix[2][ne] = min;
            ne++;
            mincost += min;
        }
        cost[a][b] = cost[b][a] = 999;
    }

    printf("\nMinimum cost = %d\n", mincost);


    for(i = 0; i< 3; i++)
    {
        for(j = 1; j<ne; j++)
        {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");

    }

}