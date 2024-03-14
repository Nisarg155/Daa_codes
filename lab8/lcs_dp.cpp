#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int sol(int n1 ,int n2 , string &s1 , string &s2 , vector<vector<int>> &dp)
{
    if(n1 < 0 || n2 < 0) return 0;

    if(dp[n1][n2] != -1) return dp[n1][n2];
    
    if(s1[n1] == s2[n2] ) return dp[n1][n2] = 1 + sol(n1-1,n2-1,s1,s2,dp);

    else return dp[n1][n2] = max(sol(n1-1,n2,s1,s2,dp),sol(n1,n2-1,s1,s2,dp));

    
} 

int main()
{
    string s1 = "abcd";
    string s2 = "abed";

    int n1 = s1.size();
    int n2 = s2.size();

    vector<vector<int>> dp(n1,vector<int> (n2,-1));

    cout<<sol(n1-1,n2-1,s1,s2,dp)<<endl;
    return 0;
}