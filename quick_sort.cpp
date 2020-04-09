#include<iostream>
using namespace std;
int partition(int arr[],int n,int first,int last)
{
    int pivot=arr[first];
    int count=0;
    for(int i=first+1;i<=last;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }
    int pivotindex=count+first;
    arr[first]=arr[pivotindex];
    arr[pivotindex]=pivot;
    int i=first;
    int j=last;
    while(i<pivotindex&&j>pivotindex)
    {
        if(arr[i]<=pivot)
        {
            i++;
        }
        else if(arr[j]>=pivot)
        {
            j--;
        }
        else
        {
            int temp;
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
    }
    return pivotindex;
}
void quick_sort(int arr[],int n,int first,int last)
{
    if(first>=last)
    {
        return;
    }
    int p=partition(arr,n,first,last);
    quick_sort(arr,n,first,p-1);
    quick_sort(arr,n,p+1,last);
}
int main()
{
    cout<<"Enter the size of array:"<<endl;
    int n;
    cin>>n;
    int arr[n];
    cout<<"Enter the element in array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int first=0;
    int last=n-1;
    quick_sort(arr,n,first,last);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}
