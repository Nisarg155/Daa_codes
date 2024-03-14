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
    vector<vector<char>> sol(n1+1,vector<char> (n2+1,'$'));
    for(int i = 1;i<=n1;i++)
    {
        for(int j = 1;j<=n2;j++)
        {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                sol[i][j] = 'd';
            }
            else if(dp[i-1][j] >= dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                sol[i][j] = 'u';
            }
            else
            {
                dp[i][j] = dp[i][j-1];
                sol[i][j] = 'p';

            }

        }
    }
    cout<<dp[n1][n2]<<endl;

    int i = n1 , j = n2;
    string ans = "";

    while(i> 0 && j > 0)
    {
        if(sol[i][j] == 'd')
        {
            ans += s1[i-1];
            i--;
            j--;
        }
        else if(sol[i][j] == 'u')
        {
            i--;
        }
        else {
            j--;
        }
    } 
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}