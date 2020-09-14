#include<iostream>
using namespace  std;

int adjMatrix[20][20];

void addEdge(int adjMatrix[20][20], int u, int v)
{
	adjMatrix[u][v] = 1;
	adjMatrix[v][u] = 1;
}

void printGraph(int adjMatrix[20][20], int v)
{
	for(int i=1;i<=v;i++)
	{
		for(int j=1;j<=v;j++)
		{
			cout<<adjMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int v = 5;
	addEdge(adjMatrix, 1, 2);
	addEdge(adjMatrix, 1, 3);
	addEdge(adjMatrix, 1, 4);
	addEdge(adjMatrix, 1, 5);
	addEdge(adjMatrix, 2, 3);
	addEdge(adjMatrix, 2, 4);
	addEdge(adjMatrix, 3, 4);
	addEdge(adjMatrix, 4, 5);
	printGraph(adjMatrix, v);
}
//Pros : Removing an edge takes O(1) time. Queries like whether there is an edge from vertex ‘u’ to vertex ‘v’ 
//       are efficient and can be done O(1).
//Cons: Consumes more space O(V^2). Even if the graph is sparse(contains less number of edges), it consumes the same space.
//      Adding a vertex is O(V^2) time.
