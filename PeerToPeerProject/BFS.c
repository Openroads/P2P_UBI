#include <stdio.h>
#include "Algorithms.h"

struct slistEl
{
  slistEl * next;
  int data;
};

	int n;                   // Liczba wierzchołków
	char ** A;               // Macierz sąsiedztwa
	bool * visited;          // Tablica odwiedzin

void bfs(int **matrix, struct UserFile *array,int size,int user, int file)
{
	  int *visited  = malloc(sizeof (int) * size);
	  int i;
	  slistEl *q,*head,*tail; // Kolejka

	  q = malloc(sizeof( slistEl ));        // W kolejce umieszczamy v
	  q->next = NULL;
	  q->data = user;
	  head = tail = q;

	  visited[user] = 1;      // Wierzchołek v oznaczamy jako odwiedzony

	  while(head)
	  {
	    user = head->data;       // Odczytujemy v z kolejki

	    q = head;             // Usuwamy z kolejki odczytane v
	    head = head->next;
	    if(!head) tail = NULL;
	    free(q);

	    printf("%d \n", user);

	    for(i = 0; i < size; i++)
	      if((matrix[user][i] == 1) && !visited[i])
	      {
	        q = malloc(sizeof( slistEl )); // W kolejce umieszczamy nieodwiedzonych sąsiadów
	        q->next = NULL;
	        q->data = i;
	        if(!tail) head = q;
	        else tail->next = q;
	        tail = q;
	        visited[i] = 1; // i oznaczamy ich jako odwiedzonych
	      }
	  }
}