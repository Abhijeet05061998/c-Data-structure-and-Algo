#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pair_of_sum(int arr[],int n,int x)
{
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {

            if(arr[i]+arr[j]==x)
            {
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[100];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cin>>x;
    pair_of_sum(arr,n,x);
}
