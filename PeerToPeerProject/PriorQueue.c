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
		   	if(q->priority <= temp->priority)
		   	{
		   		q->next=temp;
		   		*head = q;
		   	}else{
			   	while(temp->next && q->priority > temp->next->priority )
			   	{
			   		temp = temp->next;
			   	} 
			   	q->next    = temp->next;
			   	temp->next = q;		      	
		  	}
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

int isInQueue(struct slistEl *head,int value)
{
	struct slistEl  *temp; 

	temp = head;
	while(temp)
	{
		if(temp->data == value) return 1;
		temp=temp->next;
	}

	return 0;
}