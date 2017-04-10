#include "List.h"
#include <stdio.h>
#include <stdlib.h>

void addToList(struct listEl **head,int value)
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

int dropFirst(struct listEl **head)
{
	int retVal=0;
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
		return -1;
	}
}

void showList(struct listEl *head)
{
	struct listEl  *temp; 
	temp = head;
	while(temp)
	{
		printf(" %d ",temp->data);
		temp=temp->next;
	}
}

int isEmpty(struct listEl *head)
{
	if(!head) return 1;
	else return 0;
}

int isInList(struct listEl *head,int value)
{
	struct listEl  *temp; 

	temp = head;
	while(temp)
	{
		if(temp->data == value) return 1;
		temp=temp->next;
	}

	return 0;
}