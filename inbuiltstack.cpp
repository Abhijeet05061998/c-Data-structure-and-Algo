#include<iostream>
#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main()
{
    stack<int> s;
    s.push(100);
    s.push(102);
    s.push(103);
    s.push(104);
    s.push(105);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
}


