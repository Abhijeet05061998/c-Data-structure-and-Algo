#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class Treenode
{
public:
    T data;
    vector<Treenode<T>*>children;
    Treenode(T data)
    {
        this->data=data;
    }
};
Treenode<int>*takeinput()
{
    int rootdata;
    cout<<"Enter the root data:-"<<endl;
    cin>>rootdata;
    Treenode<int>*root=new Treenode<int>(rootdata);
    queue<Treenode<int>*>pendingqueue;
    pendingqueue.push(root);

    while(pendingqueue.size()!=0)
    {
        Treenode<int>*frontelement=pendingqueue.front();
        pendingqueue.pop();
        int children;
        cout<<"Enter the children of "<<frontelement->data<<endl;
        cin>>children;
        for(int i=0;i<children;i++)
        {
            int childnode;
            cout<<"Enter"<<i<<" th children of "<<frontelement->data<<endl;
            cin>>childnode;
            Treenode<int>*child=new Treenode<int>(childnode);
            frontelement->children.push_back(child);
            pendingqueue.push(child);
        }
    }
    return root;
}
void preorder(Treenode<int>*root)
{
    cout<<root->data<<" ";
    for(int i=0;i<root->children.size();i++)
    {
        preorder(root->children[i]);
    }
}
void postorder(Treenode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<root->children.size();i++)
    {
        postorder(root->children[i]);
    }
    cout<<root->data<<" ";
}
void print(Treenode<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    for(int i=0;i<root->children.size();i++)
    {
        cout<<root->children[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<root->children.size();i++)
    {
        print(root->children[i]);
    }
}
int main()
{
    Treenode<int>*root=takeinput();
    print(root);
    preorder(root);
    cout<<endl;
    postorder(root);
}
//5 3 6 7 8 0 2 9 10 1 13 1 11 1 14 0 0 0



