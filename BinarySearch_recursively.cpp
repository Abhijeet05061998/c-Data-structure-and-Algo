#include<iostream>
using namespace std;
  int bsearch(int input[],int first,int last,int n,int element)
  {
      if(first>=last)
      {
          return -1;
      }
      int mid=(first-(first+last))/2;
      if(input[mid]==element)
      {
          return mid;
      }
      else if(input[mid]>element)
      {
          return bsearch(input,first,mid-1,element,n);
      }
      else
      {
          return bsearch(input,mid+1,last,element,n);
      }

  }
  int binarysearch(int input[],int n,int element)
{
    int first=0;
    int last=n-1;
   return bsearch(input,first,last,n,element);
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
    int element;
    cout<<"Enter the element that you want to search:"<<endl;
    cin>>element;
   cout<< binarysearch(a,n,element);

}
