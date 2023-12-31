#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> deno = {2000,500,200,100,50,20,10,5,2,1};
    int i = 0;
    int count = 0;
    while(n>0)
    {
        if(n>=deno[i])
        {
            count += n/deno[i];
            n = n%deno[i];
        }
        else{
            i++;
        }
    }

    cout<<count<<endl;
}