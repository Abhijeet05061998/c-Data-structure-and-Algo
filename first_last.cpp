#include<iostream>
using namespace std;
int main()
{
    int t,sum;
    cout<<"Enter the test case:"<<endl;
    cin>>t;
    while(t>0)
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

       for(int i=0;i<n;i++)
       {
           sum=a[0]+a[n-1];
       }
       cout<<sum<<endl;
       t--;
   }
}
