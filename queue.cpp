#include<iostream>
using namespace std;
template<typename T>
class queue
{
    T*data;
    int firstindex;
    int nextindex;
    int size;
    int capacity;
public:

    queue(T s)
    {
        data=new T[s];
        firstindex=-1;
        nextindex=0;
        size=0;
        capacity=s;
    }

    int getsize()
    {
        return size;
    }
    bool empty()
    {
        return size==0;
    }
    void enqueue(T element)
    {
        if(nextindex==capacity)
        {
           T*newdata=new T[2*capacity];
           int j=0;
           for(int i=firstindex;i<capacity;i++)
           {
               newdata[j]=data[i];
               j++;
           }
           delete []data;
           data=newdata;
           firstindex=0;
           capacity*=2;
        }
        data[nextindex]=element;
        nextindex=(nextindex+1)%capacity;
        if(firstindex==-1)
        {
            firstindex=0;
        }
        size++;
    }
    T front()
    {
        if(empty())
        {
            cout<<"queue is empty!"<<endl;
        }
        return data[firstindex];

    }
    T dequeue()
    {
        if(empty())
        {
            cout<<"queue is empty"<<endl;
        }
        T ans=data[firstindex];
        firstindex=(firstindex+1)%capacity;
        size--;
        if(size==0)
        {
            firstindex=-1;
            nextindex=0;
        }
    }
};
int main()
{
    queue<int>s(5);
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60);
    s.enqueue(70);
    s.enqueue(80);

    cout<<s.empty()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.dequeue()<<endl;
    cout<<s.getsize()<<endl;
    cout<<s.front()<<endl;
}
