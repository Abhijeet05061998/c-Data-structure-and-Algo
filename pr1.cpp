#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
    int n,i,d;
    cin>>n>>d;
    int arr[100000];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
        i=0;
    int j=i+d-1;
    while(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    i=d;
    j=n-1;
    while(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    i=0;
    j=n-1;
    while(i<j)
    {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    t--;
  }
  return 0;

}
