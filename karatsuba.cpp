#include<bits/stdc++.h>
using namespace std;
int binarymultiplication(char s[])
{
    int len=strlen(s);
    int var1=0,prod=1;
    for(int i=len-1;i>=0;i--)
    {
        if(s[i]=='1')
        {
            var1=var1+prod;
        }
        prod*=2;
    }
    return var1;
}
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
    char arr1[100];
    char arr2[100];
        cin>>arr1;
        cin>>arr2;
    int l1=binarymultiplication(arr1);
    int l2=binarymultiplication(arr2);
    cout<<l1*l2<<endl;
    t--;
    }
}
