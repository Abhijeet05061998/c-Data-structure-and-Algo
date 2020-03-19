#include<iostream>
using namespace std;
class stack
{
    int *data;
    int nextindex;
    int capacity;
public:
    stack()
    {
        data=new int[2];
        nextindex=0;
        capacity=2;
    }

    int size()
    {
        return nextindex;
    }
    bool empty()
    {
        return nextindex==0;
    }

    void push(int element)
    {
        if(nextindex==capacity)
        {
            int *newdata=new int[2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newdata[i]=data[i];
            }
            capacity*=2;
            delete []data;
            newdata=data;
        }
        data[nextindex]=element;
        nextindex++;
    }
    int pop()
    {
        if(empty())
        {
            cout<<"Stack is Empty"<<endl;
        }
        nextindex--;
        return data[nextindex];
    }

    int top()
    {
        return data[nextindex-1];
    }
};
int main()
{
    stack s;
    s.push(10);
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.push(16);
    s.push(17);
    s.push(18);
    s.push(19);
    s.push(20);
    s.push(21);
    s.push(22);
    s.push(23);
    s.push(24);

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.empty()<<endl;
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;

}
