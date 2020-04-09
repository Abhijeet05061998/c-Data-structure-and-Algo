#include<iostream>
using namespace std;

class BinaryTree
{
    int data;
    BinaryTree*left;
    BinaryTree*right;
    BinaryTree(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
class BST
{
    private:
    int *root;
    BST(int )

    private:
         BinaryTree<int>*deleteData( BinaryTree<int>*node)
        {
           if(node==NULL)
           {
               return NULL;
           }
           if(data>node->data)
           {
               node->right=deleteData(data,node->right);
           }
           else if(data<node->data)
           {
               node->left=deleteData(data,node->left);
           }
           else
           {
               if(node->data==NULL&&node->right==NULL)
               {
                   delete node;
                   return NULL;
               }
               else if(node->left==NULL)
               {
                    BinaryTree<int>*temp=node->right;
                   delete node;
                   return temp;
               }
               else if(node->right==NULL)
               {
                    BinaryTree<int>*temp=node->left;
                    node->left=NULL;
                    delete node;
                    return temp;
               }
               else
               {
                    BinaryTree<int>*minnode=node->right;
                    while(minnode->left!=NULL)
                    {
                        minnode=minnode->left;
                    }
                    int rightmin=minnode->data;
                    node->data=rightmin;
                    node->right=deleteData(rightmin,node->right);
                    return node;
               }
           }
        }
    public:
    void deleteData(int data)
    {

    }
    private:
    BinaryTree<int>* insertData( BinaryTree<int>*node)
    {
        if(node==NULL)
        {
             BinaryTree<int>*newNode=new  BinaryTree<int>(data);
             return newNode;
        }
        if(data<node->data)
        {
            node->left=insertData(data,node->left);
        }
        else
        {
            node->right=insertData(data,node->right);
        }
        return node;
    }
    private:
        bool hashData(BinaryTree<int>*node)
        {
            if(node==NULL)
            {
                return;
            }
            if(node->data==data)
            {
                return true;
            }
            else if(data<node->data)
            {
                return hashData(data,node->left);
            }
            else
            {
                return return hashData(data,node->right);
            }
        }
    public:
        bool hashData(int data)
        {
            return hashData(data,node->right);
        }
};
