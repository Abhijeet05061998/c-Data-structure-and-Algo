#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node*next;

    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
Node *takeinput()
{
    int data;
    Node*head=NULL;
    Node*tail=NULL;
    while(data!=0)
    {
        Node *newNode=new Node(data);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=tail->next;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
     cout<<endl;

}
int  length(Node *head)
{
    Node *temp=head;
   int count=0;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<count;
}
int main()
{
    Node*head=takeinput();
    print(head);
    length(head);
}
