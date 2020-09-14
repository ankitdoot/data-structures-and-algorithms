//https://cses.fi/problemset/task/1635/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	int x;//desired sum
	cin>>N>>x;
	vector<int> v(N);
	const unsigned int M = 1000000007;
	for(int i = 0; i < N; i++)
	{
		cin>>v[i];
	}
	int dp[x + 1];
	
	dp[0] = 1;//No of ways to make sum 0
	for(int sum = 1; sum <= x; sum++)
	{
		dp[sum] = 0;
		for(int coin_value : v)
		{
			if(coin_value <= sum)
			{
				dp[sum] = (dp[sum] + dp[sum - coin_value])%M;
			}
		}
		
	}
	cout<<dp[x]<<"\n";
}

//time complexity O(NX).
//space complexity O(X)