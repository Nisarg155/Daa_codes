#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
    int n = 4;
    int cap = 8;
    vector<int> wt = {2,3,4,5};
    vector<int> val = {1,2,5,6};
    vector<vector<int>> dp(n+1,vector<int> (cap+1,-1));

    for(int i = 0;i<=n;i++) dp[i][0] = 0;
    for(int i = 0;i<=cap;i++) dp[0][i] = 0;

    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=cap;j++)
        {
            int ans ;
            if(wt[i-1] <= j) ans = val[i-1] + dp[i-1][j-wt[i-1]];
            else ans = dp[i-1][j];
            dp[i][j] = ans ;
        }
    }
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=cap;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    vector<int> ans ;
    int i = n , j = cap;

    while(i > 0 && j >0)
    {
        if(dp[i][j] == dp[i-1][j]) i--;
        else{
            ans.push_back(wt[i-1]);
            j = j - wt[i-1];
            i--;
        }
    }
    for(auto x : ans) cout<<x<<" ";
    return 0;
}