#include<bits/stdc++.h>
using namespace std;

#define V 6

int findKey(int key[], bool mstSet[])
{
	int minIndex;
	int keyMin = INT_MAX;
	for(int i = 0; i < V; i++)
	{
		if(key[i] < keyMin && mstSet[i] == false)
				minIndex = i;
	}
	return minIndex;
}

void printMST(int parent[], int graph[V][V]) 
{ 
	cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < V; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

void primMST(int graph[V][V]){
	int parent[V];
	int key[V];
	bool mstSet[V];
	for(int i = 0; i < V; i++)
	{
		key[i] = INT_MAX; mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	for(int i = 0; i < V; i++)
	{
		int u = findKey(key, mstSet);
		mstSet[u] = true;
		for(int i = 0; i < V; i++)
		{
			if(graph[u][i] && mstSet[i] == false && graph[u][i]  < key[i])
			{
				parent[i] = u;
				key[i] = graph[u][i];
			}
		}
	}
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0, 1, 0, 0, 2, 0}, 
						{ 1, 0, 0, 0, 5, 0}, 
						{ 4, 0, 0, 0, 3, 0}, 
						{ 0, 0, 0, 0, 6, 8}, 
						{ 2, 5, 3, 6, 0, 7},
                        {0, 0, 0, 8, 7, 0} }; 
   primMST(graph);
   return 0;
}
//It is a greed algorithm
//Time complexity O(V^2)
//	If the input graph is represented using adjacency list,
//	then the time complexity of Prim’s algorithm can be reduced to O(E log V) with the help of binary heap. 


