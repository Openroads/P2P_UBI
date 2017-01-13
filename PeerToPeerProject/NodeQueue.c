#include "NodeQueue.h"
#include <stdio.h>
#include <stdlib.h>

void addNodeToQueue(struct slistEl **head,struct Node *value, int weight)
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

struct Node* takeNodeFromQueue(struct slistEl **head)
{
	struct Node *retVal = NULL;
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
		return retVal;
	}
}

void showNodeQueue(struct slistEl *head)
{
	struct slistEl  *temp; 
	temp = head;
	while(temp)
	{
		printf(" %d ",temp->data->user);
		temp=temp->next;
	}
}

int isEmptyNodeQueue(struct slistEl *head)
{
	if(!head) return 1;
	else return 0;
}

int isNodeInQueue(struct slistEl *head,struct Node *value)
{
	struct slistEl  *temp; 

	temp = head;
	while(temp)
	{
		if(temp->data->user == value->user) return 1;
		temp=temp->next;
	}

	return 0;
}