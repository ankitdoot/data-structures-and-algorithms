#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
	int src;
	int dest;
	int weight;
};
int findParent(int parent[], int node)
{
	if(parent[node] == node)
		return node;
	else return findParent(parent, parent[node]);
}


bool compare(Edge first, Edge second)
{
	return first.weight < second.weight;
}

void minimumSpanningTree(Edge input[], int V, int E)
{
	//we will pick edge one by one as per their weight,so sorting is done
	sort(input, input+E, compare);
	Edge *Output = new Edge[V-1];	
	int *parent = new int[V];
	for(int i = 0; i < V;i++)
		parent[i] = i;
	int count = 0;
	int i=0;
	while(count != V-1)
	{
		Edge currentEdge = input[i];
		int sourceParent = 	findParent(parent, currentEdge.src);
		int destParent = findParent(parent, currentEdge.dest);
		if(sourceParent != destParent)//checking that by adding that edge cycle is being introduced on not,if not, then add that edge
		{
			Output[count] = currentEdge;
			parent[sourceParent] = destParent;
			count++;
		}
		i++;
	}
	//Printing minimum spanning tree
	for(int i=0;i<V-1;i++)
	{
		if(Output[i].src < Output[i].dest)
			cout<<Output[i].src<<" "<<Output[i].dest<<" "<<Output[i].weight<<endl;
		else cout<<Output[i].dest<<" "<<Output[i].src<<" "<<Output[i].weight<<endl;
	}
}

int main()
{
	int V,E;cin>>V>>E;
	Edge *input = new Edge[E];
	for(int i = 0; i < E; i++)
	{
		cin>>input[i].src;
		cin>>input[i].dest;
		cin>>input[i].weight;
	}
	minimumSpanningTree(input, V, E);
}
//Its a greedy algorithm
