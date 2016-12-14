#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"

struct slistEl
{
  struct slistEl * next;
  int data;
};

int bfs(int **matrix, int size,int user, int file, struct UserFile *userFile)
{	  
	int length = -1;
	int i;
	int *visited  = malloc(sizeof (int) * size);
	  for(i=0; i<size; ++i)
	  {
	  	visited[i] =0 ;
	  }
	struct slistEl *q, *head, *tail; 

	  q = malloc(sizeof( struct slistEl ));
	  q->next = NULL;
	  q->data = user;
	  head = tail = q;

	  visited[user] = 1;

	  while(head)
	  {
	  	/** next user in bfs  **/
	    user = head->data;
	    length++;
 		//printf("N %d \n",user );
  		for(i=0;i<userFile[user].fileAmount;++i)
  		{
  			if(userFile[user].files[i] == file)
  			{
  				//printf("BFS: User %d has file %d \n",user,file);
  				free(visited);
  				return length;
  			}
  		}


	    q = head;             //deleted from queue
	    head = head->next;
	    if(!head) tail = NULL;
	    free(q);

	    for(i = 0; i < size; i++)
	      if((matrix[user][i] == 1) && !visited[i])
	      {
	        q = malloc(sizeof(struct  slistEl ));
	        q->next = NULL;
	        q->data = i;
	        if(!tail) head = q;
	        else tail->next = q;
	        tail = q;
	        visited[i] = 1;
	      }
	  }
	  return -1;
}