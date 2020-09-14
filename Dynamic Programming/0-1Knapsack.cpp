
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N,weight;
	cin>>N>>weight;
	vector<int>value(N+1);
	for(int i = 1; i <= N; i++)
	{
		cin>>value[i];
	}
	vector<int>w(N+1);
	for(int i = 1; i <= N; i++)
	{
		cin>>w[i];
	}
	int dp[N+1][weight+1];
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= weight; j++)
		{
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(w[i] <= j)
			{
				dp[i][j] = max(dp[i-1][j], value[i] + dp[i-1][j-w[i]]);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}
	cout<<dp[N][weight]<<"\n";
}
//time complexity O(NW).
//space complexity O(NW)
