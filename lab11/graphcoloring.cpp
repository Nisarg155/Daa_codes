#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<vector<int>> &graph , int c , vector<int> color , int v)
{
    for(int i = 0; i < graph[v].size(); i++)
    {
        if(graph[v][i] && c == color[i])
        {
            return false;
        }
    }
    return true;
} 

void print(vector<int> &color , int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << color[i] << " ";
    }
    cout << endl;
}

void sol(vector<vector<int>> &graph , int m ,int n , vector<int> &color , int v )
{
    if(v == n)
    {
        print(color, n);
        return ;
    }

    for(int c = 1; c <= m; c++)
    {
        if(isSafe(graph, c, color, v))
        {
            color[v] = c;
            sol(graph, m, n, color, v + 1);
            color[v] = 0;
        }
    }


}

int main()
{
    int m;
    cout << "Enter the number of colors: ";
    cin >> m;
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    cout << "Enter the adjacency matrix: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "Enter the row " << i + 1 << ": "<<endl;
        for(int j = 0; j < n; j++)
        {
            cout<< "Enter the element " << j + 1 << ": ";
            cin >> graph[i][j];
        }
    }
    vector<int> color(n,0);
    for(int i = 0; i < n; i++)
    {
        color[i] = 0;
    }
    sol(graph, m, n, color, 0);
}