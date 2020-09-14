#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>adj[5];

void addEdge(vector<int>adj[5], int u,int v)
{
	adj[v].push_back(u);
	adj[u].push_back(v);
}

void BFS(vector<int>adj[5],int v)
{
	vector<bool>visited(v,false);
	queue<int>q;
	q.push(0);
	visited[0] = true;
	while(!q.empty())
	{
		int x =  q.front();
		cout<<x<<" ";
		q.pop();
		for(int i=0;i<adj[x].size();i++)
		{
			if(!visited[adj[x][i]])
				q.push(adj[x][i]);
			visited[adj[x][i]] = true;
		}
	}
}

int main()
{
	int v = 5;
	addEdge(adj,0,1);
	addEdge(adj,0,4);
	addEdge(adj,1,2);
	addEdge(adj,1,3);
	addEdge(adj,1,4);
	addEdge(adj,2,3);
	addEdge(adj,3,4);
	BFS(adj,v);
}
