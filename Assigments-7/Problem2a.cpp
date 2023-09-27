#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> A={-30, -24, -12, -5, -1, 2,7,9,13,19,23};
    vector<int>res;
    int w;
    cin>>w;
    int sum=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum<=w)
        {
            res.push_back(A[i]);
        }
    }
    int x=res.size();
    for(int j=0;j<x;j++)
    {
        cout<<res[j]<<" ";
    }
    cout<<endl;
    cout<<"Maximum number of elements is: "<<x<<endl;
}