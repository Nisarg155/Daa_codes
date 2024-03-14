#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    // for(int i = 4 ; i >= 0 ;i--)
    // {
    //     for(int j = i+1;j<5;j++)
    //     {
    //         for(int k = i ;k<j ;k++)
    //         {
    //             cout<<i<<" "<<k<<"    "<<k+1<<" "<<j<<endl;
    //         }

    //         cout<<i<<" "<<j<<endl;
    //     }
    // }


    for(int diff = 1;diff<5;diff++)
    {
        for(int i = 1 ;i<5gram-diff ;i++)
        {
            int j = i+diff;
            for(int k = i ;k<j ;k++)
            {
                cout<<i<<" "<<k<<"    "<<k+1<<" "<<j<<endl;
            }
            cout<<i<<" "<<j<<endl;
        }
    }
}