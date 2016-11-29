#include "PriorQueue.h"
#include <stdio.h>
#include <stdlib.h>
void addToQueue(struct slistEl **head,int value, int weight)
{
	struct slistEl *q, *temp;
		q= malloc( sizeof(struct slistEl ) );
	    q->next = NULL;
	    q->data = value;
	    q->priority = weight;
	  
	    if(!*head)
	    {
	    	*head = q;
	    	//printf("after %p \n",*head);
	    }else{
	    /**  add to queue **/
		   	temp = *head;
		   	while(q->priority > temp->priority )
		   	{
		  		if(temp->next)
		   			{
		   				temp = temp->next;
		   			}else{printf("abreak\n"); break;}
		   	} 
		   	q->next    = temp->next;
		   	temp->next = q;		      	
		  
	    }
}

int takeFromQueue(struct slistEl **head)
{
	int retVal=0;
	struct slistEl  *temp;
	if(*head)
	{
		retVal=(*head)->data;
		temp=*head;
		*head=(*head)->next;
		free(temp);
		return retVal;
	}else
	{
		return -1;
	}
}

void showQueue(struct slistEl *head)
{
	struct slistEl  *temp; 
	temp = head;
	while(temp)
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}
}

int isEmpty(struct slistEl *head)
{
	if(!head) return 1;
	else return 0;
}