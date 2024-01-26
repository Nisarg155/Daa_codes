#include<bits/stdc++.h>

using namespace std;

int makingchange(int tar,int ind , vector<int> & coins,vector<vector<int>> &dp)
{
    if(ind == 0) 
    {
        if(tar%coins[ind] == 0) return tar/coins[ind];
        else return INT_MAX;
    }

    if(dp[ind][tar] != -1) return dp[ind][tar];

    int nt = makingchange(tar,ind-1,coins,dp);
    int tk = INT_MAX;
    if(coins[ind] <= tar)
    {
        tk = 1 + makingchange(tar-coins[ind],ind,coins,dp);
    }

    return dp[ind][tar] = min(nt,tk);
}

int main()
{
    int n,tar;
    cin>>n>>tar;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    vector<vector<int>> dp(n,vector<int>(tar+1,-1));
    int ans = makingchange(tar,n-1,coins,dp);
    if(ans == INT_MAX) cout<<"-1";
    else cout<<ans;
    return 0;
}