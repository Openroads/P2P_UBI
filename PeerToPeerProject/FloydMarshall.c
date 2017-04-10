#include "Algorithms.h"
#include <stdlib.h>
#include <stdio.h>
#define INF 2147483647


int **d, **p;

void initialization(int **matrix, int size)
{
    int i,j;

    d = (int**)malloc(sizeof(int*) * size);
    p = (int**)malloc(sizeof(int*) * size);
    
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
            
            p[i][j] = 0;
        }
    }
}

void FloydWasrhall(int size)
{
    int k, i, j;
	for(k = 0; k < size; k++)
	{
		for(i = 0; i < size; i++)
		{
			for(j = 0; j < size; j++)
			{
				if(d[i][k] != INF && d[j][k] != INF && (d[i][k] + d[k][j] < d[i][j]))
				{
					d[i][j] = d[i][k] + d[k][j];
					p[i][j] = k;
				}
			}
		}
	}
}


int floydWarshall(int **matrix, int size, int begin, int file, struct UserFile *userFile)
{
    int i, j;
    
    for(j=0;j<userFile[begin].fileAmount;++j)
        {
            if(userFile[begin].files[j] == file)
            {
                //printf("PRIM: User %d has file %d \n",user,file);
                return 0;
            }
        }
    initialization(matrix, size);
    FloydWasrhall(size);
    

  for (i = 0; i < size; i++) 
  {
		for (j = 0; j < size; j++) 
        {
            if(i == begin)
            {
                if(hasFile(j, file, size, userFile))
                {
                    return d[i][j];
                }
            }
		}
	}

    return -1;   
}