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
	int v = 6;
	addEdge(1,2);
	addEdge(2,3);
	addEdge(1,3);
	addEdge(5,4);
	int components = 0;
	cout<<"Each Component of graph is : "<<endl;
	for(int i=0;i<v;i++)
	{
		if(!visited[i])
		{
			DFS(i);
			cout<<endl;
			components++;
		}
	}
	cout<<"Total Connected Components in graph is : "<<components<<endl;
}
