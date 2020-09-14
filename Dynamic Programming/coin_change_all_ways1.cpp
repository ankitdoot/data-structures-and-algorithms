#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int M;
        cin>>M;
        int v[M+1];//value of all coins
        for(int  i = 1; i <= M; i++)
        {
            cin>>v[i];
        }
        int N;
        cin>>N;//value of amount to be paid
        int dp[M+1][N+1];
        for(int i = 1; i <= M; i++)
        {
            for(int sum = 0; sum <= N; sum++)
            {
                if(sum == 0)//
                {
                    dp[i][sum] = 1;//possible ways to pay 0 amount
                }
                else {
                    //including given coin
                    int op1 = (v[i] > sum) ? 0 : dp[i][sum - v[i]];
                    //excluding given coin
                    int op2 = (i == 1) ? 0 : dp[i-1][sum];
                    dp[i][sum] = op1 + op2;
                }
            }
        }
        cout<<dp[M][N]<<"\n";
    }
    //enter your code here
    return 0;
}

//time complexity O(MN)
//space complexity O(MN)