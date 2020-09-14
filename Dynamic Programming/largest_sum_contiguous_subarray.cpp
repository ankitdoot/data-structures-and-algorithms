#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int* arr = new int[N];
	for(int i = 0; i < N; i++)
		cin>>arr[i];
	int max_sum = 0;
	int current_sum = 0;
	for(int i = 0; i < N; i++)
	{
		current_sum += arr[i];
		if(current_sum > max_sum)
			max_sum = current_sum;
		if(current_sum < 0)
			current_sum = 0;
	}
	cout<<max_sum<<"\n";
}

//Time Complexity is O(N).

