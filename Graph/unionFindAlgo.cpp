#include<iostream>
#include<utility>
#include<vector>
using namespace std;

int findSet(int parent[], int u)
{
	if(parent[u] == -1)
		return u;
	return findSet(parent, parent[u]);
}

void doUnion(int parent[], int p1, int p2)
{
	parent[p1] = p2;
}

bool isCyclic(int v, int E, vector< pair <int, int> >G)
{
	int *parent = new int[v];
	for(int i = 0; i < v; i++)
		parent[i] = -1;
	for(int i = 0; i < E; i++)
	{
		int p1 = findSet(parent, G[i].first);
		int p2 = findSet(parent, G[i].second);
		if(p1 == p2)
			return true;
		doUnion(parent, p1, p2);
	}
	return false;
}

int main()
{
	int V = 3, E = 3;
	vector< pair <int, int> >G;
	G.push_back(make_pair(0, 1));
	G.push_back(make_pair(1, 2));
	G.push_back(make_pair(0, 2));
	if(isCyclic(V, E, G))
		cout<<"Cycle Present"<<endl;
	else cout<<"Cycle not Present"<<endl;
}

