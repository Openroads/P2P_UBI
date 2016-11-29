#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"

const int WEIGHT = 1;

struct slistEl
{
  struct slistEl * next;
  int data;
  int priority;
};

int prim(int **matrix, int size, int user, int file, struct UserFile *userFile)
{
	int i,j;
	int *visited  = malloc(sizeof (int) * size);
	for(i=0; i<size; ++i)
	  {
	  	visited[i] =0 ;
	  }

	struct slistEl *q, *head, *temp; 

	q = malloc(sizeof( slistEl ) );
	q->next = NULL;
	q->data = user;
	q->priority = WEIGHT;

	head=temp=q;
	visited[user] = 1;


	for(i=0;i<size;++i)
	{
		 for(j = 0; j < size; j++)
	      if((matrix[user][j] == 1) && !visited[i])
	      {
	      	q= malloc( sizeof(slistEl ) );
	      	q->next = NULL:
	      	q->data = j;
	      	q->priority = WEIGHT;
	      	/**  add to queue */
	      	temp = head;
	      	while(temp && q->priority > temp->priority )
	      	{
	      		temp = temp->next;
	      	} 
	      	q->next    = temp->next;
	      	temp->next = q;

	      }
	//  
	}



	return 1;
}