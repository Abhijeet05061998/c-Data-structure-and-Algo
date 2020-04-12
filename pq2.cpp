#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    priority_queue<int>pq(arr,arr+n);
    int i=n-1;
    while(i>=0)
    {
        arr[i]=pq.top();
        pq.pop();
        i--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}
