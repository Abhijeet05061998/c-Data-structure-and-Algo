#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    priority_queue<int>pq;
    for(int i=1;i<=n;i++)
    {
        pq.push(i);
    }
    cout<<"Top Element"<<pq.top()<<endl;
    cout<<"Size of queue"<<pq.size()<<endl;
    cout<<pq.empty()<<endl;

    while(pq.empty()==false)
    {
        cout<<pq.top()<<endl;
        pq.pop();
    }
    return 0;

}

