#include<iostream>
using namespace std;
void merg(int a[],int n,int si,int ei)
{
    int mid=(si+ei)/2;
    int i=si;
    int j=mid+1;
    int k=0;
    int *output=new int [n];
    while(i<=mid&&j<=ei)
    {
        if(a[i]<a[j])
        {
            output[k]=a[i];
            i++;
            k++;
        }
        else
        {
            output[k]=a[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        output[k]=a[i];
        k++;
        i++;
    }
    while(j<=ei)
    {
        output[k]=a[j];
        k++;
        j++;
    }
    int m=0;
    for(int i=si;i<=ei;i++)
    {
        a[i]=output[m];
        m++;
    }
    delete [] output;
}

void merge_sort(int a[],int n,int si,int ei)
{
    if(si>=ei)//base case
    {
        return;
    }
    int mid=(si+ei)/2;
    merge_sort(a,n,si,mid);
    merge_sort(a,n,mid+1,ei);
    merg(a,n,si,ei);
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
    int si=0;
    int ei=n-1;
    merge_sort(a,n,si,ei);
    for(int i=0;i<6;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
