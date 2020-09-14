#include<bits/stdc++.h>
using namespace std;
class Graph{
	int v;
	list<int> *adj;
	bool isCyclicUtil(int s,bool visited[],int parent);
	public :
	Graph(int v);
	void addEdge(int u,int v);
	bool isCyclic();
};

Graph :: Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph :: addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

bool Graph :: isCyclicUtil(int s, bool visited[], int parent)
{
	visited[s] = true;
	list<int> :: iterator i;
	for(i = adj[s].begin();i != adj[s].end();++i)
	{
		if(!visited[*i])
		{
			if(isCyclicUtil(*i,visited,s))
				return true;
		}
		else if(*i != parent)
			return true;
	}
	return false;
}

bool Graph :: isCyclic()
{
	bool *visited = new bool[v];
	for(int i = 0;i<v;i++)
		visited[i] = false;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			if(isCyclicUtil(i,visited,-1));
				return true;
		}
	}
	return false;
}

int main()
{
	Graph G(4);
	G.addEdge(0,1);
	G.addEdge(1,2);
	G.addEdge(0,2);
	G.addEdge(0,3);
	if(G.isCyclic())
		cout<<"Cycle Found \n";
	else cout<<"Cycle not Found \n";
}

/*Time Complexity: O(V+E).
The program does a simple DFS Traversal of the graph which is represented using adjacency list. So the time complexity is O(V+E).
Space Complexity: O(V).
To store the visited array O(V) space is required.*/

