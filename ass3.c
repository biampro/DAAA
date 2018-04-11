//====================================================================
// Name    	    : Bellman Ford
// Author  	    : Suraj Pagade   (Roll no : 65)
// Assignment    : 3
//===================================================================
//Source code :
#include <stdio.h>
#include <stdlib.h>


int Bellman_Ford(int G[20][20], int V, int E, int edge[20][2])
{
	int i, u, v, k, S, distance[20], parent[20], flag=1;
    
	for(i=0;i<V;i++)
	{
    	distance[i] = 1000 , parent[i] = -1 ;
	}
    
	printf("\nEnter source: ");
	scanf("%d",&S);
	printf("\n");
	distance[S-1]=0 ;
    
	for(i=0;i<V-1;i++)
	{
    	for(k=0;k<E;k++)
    	{
        	u = edge[k][0] , v = edge[k][1] ;
        	if(distance[u]+G[u][v] < distance[v])
       		 distance[v] = distance[u] + G[u][v] , parent[v]=u ;
    	}
	}
    
	for(k=0;k<E;k++)
	{
    	u = edge[k][0] , v = edge[k][1] ;
    	if(distance[u]+G[u][v] < distance[v])
   		 flag = 0 ;
	}
    
	if(flag)
    	for(i=0;i<V;i++)
   		 printf("Vertex %d -> cost = %d parent = %d\n",i+1,distance[i],parent[i]+1);

	return flag;
}


int main()
{
	int V, edge[20][2], G[20][20], i, j, k=0;

	printf("\nEnter number of vertices : ");
	scanf("%d",&V);
	printf("\nEnter graph :\n\n");
	for(i=0;i<V;i++)
    	for(j=0;j<V;j++)
    	{
   		 printf("Distance from node %d to %d : ", i+1, j+1);
        	scanf("%d",&G[i][j]);
        	if(G[i][j]!=0)
            	edge[k][0]=i,edge[k++][1]=j;
    	}

	if(Bellman_Ford(G,V,k,edge))
	{
    	printf("\nNo negative weight cycle\n\n");
	}
	else
	{
   	 printf("\nNegative weight cycle exists\n\n");
	}
    
	return 0;
}


/*
Output
student@student-ThinkCentre-M57e:~$ gcc ford.c -o out
student@student-ThinkCentre-M57e:~$ ./out

Enter number of vertices : 4

Enter graph :

Distance from node 1 to 1 : 0
Distance from node 1 to 2 : 9
Distance from node 1 to 3 : 12
Distance from node 1 to 4 : 0
Distance from node 2 to 1 : 6
Distance from node 2 to 2 : 0
Distance from node 2 to 3 : 0
Distance from node 2 to 4 : -1
Distance from node 3 to 1 : 16
Distance from node 3 to 2 : 0
Distance from node 3 to 3 : 0
Distance from node 3 to 4 : 2
Distance from node 4 to 1 : 3
Distance from node 4 to 2 : 0
Distance from node 4 to 3 : 0
Distance from node 4 to 4 : 0

Enter source: 1

Vertex 1 -> cost = 0 parent = 0
Vertex 2 -> cost = 9 parent = 1
Vertex 3 -> cost = 12 parent = 1
Vertex 4 -> cost = 8 parent = 2

No negative weight cycle

*/

