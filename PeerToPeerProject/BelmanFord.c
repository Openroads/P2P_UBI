#include <stdio.h>
#include <stdlib.h>
#include "Algorithms.h"



const int MAXINT = 2147483647;    // Największa liczba całkowita
const int WEIGHT = 1;


void relax(int  u,int v,int w,int *d,int *p);
// Zmienne globalne
int m,n;                          // Liczba krawędzi i wierzchołków w grafie
long long * d;                    // Tablica kosztów dojścia
int * p;                          // Tablica poprzedników

int belmanFord(int **matrix, int size, int user, int file, struct UserFile *userFile)
{
  int *distTo   = malloc(sizeof(int)*size);
  int *predNode = malloc(sizeof(int)*size);
  int i,j,x;
  
  /***  Initialization ***/
  for(i=0; i<size; i++)
  {
  	distTo[i] 	= MAXINT;
  	predNode[i]	=-1;
  }
  distTo[user] = 0;   
  /**********************/


  for(i = 1; i < size; ++i)
  {
    for(x = 0; x < size-1; x++)
      for(j=0; j < size; ++j)
        if(matrix[x][j]==1){
        	relax(x,j,WEIGHT,distTo,predNode);
  		}
  }
  for(x = 0; x < size; ++x)
    for(j=0; j < size; ++j)
        if(matrix[x][j]==1){
        	if(d[j] > d[x] + WEIGHT) return -999; //negative cycle
        }
  	

  for(i=0 ; i< size; ++i)
  {
  	predNode[i];
  }

  return 2;
}

void relax(int  u,int v,int w,int *d,int *p)
{
	if(d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		p[v]=u; 
	}
}