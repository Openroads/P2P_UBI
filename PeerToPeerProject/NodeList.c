#include "NodeList.h"
#include <stdio.h>
#include <stdlib.h>

void addNodeToList(struct listEl **head,struct Node *value)
{
	struct listEl *q, *temp;
		q= malloc( sizeof(struct listEl ) );
	    q->next = NULL;
	    q->data = value;
	  
	    if(!*head)
	    {
	    	*head = q;
	    	//printf("after %p \n",*head);
	    }else{
	    /**  add to queue **/
		   	temp = *head;
		
			while(temp->next)
			{
			   	temp = temp->next;
			} 
			q->next    = temp->next;
			temp->next = q;		      	
		  	}
}

struct Node *getFirstNode(struct listEl **head)
{
	struct Node *retVal = NULL;
	struct listEl  *temp;
	if(*head)
	{
		retVal	=	(*head)->data;
		temp	=	*head;
		*head	=	(*head)->next;
		free(temp);
		return retVal;
	}else
	{
		return retVal;
	}
}

void showNodeList(struct listEl *head)
{
	struct listEl  *temp; 
	temp = head;
	while(temp)
	{
		printf(" %d ",temp->data->user);
		temp=temp->next;
	}
}

int isNodeListEmpty(struct listEl *head)
{
	if(!head) return 1;
	else return 0;
}

int isNodeInList(struct listEl *head,struct Node *value)
{
	struct listEl  *temp; 

	temp = head;
	while(temp)
	{
		if(temp->data->user == value->user) return 1;
		temp=temp->next;
	}

	return 0;
}