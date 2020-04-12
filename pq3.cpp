#include<iostream>
#include<queue>
using namespace std;

int fun(int arr[],int n,int k)
{
    priority_queue<int>p;
    for(int i=0;i<n;i++)
    {
        p.push(arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        arr[i]=-arr[i];
    }
    k=k-1;
    while(k--)
    {
        p.pop();
    }
    return p.top();
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<fun(arr,n,k);
}
