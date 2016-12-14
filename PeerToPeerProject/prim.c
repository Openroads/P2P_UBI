#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"
#include "PriorQueue.h"

const int WEIGHT_PR = 1;

int prim(int **matrix, int size, int user, int file, struct UserFile *userFile)
{

	int length=0;
	int i,j;

	for(j=0;j<userFile[user].fileAmount;++j)
	  	{
	  		if(userFile[user].files[j] == file)
	  		{
	  			//printf("PRIM: User %d has file %d \n",user,file);
	  			return length;
	  		}
		}

	int *visited  = malloc(sizeof (int) * size);
	for(i=0; i<size; ++i)
	  {
	  	visited[i] =0 ;
	  }

	struct slistEl *headQueue; 
	headQueue = NULL;
	
	visited[user] = 1;


	for(i=1; i < size ;++i)
	{
		 for(j = 0; j < size; ++j)
	      if((matrix[user][j] == 1) && !visited[j])
	      {
	      	addToQueue(&headQueue,j,WEIGHT_PR);
	      }
	    
	    user = takeFromQueue(&headQueue);
	    
	    if(user >= 0)
	    {
		    length++;
		    visited[user] = 1;
		    if(user>0)
		    for(j=0;j<userFile[user].fileAmount;++j)
	  		{
	  			if(userFile[user].files[j] == file)
	  			{
	  				//printf("PRIM: User %d has file %d \n",user,file);
	  				return length;
	  			}
			}

	    }
	}
	return -1;
}