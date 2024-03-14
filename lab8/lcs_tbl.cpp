#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    string s1 = "abcef";
    string s2 = "abedf";
    int n1 = s1.size();
    int n2 = s2.size();
    vector<vector<int>> dp(n1+1,vector<int> (n2+1,0));
    for(int i = 1;i<=n1;i++)
    {
        for(int j = 1;j<=n2;j++)
        {
            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);

        }
    }
    cout<<dp[n1][n2]<<endl;

    return 0;
}