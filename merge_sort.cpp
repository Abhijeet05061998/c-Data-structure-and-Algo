//BINARY SEARCH WITH MERGE_SORT USING RECURSION
#include<iostream>
using namespace std;
int  binarysearch(int arr[],int n,int first ,int last,int num)
{
    if(first>=last)
    {
        return -1;
    }
    int mid=(first+last)/2;
    if(arr[mid]==num)
    {
        return mid;
    }
    else if(arr[mid]>num)
    {
        return binarysearch(arr,n,first,mid-1,num);
    }
    else
    {
        return binarysearch(arr,n,mid+1,last,num);
    }
}
int merg(int arr[],int n,int first,int last)
{
    int mid=(first+last)/2;
    int *output=new int[n];
    int i=first;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=last)
    {
        if(arr[i]<arr[j])
        {
            output[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            output[k]=arr[j];
            j++;
            k++;
        }

    }
    while(i<=mid)
    {
        output[k]=arr[i];
        k++;
        i++;
    }
    while(j<=last)
    {
        output[k]=arr[j];
        k++;
        j++;
    }
    int m=0;
    for(int i=first;i<=last;i++)
    {
        arr[i]=output[m];
        m++;
    }
    delete []output;
}

void merge_sort(int arr[],int n,int first,int last,int num)
{
    //base case
    if(first>=last)
    {
        return;
    }
    int mid=(first+last)/2;
    merge_sort(arr,n,first,mid,num);
    merge_sort(arr,n,mid+1,last,num);
    merg(arr,n,first,last);
    binarysearch(arr,n,first,last,num);
}

int main()
{

    int n;
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    int arr[100];
    cout<<"Enter the element in array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int num;
    cout<<"Enter the element that you want search:"<<endl;
    cin>>num;
    int first=0;
    int last=n-1;
    merge_sort(arr,n,first,last,num);
    cout<<"Sorted Array:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Searched Element:"<<endl;
    cout<<binarysearch(arr,n,first,last,num);
}

