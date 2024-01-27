#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void dfs(vector<int> adj[],vector<int> &visited,int node ,stack<int> &s)
{
    visited[node] = 1;

    for(auto &it : adj[node])
    {
        if(!visited[it])
        {
            dfs(adj,visited,it,s);
        }
    }
    s.push(node);
}
int main()
{
    vector<int> adj[6];
    adj[4].push_back(1);
    adj[4].push_back(0);
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> visited(6,0);
    vector<int> ans;
    stack<int> s;
    for(int i = 0;i<6;i++)
    {
        if(!visited[i])
        {
            dfs(adj,visited,i,s);
        }
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    for(auto &it : ans)
    {
        cout<<it<<" ";
    }
    return 0;
}