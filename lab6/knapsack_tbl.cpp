#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int n = 4;
    int cap = 8;
    vector<int> wt = {2,3,4,5};
    vector<int> val = {1,2,5,6};
    vector<vector<int>> dp(n,vector<int> (cap+1,-1));

    for(int i = 0;i<n;i++) dp[i][0] = 0;
    for(int i = 0;i<=cap;i++) if(wt[i]<=cap) dp[0][wt[i]] = val[i];

    for(int i = 1;i<n;i++)
    {
        for(int j = 1;j<=cap;j++)
        {
            int ans ;
            if(wt[i] <= j) ans = val[i] + dp[i-1][j-wt[i]];
            else ans = dp[i-1][j];
            dp[i][j] = ans ;
        }
    }

    int ans = dp[n-1][cap];
    if(ans != INT_MAX) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}