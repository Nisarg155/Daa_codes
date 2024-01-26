#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sol(int i , int cap ,vector<int> & val , vector<int> &wgt , vector<vector<int>> &dp )
{
    if(i <0 || cap == 0) return 0;

    if(dp[i][cap] != -1) return dp[i][cap];

    int nt = sol(i-1,cap,val,wgt,dp);

    int tk = INT_MIN;
    if(wgt[i]<= cap)
    {
        tk = val[i] + sol(i-1,cap-wgt[i],val,wgt,dp);
    }

    return dp[i][cap] = max(nt,tk);
}
int main()
{
    int n = 4;
    int cap = 8;
    vector<int> wt = {2,3,4,5};
    vector<int> val = {1,2,5,6};
    vector<vector<int>> dp(n,vector<int> (cap+1,-1));

    int ans = sol(n-1,cap,val,wt,dp);
    if(ans != INT_MAX) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;
}