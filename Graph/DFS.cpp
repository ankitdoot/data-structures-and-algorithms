#include<iostream>
#include<vector>
using namespace std;

vector<int>adj[10];
vector<bool>visited(10,0);

void addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void DFS(int s)
{
	visited[s] = 1;
	cout<<s<<" ";
	for(int i=0;i<adj[s].size();i++)
	{
		if(!visited[adj[s][i]])
		{
			DFS(adj[s][i]);
		}
	}
}

int main()
{
	int v = 5;
	addEdge(0,4);
	addEdge(1,2);
	addEdge(1,3);
	addEdge(1,4);
	addEdge(2,4);
	addEdge(3,4);
	
	DFS(0);
}
//Time Complexity of DFS is O(V+E)
//Auxillary Space Complexity: O(V).
//Since, an extra visited array is needed of size V.
