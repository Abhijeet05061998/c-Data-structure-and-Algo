#include<iostream>
#include<vector>
#include<queue>
using namespace std;
template<typename T>
class BinaryTree
{
    public:
    T data;
    BinaryTree*left;
    BinaryTree*right;

    BinaryTree(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTree()
    {
        delete left;
        delete right;
    }
};

BinaryTree<int>*takeinput()
{
    cout<<"Enter the root data:"<<endl;
    int rootdata;
    cin>>rootdata;

    if(rootdata==-1)
    {
        return NULL;
    }
    BinaryTree<int>*root=new BinaryTree<int>(rootdata);
    queue<BinaryTree<int>*>pendingnode;
    pendingnode.push(root);
    while(pendingnode.size()!=0)
    {
        BinaryTree<int>*frontelement=pendingnode.front();
        pendingnode.pop();
        cout<<"Enter the left child of"<<frontelement->data<<endl;
        int leftchild;
        cin>>leftchild;
        if(leftchild!=-1)
        {
            BinaryTree<int>*child=new BinaryTree<int>(leftchild);
            frontelement->left=child;
            pendingnode.push(child);
        }
        cout<<"Enter the right child of "<<frontelement->data<<endl;
        int rightchild;
        cin>>rightchild;
        if(rightchild!=-1)
        {
            BinaryTree<int>*child=new BinaryTree<int>(rightchild);
            frontelement->right=child;
            pendingnode.push(child);
        }
    }
    return root;
}


bool checkBST(BinaryTree<int>*root,int minimum=INT_MIN,int maximum=INT_MAX)
{
   if(root==NULL)
   {
       return true;
   }
   if(root->data<minimum||root->data>maximum)
   {
       return false;
   }

   bool leftisok=checkBST(root->left,minimum,root->data-1);
   bool rightisok=checkBST(root->right,root->data,maximum);
   return leftisok&&rightisok;
}

void print(BinaryTree<int>*root)
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
    BinaryTree<int>*root=takeinput();
    print(root);
  cout<<checkBST(root);
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
//1 2 38 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
//4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
//4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
