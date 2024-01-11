#include<bits/stdc++.h>
#include<iostream>
using namespace std;


void merge(vector<int> &arr ,int low,int mid,int high)
{
    int n = high - low + 1;
    vector<int> temp (n);
    int p1 = low , p2 = mid + 1 , k = 0;
    while(p1 <= mid && p2 <= high)
    {
        if(arr[p1] <= arr[p2])
        {
            temp[k++] = arr[p1++];
        }
        else{
            temp[k++] = arr[p2++];
        }
    }

    if(p1<= mid)
    {
        while(p1 <= mid)
        {
            temp[k++] = arr[p1++];
        }
    }
    else{
        while(p2 <= high)
        {
            temp[k++] = arr[p2++];
        }
    }

    for(int i = 0;i< n ;i++)
    {
        arr[low + i] = temp[i];
    }

    return;

}
void merge_sort(vector<int> &arr , int low ,int high)
{
    if(low >= high)
    {
        return ;
    }

    int mid = low + (high - low)/2;
    merge_sort(arr , low , mid);
    merge_sort(arr , mid+1 , high);
    merge(arr , low , mid , high);
}
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    merge_sort(v , 0 , n-1);


    for(auto &i :v)
    {
        cout<<i<<" ";
    }

    return 0;
}