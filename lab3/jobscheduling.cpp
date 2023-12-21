#include <bits/stdc++.h>

using namespace std;

int find(int x, vector<int> &parent)
{
    if(parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x],parent);
}


void union_set(int x, int y, vector<int> &parent)
{
    int x_rep = find(x,parent);
    int y_rep = find(y,parent);
    if(x_rep == y_rep)
    {
        return;
    }
    parent[y_rep] = x_rep;
}


int main()
{
    vector<pair<int,pair<int,int>>> pr_dl_jb;

    int n;
    cin>>n;
    int max_dl = 0;
    vector<pair<int,int>> sol;
    for(int i = 0; i < n; i++)
    {
        cout<<"Enter the profit of job  "<<(i+ 1)<<" :- ";
        int profit;
        cin>>profit;
        cout<<"Enter deadline of job  "<<(i + 1)<<" :- ";
        int deadline;
        cin>>deadline;
        max_dl = max(max_dl,deadline);
        pr_dl_jb.push_back({profit,{deadline,i}});

    }

    sort(pr_dl_jb.rbegin(), pr_dl_jb.rend());
    int size_sol = min(max_dl, n);
    vector<int> parent (size_sol + 1,0);
    for(int i = 0;i<=size_sol;i++)
    {
        parent[i] = i;
    }


    int count = 0;
    int profit = 0;
    for(int i = 0; i < n; i++)
    {
        int jb = pr_dl_jb[i].second.second;
        int pft = pr_dl_jb[i].first;
        int dl = pr_dl_jb[i].second.first;
        int rep = find(min(dl,n),parent);
        if(rep > 0)
        {
            union_set(rep - 1, rep, parent);
            count++;
            profit += pft;
            sol.push_back({pft,jb});
        }
    }

    for(auto x : sol)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }



    
}