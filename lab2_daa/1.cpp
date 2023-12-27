#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

float sol(vector<pair<int,int>> &v, int n,int weight)
{
    sort(v.rbegin(), v.rend());
    vector<pair<float,pair<int,int>>> res;

    for (int i = 0; i < n; i++)
    {
        float resu  = float(v[i].first*1.0/v[i].second*1.0);
        res.push_back({resu,{v[i].first,v[i].second}});
    }

    sort(res.rbegin(), res.rend());
    
    float profit = 0.0;
    int wt = 0;
    
    for(auto ele : res)
    {
        if(wt == weight) break;
        if(wt + ele.second.second <= weight)
        {
            wt += ele.second.second;
            profit += ele.second.first;
        }
        else{
            
            profit = (weight-wt)*ele.second.first/ele.second.second + profit;
            wt += (weight- wt);
            cout<<profit<<endl;
        }
    }
    
    return profit;
}


int main()
{
    int n  = 0,wet ;
    cout<<"Enter number and weight :- "<<endl;
    cin>>n>>wet;
    vector<pair<int,int>> pro_wth;
    for(int i ; i<n; i++)
    {
        int p , w;
        cout<<"Enter profit :- ";
        cin>>p;
        cout<<"enter weight :- ";
        cin>>w;
        pro_wth.push_back({p,w});
    }

    float ans = sol(pro_wth,n,wet);
    cout<<"Solution is :- "<<ans<<endl;

}