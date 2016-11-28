#include <stdio.h>
#include <stdlib>



const int MAXINT = 2147483647;    // Największa liczba całkowita
const int WEIGHT = 1;

struct slistEl
{
  slistEl * next;
  int v,w;
};

// Zmienne globalne
int m,n;                          // Liczba krawędzi i wierzchołków w grafie
slistEl ** A;                     // Tablica dynamiczna list sąsiedztwa
long long * d;                    // Tablica kosztów dojścia
int * p;                          // Tablica poprzedników

int belmanFord(int **matrix, int size, int user, int file, struct UserFile *userFile)
{
  int *distTo   = malloc(sizeof(int)*size);
  int *predNode = malloc(sizeof(int)*size);
  int i,x;
  slistEl * pv;
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

  for(x = 0; x < size; ++x)
    for(j=0; j < size; ++j)
        if(matrix[x][j]==1){
        	if(d[j] > d[x] + WEIGHT) return -999; //negative cycle
        }
  	

  for(i=0 ; i< size ++i)
  {
  	predNode[i];
  }

  return true;
}

void relax(u,v,w,*d,*p)
{
	if(d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		p[v]=u; 
	}
}