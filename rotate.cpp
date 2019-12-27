#include<iostream>
using namespace std;

int rotate_array(int arr[],int n,int d)
{
    while(d>0)
    {
        int temp=arr[0];
        for(int i=0;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        arr[n-1]=temp;
        d--;
    }
}
int main()
{

    int n;
    cout<<"Enter the size of array:"<<endl;
    cin>>n;
    int a[100];
    cout<<"Enter the element in array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the element where you want rotate array:"<<endl;
    int d;
    cin>>d;
    rotate_array(a,n,d);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}
