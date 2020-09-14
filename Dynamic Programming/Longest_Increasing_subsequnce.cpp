#include<iostream>
using namespace std;

int LIS(int arr[], int N)
{
    int lis[N];
    lis[0] = 1;
    for(int i = 1; i < N; i++)
    {
        lis[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j] < arr[i] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    return lis[N-1];
}

int main()
{
    int N;
    cin>>N;
    int *arr = new int[N];
    for(int i = 0; i < N; i++)
        cin>>arr[i];
    int ans = LIS(arr, N);
    cout<<ans<<"\n";
}
/*
Time Complexity: O(n2).
As nested loop is used.
Auxiliary Space: O(n).
Use of any array to store LIS values at each index.
*/
