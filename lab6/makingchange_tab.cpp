#include<bits/stdc++.h>

using namespace std;

int makingchange(int tar,vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int> (tar+1,INT_MAX));
    for(int i=0;i<n;i++) dp[i][0] = 0;
    for(int i = 0;i<=tar;i++)
    {
        if(i%coins[0] == 0) dp[0][i] = i/coins[0];
    }

    for(int i = 1;i<n;i++)
    {
        for(int j = 1;j<= tar ;j++)
        {
            int nt = dp[i-1][j];
            int tk = INT_MAX;
            if(coins[i] <= j)
            {
                tk = 1 + dp[i][j-coins[i]];
            }
            dp[i][j] = min(nt,tk);
        }
    }

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<=tar;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n-1][tar];
}

int main()
{
    int n,tar;
    cin>>n>>tar;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int ans = makingchange(tar,coins);
    if(ans == INT_MAX) cout<<"-1";
    else cout<<ans;
    return 0;

}