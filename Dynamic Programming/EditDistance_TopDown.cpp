#include<bits/stdc++.h>
using namespace std;
const int maxlen = 1000;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

int EditDistance(string str1, string str2, int m, int n, int dp[][maxlen])
{
    if(m == 0)
        return n;
    if(n == 0)
        return m;
    if(dp[m-1][n-1] != -1)
        return dp[m-1][n-1];
    if(str1[m-1] == str2[n-1])
        return dp[m-1][n-1] = EditDistance(str1, str2, m-1, n-1, dp);

    return dp[m-1][n-1] = 1 + min(EditDistance(str1, str2, m-1, n-1, dp),
                                  EditDistance(str1, str2, m-1, n, dp),
                                  EditDistance(str1, str2, m, n-1, dp)
                                  );
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    int m = s1.size();
    int n = s2.size();
    int dp[m][maxlen];
    memset(dp, -1, sizeof(dp));
    int ans = EditDistance(s1, s2, m, n, dp);
    cout<<ans<<"\n";
}

//Time Complexity: O(M * N)
//Auxiliary Space: O(M * N)
//Auxiliary Space: O(M * N)
