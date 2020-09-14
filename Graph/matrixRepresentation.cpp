//Adjecency Matrix Representation of graph
#include<iostream>
using namespace std;

void addEdge(int adjMatrix[][5],int src, int dest)
{
	adjMatrix[src][dest] = 1;//For Directed Grpah
}

void printAdjMatrix(int adjMatrix[][5], int vertices)
{
	for(int i=0;i<vertices;i++)
	{
		for(int j=0;j<vertices;j++)
		{
			cout<<adjMatrix[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	int nodes = 5;//No of Nodes
	int adjMatrix[5][5] = {};
	addEdge(adjMatrix,0,1);
	addEdge(adjMatrix,0,2);
	addEdge(adjMatrix,0,3);
	addEdge(adjMatrix,1,1);
	addEdge(adjMatrix,1,3);
	addEdge(adjMatrix,2,3);
	addEdge(adjMatrix,2,4);
	
	printAdjMatrix(adjMatrix, 5);
}
/*
Pros: Representation is easier to implement and follow. Removing an edge takes O(1) time. Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ are efficient and can be done O(1).

Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space. Adding a vertex is O(V^2) time.
*/
