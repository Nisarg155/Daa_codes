#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void addEdge(vector<int> adj[] ,int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addedge_directed(vector<int> adj[] ,int u, int v)
{
    adj[u].push_back(v);
}


void bfs(vector<int> adj[] , int n)
{
    bool visited[n];
    memset(visited,false,sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty())
    {
        int ele = q.front();
        q.pop();
        cout<<ele<<" ";
        for(auto &it :adj[ele])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it] = true;
            }
        }
    }
    cout<<endl;
}

int main()
{
    vector<int> adj[10];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 5);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 6);
    addEdge(adj, 4, 7);
    addEdge(adj, 5, 8);
    addEdge(adj, 6, 9);
    addEdge(adj, 7, 8);
    addEdge(adj, 8, 9);
    bfs(adj,10);

    vector<int> undir_adj[10];
    addedge_directed(undir_adj, 0, 1);
    addedge_directed(undir_adj, 0, 4);
    addedge_directed(undir_adj, 1, 2);
    addedge_directed(undir_adj, 1, 3);
    addedge_directed(undir_adj, 1, 4);
    addedge_directed(undir_adj, 2, 3);
    addedge_directed(undir_adj, 2, 5);
    addedge_directed(undir_adj, 3, 4);
    addedge_directed(undir_adj, 3, 6);
    addedge_directed(undir_adj, 4, 7);
    addedge_directed(undir_adj, 5, 8);
    addedge_directed(undir_adj, 6, 9);
    addedge_directed(undir_adj, 7, 8);
    addedge_directed(undir_adj, 8, 9);
    bfs(undir_adj,10);
    return 0;
}