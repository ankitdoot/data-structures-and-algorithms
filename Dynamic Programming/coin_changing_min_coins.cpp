#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;//No of coins
	cin>>N;
	int sum;
	cin>>sum;
	vector<int> value(N);
	for(int i = 0; i < N; i++)
	{
		cin>>value[i];
	}
	
	int dp[sum+1];		//stores min no of coins for sum i
	dp[0] = 0;
	
	//stores the index of value used at index i in dp[] array, 
	//will help to retrive all coins used for coin_changing using min coins. 
	int index[sum+1];
	
	
	for(int i = 1; i <= sum; i++)
	{
		dp[i] = INT_MAX - 1;
		index[i] = -1;
	}
		
	for(int i = 0; i < N; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			if(j >= value[i] && (1 + dp[j-value[i]]) < dp[j])
			{
				dp[j] = 1 + dp[j-value[i]];
				index[j] = i;
			}
		}
	}
	
	if(dp[sum] == INT_MAX -1)
		cout<<"coin changing not possible"<<"\n";
	else cout<<"min coins required for coin change is "<<dp[sum]<<"\n";
	
	//find all coins used for coin_changing using min coins
	cout<<"all coins used for coin_changing are ";
	int total = sum;
	if(index[total] != -1)
	{
		while(total != 0)
		{
			cout<<value[index[total]]<<" ";
			total = total - value[index[total]];
		}
	}
	cout<<"\n";
}
