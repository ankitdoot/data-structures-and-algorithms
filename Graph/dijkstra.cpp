//Single source shortest path algorithm
//Time Complexity of below implementation is O(V^2).
#include<bits/stdc++.h>
using namespace std;
void printMinDis(int minDis[], int V)
{
	cout<<"Shortest Path"<<endl;
	cout<<"vertex\t\tdistance"<<endl;
	for(int i = 0; i < V; i++)
		cout<<i<<"\t\t"<<minDis[i]<<endl;
}

void dijkstra(vector< pair<int, int> >G[], int V, int E)
{
	bool *visited = new bool[V];
	int *minDis = new int[V];
	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		minDis[i] = INT_MAX;
	}
	minDis[0] = 0;
	int count = 0;
	while(count != V-1)
	{
		int currMin = INT_MAX;
		int minIndex;
		for(int i = 0; i < V; i++)
		{
			if(minDis[i] < currMin && visited[i] == false)
			{
				currMin = minDis[i];
				minIndex = i;
			}
		}
		visited[minIndex] = true;
		count++;
		for(int i = 0; i < G[i].size(); i++)
		{
			int x = G[minIndex][i].first;
			int y = G[minIndex][i].second;
			if(!visited[ x ] && minDis[minIndex] + y < minDis[x])
				minDis[x] = minDis[minIndex] + y;
		}
	}
	printMinDis(minDis, V);
}

int main()
{
	int V = 6,E = 8;
	vector< pair <int, int> >G[V];//(destNode, weight)
	G[0].push_back(make_pair(1, 4));
	G[0].push_back(make_pair(5, 8));
	
	G[1].push_back(make_pair(0, 4));
	G[1].push_back(make_pair(2, 8));
	G[1].push_back(make_pair(5, 11));
	
	G[2].push_back(make_pair(1, 8));
	G[2].push_back(make_pair(3, 2));
	
	G[3].push_back(make_pair(2, 2));
	G[3].push_back(make_pair(4, 6));
	G[3].push_back(make_pair(5, 7));
	
	G[4].push_back(make_pair(3, 6));
	G[4].push_back(make_pair(5, 1));
	
	G[5].push_back(make_pair(0, 8));
	G[5].push_back(make_pair(1, 11));
	G[5].push_back(make_pair(3, 7));
	G[5].push_back(make_pair(4, 1));
	
	dijkstra(G, V, E);
}
