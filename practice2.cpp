#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
Node *takeinput()
{
    int data;
    cin>>data;
    Node* Head=NULL;
    Node* Tail=NULL;
    while(data!=0)
    {
        Node *newNode=new Node(data);
        if(Head==NULL)
        {
            Head=newNode;
            Tail=newNode;
        }
        else
        {
            Tail->next=newNode;
            Tail=Tail->next;
        }
        cin>>data;
    }
    return Head;
}
void printIthNode(Node *head, int i) {
    Node* temp=head;
    int count=0;
    while(count<i&&temp!=NULL)
    {
      count++;
      temp=temp->next;
    }
    if(temp==NULL)
    {

        return;
    }
    else
    {
        cout<<temp->data;
    }

}
int main()
{
   Node* Head=takeinput();
   int i;
    cin>>i;
    printIthNode(Head,i);
}
