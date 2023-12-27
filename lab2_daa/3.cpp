#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the n ";
    cin>>n;
    vector<pair<int,int>> activities;

    for(int i=0;i<n;i++)
    {
        int start,end;
        cout<<"Enter the start time and end time of activity "<<i+1<<endl;
        cin>>start>>end;
        activities.push_back(make_pair(start,end));
    }

    sort(activities.begin(),activities.end(),[](pair<int,int> a,pair<int,int> b){
        return a.second<b.second;
    }); // sort the activities according to their end time
    int deadline = activities[0].second;
    int count = 1;
    for(int i=1;i<n;i++)
    {
        if(activities[i].first>=deadline)
        {
            count++;
            deadline = activities[i].second;
        }
    }
    return 0;
}