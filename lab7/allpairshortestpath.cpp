#include <bits/stdc++.h>
using namespace std;

void ins(vector<vector<int>> &mat, int u, int v, int w) {
    mat[u][v] = w;
}

void floud_warshall(vector<vector<int>> &mat)
{
    int n = mat.size();

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            for(int k = 0;k<n;k++)
            {
                if(mat[j][i] != INT_MAX && mat[i][k] != INT_MAX)
                    mat[j][k] = min(mat[j][k],mat[j][i]+mat[i][k]);
            }
        }
    }


    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(mat[i][j] == INT_MAX)
                cout<<"0"<<" ";
            else
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    vector<vector<int>> mat(5,vector<int>(5,INT_MAX));
    ins(mat,1,2,3);
    ins(mat,2,3,2);
    ins(mat,3,4,1);
    ins(mat,4,1,2);
    ins(mat,1,4,7);
    ins(mat,2,1,8);
    ins(mat,3,1,5);

    for(int i = 0;i<5;i++) mat[i][i] = 0;
    floud_warshall(mat);
    return 0;
}
