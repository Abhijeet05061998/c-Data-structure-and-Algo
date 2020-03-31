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
    queue<Treenode<int>*>pendingnode;
    pendingnode.push(root);

    while(pendingnode.size()!=0)
    {
        Treenode<int>*frontelement=pendingnode.front();
        pendingnode.pop();
        int children;
        cout<<"Enter the no of children "<<frontelement->data<<":"<<endl;
        cin>>children;
        for(int i=0;i<children;i++)
        {
            int childnode;
            cout<<"Enter "<<i<<" th children of "<<frontelement->data<<endl;
            cin>>childnode;
            Treenode<int>*child=new Treenode<int>(childnode);
            frontelement->children.push_back(child);
            pendingnode.push(child);
        }
    }
    return root;
}
int countnode(Treenode<int>*root)
{
    int ans=1;
    for(int i=0;i<root->children.size();i++)
    {
        ans+=countnode(root->children[i]);
    }
    return ans;
}
int sumofnodes(Treenode<int>*root)
{
    int sum=root->data;
    for(int i=0;i<root->children.size();i++)
    {
        sum+=sumofnodes(root->children[i]);
    }
    return sum;
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
       cout<<"total no nodes present in tree is:"<<countnode(root)<<endl;
       cout<<"sum of nodes is:"<<sumofnodes(root);
    }
