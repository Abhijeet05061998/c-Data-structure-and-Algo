#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n==0)
    {
        return 1;
    }
    int smalloutput=factorial(n-1);
    return n*smalloutput;
}
int main()
{
    int x;
    cin>>x;
    int output=factorial(x);
    cout<<output<<endl;
}
