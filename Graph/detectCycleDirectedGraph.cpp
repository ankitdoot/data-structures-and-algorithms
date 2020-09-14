#include<bits/stdc++.h> 
using namespace std; 
  
class Graph 
{
	int v;
	list<int> *adj;
	bool isCyclicUtil(int s, bool visited[], list<int>adj[]);
	public :
	Graph(int v);
	void addEdge(int u, int v);
	bool isCyclic();
};

Graph :: Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph :: addEdge(int u, int v)
{
	adj[u].push_back(v);
}

bool Graph :: isCyclicUtil(int s, bool visited[], list<int>adj[])
{
	visited[s] = true;
	list<int> :: iterator i;
	for(i = adj[s].begin();i != adj[s].end();i++)
	{
		if(!visited[*i])
		{
			if(isCyclicUtil(*i, visited, adj))
				return true;
			else visited[*i] = false;
		}

		else return true;
	}
	return false;
}

bool Graph :: isCyclic()
{
	bool *visited = new bool[v];
	for(int i = 0; i<v; i++)
		visited[i] = false;
	for(int i = 0;i<v;i++)
	{
		if(isCyclicUtil(i,visited,adj))
			return true;
		else visited[i] = false;
	}
	
	return false;
}

int main()
{
	Graph G(6);
	G.addEdge(0,1);
	G.addEdge(1,2);
	G.addEdge(0,2);
	G.addEdge(3,4);
	G.addEdge(4,5);
	G.addEdge(5,3);
	
	if(G.isCyclic())
		cout<<"Graph contains cycle"<<endl;
	else cout<<"Graph doesn't contains cycle"<<endl;
	return 0;
}
//refer video ::  https://www.youtube.com/watch?v=0dJmTuMrUZM
/*Time Complexity: O(V+E).
Time Complexity of this method is same as time complexity of DFS traversal which is O(V+E).
Space Complexity: O(V).
To store the visited and recursion stack O(V) space is needed.
*/
