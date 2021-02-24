#include<bits/stdc++.h>
using namespace std;
int  main()
{

    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<n;i++)
    {
        int dev=arr[i]/4;
        if(arr[i]%4==0)
        {
            cout<<dev;
        }
        else
        {
            cout<<"-1"<<" ";
        }
    }
}
