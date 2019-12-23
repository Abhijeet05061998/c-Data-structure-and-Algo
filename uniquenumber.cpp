#include<iostream>
using namespace std;
int find_unique(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
void merge(int a[],int n,int first,int last)
{
    int mid=(first+last)/2;
    int i=first;
    int j=mid+1;
    int k=0;
    int *output=new int[n];
    while(i<=mid&&j<=last)
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
    while(j<=last)
    {
        output[k]=a[j];
        k++;
        j++;
    }
    int m=0;
    for(int i=first;i<=last;i++)
    {
        a[i]=output[m];
        m++;
    }
    delete []output;
}
void merge_sort(int a[],int n,int first,int last)
{
    if(first>=last)
    {
        return;
    }
    int mid=(first+last)/2;
    merge_sort(a,n,first,mid);
    merge_sort(a,n,mid+1,last);
    merge(a,n,first,last);
    find_unique(a,n);

}
int main()
{
    int n;
    cin>>n;
    int a[100];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int first=0;
    int last=n-1;
    merge_sort(a,n,first,last);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
