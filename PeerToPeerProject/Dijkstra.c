#include "Algorithms.h"

int *path;
int *previous;
int *visited;

int macierz[3][3] =
{
	0, 2, 3,
	2, 0, 4,
	3, 4, 0
};

void initialize(int size)
{

    path = malloc(sizeof(int) * size);
    previous = malloc(sizeof(int) * size);
    visited = malloc(sizeof(int) * size);

    previous[0] = -1;

    int i;
    for(i = 0; i < size; i++)
    {
        path[i] = 100;
        visited[i] = 0;
        if(i > 0)
        {
            previous[i] = 100;
        }
    }
}

int min(int size)
{
    int mini = 1000;
    int coordinate;

    int i;
    for(i = 0; i < size; i++)
    {
        if((mini > path[i]) && visited[i] != 1)
        {
            mini = path[i];
            coordinate = i;
        }
    }

    path[coordinate] = mini;
    visited[coordinate] = 1;
    return coordinate;
}

void relex(int u, int v, int **matrix)
{
    if(path[v] > path[u] + matrix[u][v])
    {
        path[v] = path[u] + matrix[u][v];
        previous[v] = u;
    }
}

void wypisz(int size)
{
    printf("\nPath: \n");
    int i;
    for(i = 0; i < size; i++)
    {
        printf("%4d ", path[i]);
    }

    printf("\nPrevious: \n");
    for(i = 0; i < size; i++)
    {
        printf("%4d ", previous[i]);
    }

}

int hasFile(int v, int file, int size, struct UserFile *userFile)
{
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
                    return 1;
                }
            }
        }
    }
    return 0;
}

int checking(int size, int file, struct UserFile *userFile)
{ 
    int i = 0;
    int flag = 0;
    while(1)
    {
        int j;
        for(j = 0; j < size; j++)
        {
            if(i == path[j])
            {
                int has = hasFile(j, file, size, userFile);
                if(has == 1)
                {
                    flag = 1;
                    return i;
                }
            }
        }
        if(flag == 1 || i > 10000)
        {
            break;
        }
        i++;
    }
    return -1;

}

int dijkstra(int **matrix, int size, int begin, int file, struct UserFile *userFile)
{
    initialize(size);

    
    int u;

    path[begin] = 0;
    previous[begin] = -1;

    int i;
    for(i = 0; i < size; i++)
    {
        u = min(size);
        int j;
        for(j = 0; j < size; j++)
        {
            if(matrix[u][j] > 0)
            {
                relex(u, j, matrix);
            }
        }
    }

    

    //wypisz(size);

    int result = checking(size, file, userFile);
}

