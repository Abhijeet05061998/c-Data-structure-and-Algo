#include<bits/stdc++.h>
using namespace std;


min_step(int n)
{
	if(n<=1)
	{
		return 0;
	}
	int x;
	int y=INT_MAX,z=INT_MAX;
	x=min_step(n-1);
	if(n%2==0)
	{
		y=min_step(n/2);
	}
	if(n%3==0)
	{
		z=min_step(n/3);
	}

	int ans=min(x,min(y,z))+1;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	cout<<min_step(n);
}
