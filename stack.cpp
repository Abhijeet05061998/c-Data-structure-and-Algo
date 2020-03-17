#include<iostream>
#include<climits>
#include<math.h>
using namespace std;
class Arraystack
{
    int *data;
    int nextIndex;
    int capacity;
public:
    Arraystack(int totalsize)
    {
        data=new int[totalsize];
        nextIndex=0;
        capacity=totalsize;
    }
    int stacksize()
    {
        return nextIndex;
    }
    bool Empty()
    {
        return nextIndex==0;
    }
    void push(int element)
    {
        if(nextIndex==capacity)
        {
            cout<<"Stack is full"<<endl;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    int pop()
    {
        if(Empty())
        {
            cout<<"Stack is empty"<<endl;
        }
          nextIndex--;
          return data[nextIndex];
    }
    int top()
    {
        return data[nextIndex-1];
    }
};
int main()
{
    Arraystack s(5);
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    cout<<s.stacksize()<<endl;
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.stacksize()<<endl;
    cout<<s.Empty()<<endl;
}
