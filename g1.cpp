#include<bits/stdc++.h>
using namespace std;

int fib_helper(int n,int*ans)
{
	if(n<=1)
	{
		return n;
	}
	if(ans[n]!=-1)
	{
		return ans[n];
	}
	int a=fib_helper(n-1,ans);
	int b=fib_helper(n-2,ans);

	ans[n]=a+b;
	return ans[n];
}
int fib(int n)
{
	int*ans=new int[n+1];
	for(int i=0;i<n+1;i++)
	{
		ans[i]=-1;
	}
	fib_helper(n,ans);
}
int main()
{
	int n;
	cin>>n;
	cout<<"Ans:"<<fib(n)<<endl;
	  cout<<"fibonacci series:";
	for(int i=0;i<n+1;i++)
    {
        cout<<fib(i)<<" ";
    }
}
