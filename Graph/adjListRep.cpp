//Adjecency List Representation of graph
#include<iostream>
#include<vector>
using namespace std;

void addEdge(vector<int>adj[], int u,int v)
{
	adj[v].push_back(u);
	adj[u].push_back(v);
}

void printGraph(vector<int>adj[],int v)
{
	for(int i=0;i<v;i++)
	{
		 cout<<"\nAdjacency list of vertex "<<i<<"\n head "; 
        for(auto x : adj[i]) 
           cout<<"-> "<< x; 
        printf("\n");
	}
}

int main()
{
	int v = 5;//No of vertices
	vector<int>adj[v];
	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	printGraph(adj,5);
}
/*
Pros: Saves space O(|V|+|E|) . In the worst case, there can be C(V, 2) number of edges in a graph thus consuming O(V^2) space. Adding a vertex is easier.
Cons: Queries like whether there is an edge from vertex u to vertex v are not efficient and can be done O(V).
*/

