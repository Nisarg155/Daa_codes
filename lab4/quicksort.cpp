#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int partation(vector<int> &arr,int l , int r)
{
    int pivot = arr[l];
    int p1 = l;
    int p2 = r;

    while(p1<p2)
    {
        while(arr[p1] <= pivot && p1 <= (r -1))
        {
            p1++;
        }

        while(arr[p2] > pivot && p2 >= (l + 1))
        {
            p2--;
        }

        if(p1<p2)
        {
            swap(arr[p1],arr[p2]);
        }
    }
    swap(arr[l],arr[p2]);

    return p2;


}
void qs(vector<int> &arr, int l ,int r)
{
    if(l<r)
    {
        int pi = partation(arr,l,r);
        qs(arr,l,pi-1);
        qs(arr,pi+1,r);
    }
}
int main()
{
    int n;
    cin>>n;
vector<int> arr(n,0);
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    qs(arr,0,n-1);
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}