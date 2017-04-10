#include "Algorithms.h"
#include "NodeQueue.h"
#include "NodeList.h"
#include <stdlib.h>
#include <stdio.h>


int astar(int **matrix, int size, int begin, int file, struct UserFile *userFile)
{
	struct slistEl *headQueueOL;
	struct listEl *headListCL;
	struct Node *startNode = malloc( sizeof(struct Node) );
	startNode->user=begin;
	headListCL = NULL; 
	headQueueOL = NULL;
	// first weight 0 
	startNode->f=0;
	startNode->g=0;
	startNode->h=0;
	addNodeToQueue(&headQueueOL,startNode,0);
	int i ,j;

	struct Node *theBestNext ;
	int heuristicVal =0;


	while(!isEmptyNodeQueue(headQueueOL))
	{
		theBestNext = takeNodeFromQueue(&headQueueOL);
		addNodeToList(&headListCL,theBestNext);

		for(j=0;j<userFile[theBestNext->user].fileAmount;++j)
	  	{
	  		if(userFile[theBestNext->user].files[j] == file)
	  		{
	  			//printf("Astar: User %d has file %d \n",theBestNext->user,file);
	  			return theBestNext->f;
	  		}
		}

		for(i=0; i<size; ++i)
		{
			if(matrix[theBestNext->user][i]==1)
			{
				struct Node *n = malloc( sizeof(struct Node));
				n->user = i;
				if(isNodeInList(headListCL,n))
				{

				}
				else if(!isNodeInQueue(headQueueOL,n))
				{
					heuristicVal = dijkstra(matrix, size, n->user, file, userFile);
					n->h = heuristicVal;
					n->g = theBestNext->f+1;
					n->f= heuristicVal + n->g;
					addNodeToQueue(&headQueueOL,n,n->f);

				}else
				{
					int newG = theBestNext->f+1;
					if(newG < n->g)
					{
						heuristicVal = dijkstra(matrix, size, n->user, file, userFile);
						n->f= heuristicVal + n->g;
						addNodeToQueue(&headQueueOL,n,n->f);
					}
					
				}
			}

		}
	}
    return 0;
}