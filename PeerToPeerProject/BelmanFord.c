#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"



const int MAXINT = 2147483645;    // Największa liczba całkowita
const int WEIGHT = 1;


void relax(int  u,int v,int w,int *d,int *p);

int belmanFord(int **matrix, int size, int user, int file, struct UserFile *userFile)
{
  int *distTo   = malloc(sizeof(int)*size);
  int *predNode = malloc(sizeof(int)*size);
  int i,j,x;
  
  /***  Initialization ***/
  for(i=0; i<size; i++)
  {
  	distTo[i] 	= MAXINT;
  	predNode[i]	=-1;
  }
  distTo[user] = 0;   
  /**********************/

  for(i = 1; i < size-1; ++i)
  {
    for(x = 0; x < size; x++)
      for(j=0; j < size; ++j)
        if(matrix[x][j]==1){
        	relax(x,j,WEIGHT,distTo,predNode);
  		}
  }
  
  for(x = 0; x < size; x++)
   { 
   	for(j=0; j < size; ++j)
        if(matrix[x][j]==1){
        	if(distTo[x] > distTo[j] + WEIGHT){free(distTo); free(predNode); return -999;} //negative cycle
        }
  	}

  int shortPath =0;
  while(1)
  {
  	for(i=0 ; i< size; ++i)
	  {
	  	if(distTo[i]==shortPath)
	  		{
	  			for(j=0;j < userFile[i].fileAmount; ++j)
	  			{
		  			if(userFile[i].files[j] == file)
		  			{
		  				//printf("BELMAN FORD: User %d, has file %d \n", i,file);
              free(distTo); free(predNode);
		  				return shortPath;
		  			}
	  			} 
	  		}	  	
	  }
	shortPath++;
}
free(distTo); free(predNode);
return -1;
}

void relax(int  u,int v,int w,int *d,int *p)
{
	if(d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		p[v]=u; 
	}
}
