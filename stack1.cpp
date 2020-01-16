#include<iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;
class stackUsingarray
{
    int *data;
    int nextIndex;
    int capacity;

public:
    stackUsingarray()
    {
        data=new int[5];
        nextIndex=0;
        capacity=5;
    }
    int siz()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex==0;
    }
    void push(int element)
    {
        if(nextIndex==capacity)
        {
            int *newData=new int [2*capacity];
            for(int i=0;i<capacity;i++)
            {
                newData[i]=data[i];
            }
            capacity*=2;
            delete [] data;
            newData=data;
        }
        data[nextIndex]=element;
        nextIndex++;
    }
    int pop()
    {
        if(isEmpty())
        {
        cout<<"Stack is Empty"<<endl;
        return INT_MIN;
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
          stackUsingarray s;
          s.push(10);
          s.push(20);
          s.push(30);
          s.push(40);
          s.push(50);
          s.push(60);
          s.push(70);

         cout<<s.pop()<<endl;
         cout<<s.pop()<<endl;
         cout<<s.pop()<<endl;
         cout<<s.top()<<endl;
         cout<<s.siz()<<endl;
         cout<<s.isEmpty()<<endl;
    }

