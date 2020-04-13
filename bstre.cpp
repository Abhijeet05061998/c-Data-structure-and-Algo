#include<iostream>
#include<queue>
#include<vector>
using namespace std;
template<typename T>
class Node
{
public:

    T data;
    Node*left;
    Node*right;
    Node(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~Node()
    {
        delete left;
        delete right;
    }
};
Node<int>*takeinput()
{
    int rootdata;
    cout<<"Enter the root data:"<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    Node<int>*root=new Node<int>(rootdata);
    queue<Node<int>*>pendingNode;
    pendingNode.push(root);
    while(pendingNode.size()!=0)
    {
        Node<int>*frontelement=pendingNode.front();
        pendingNode.pop();
        cout<<"Enter the left child of "<<frontelement->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            Node<int>*child=new Node<int>(leftchild);
            frontelement->left=child;
            pendingNode.push(child);
        }

        cout<<"Enter the right child of "<<frontelement->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            Node<int>*child=new Node<int>(rightchild);
            frontelement->right=child;
            pendingNode.push(child);
        }
    }
    return root;
}

int bst(Node<int>*root,int k)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->data==k)
    {
        return true;
    }
    else if(k<root->data)
    {
        int a=bst(root->left,k);
        if(a==k)
        {
            return true;
        }
    }
    else if(k>root->data)
    {
        int b=bst(root->right,k);
        if(b==k)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
void inorder(Node<int>*root,vector<int> &v)
{
if(root==NULL)
{
    return;
}
inorder(root->left,v);
v.push_back(root->data);
inorder(root->right,v);
}
int secondLargest(Node<int>*root,int n)
{
    vector<int>v;
    inorder(root,v);
    if(n<=v.size())
    {
        return v[n-1];
    }
    else
    {
        return -1;
    }
}
void print(Node<int>*root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<":";
    if(root->left!=NULL)
    {
        cout<<"L"<<root->left->data;
    }
    if(root->right!=NULL)
    {
        cout<<"R"<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
int main()
{
    Node<int>*root=takeinput();
    print(root);
    int k,n;
    cin>>k>>n;
    cout<<bst(root,k)<<endl;
    cout<<"secondLargest no:"<<secondLargest(root,n);
}
