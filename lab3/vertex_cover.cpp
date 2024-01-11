#include <bits/stdc++.h>

using namespace std;



int main()
{
    // cout<<"Hello World";
    int rowCount=0,colCount=0;
    cout<<"Enter row count\n";
    cin>>rowCount;
    // cin>>colCount;
    colCount=rowCount;

    vector<vector<int>>v(rowCount,vector<int>(colCount,0));

    for(int i=0;i<rowCount;i++){
        for(int j=0;j<colCount;j++){
            cin>>v.at(i).at(j);
        }
        // cout<<endl;
    }
    // cout<<endl<<endl;
    // for(auto it:v){
    //     for(auto jt:it){
    //         cout<<jt<<" ";
    //     }
    //     cout<<endl;
    // }

    vector<int>noOfvertex(rowCount,0);

    cout<<endl<<endl;
    int flag=1;
    vector<char>pool;
    while(flag!=0){


        for(int i=0;i<colCount;i++){
            for(int j=0;j<rowCount;j++){
                if(i==j)
                    continue;
                if(v[i][j]==1){
                    // cout<<"\t\t\thi\n";
                    noOfvertex[i]+=1;
                }
            }
        }

        // cout<<"Printing middle vertex data\n\n";
        // for(auto it:noOfvertex){
        //     cout<<it<<" ";
        // }
        // cout<<"\nmax elemrnt row:  ";


        auto maxElementit=max_element(noOfvertex.begin(), noOfvertex.end());
        int max_elementrow=maxElementit- noOfvertex.begin();

        // cout<<max_elementrow<<"\n";


        pool.push_back(97+max_elementrow);
        for(int i=0;i<rowCount;i++){
            v[i][max_elementrow]=0;
            v[max_elementrow][i]=0;
            noOfvertex[i]=0;
        }

        flag=0;
        for(int i=0;i<colCount;i++){
            for(int j=0;j<rowCount;j++){
                if(i==j)
                    continue;
                if(v[i][j]==1){
                    // cout<<"\t\t\thi\n";
                    flag=1;
                    break;
                }
            }
        }
        // flag=0;

    }

    // cout<<"noOfvertex\n\n\n";
    // for(auto it:noOfvertex){
    //         cout<<it<<" ";
    // }
    cout<<"\n\nPool\n\n";

    for(auto it:pool){
            cout<<it<<" ";
    }


    return 0;
}