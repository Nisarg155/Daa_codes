#include<bits/stdc++.h>

using namespace std;

int makingchange(int tar,vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n+1,vector<int> (tar+1,INT_MAX));
    for(int i=0;i<=n;i++) dp[i][0] = 0;
    for(int i=0;i<=tar;i++) dp[0][i] = 0;
    for(int i = 1;i<=tar;i++)
    {
        if(i%coins[0] == 0) dp[1][i] = i/coins[0];
    }

    for(int i = 2;i<=n;i++)
    {
        for(int j = 1;j<= tar ;j++)
        {
            int nt = dp[i-1][j];
            int tk = INT_MAX;
            if(coins[i-1] <= j)
            {
                tk = 1 + dp[i][j-coins[i-1]];
            }
            dp[i][j] = min(nt,tk);
        }
    }

    int i = n , j = tar;

    while(i > 0 && j > 0)
    {
        if(dp[i][j] == dp[i-1][j])
        {
            i--;
        }
        else
        {
            cout<<coins[i-1]<<" ";
            j = j - coins[i-1];
        }
    }

    return dp[n][tar];
}

int main()
{
    int n,tar;
    cin>>n>>tar;
    vector<int> coins(n);
    for(int i=0;i<n;i++) cin>>coins[i];
    int ans = makingchange(tar,coins);
    if(ans == INT_MAX) cout<<"-1";
    else cout<<endl<<ans<<endl;
    return 0;

}