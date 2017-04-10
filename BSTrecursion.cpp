#include<iostream>
using namespace std;
class bst
{
    public:
    bst *left;
    bst *right;
    int data;
    bst *temp;

    bst * insert_(bst *root,int data)
    {
        if(root==NULL)
        {
            bst * new_node=new bst();
            new_node->left=NULL;
            new_node->right=NULL;
            new_node->data=data;
            root=new_node;
        }
        else if(root->data>data)
        {
            root->left=insert_(root->left,data);
        }
        else if(root->data<data)
        {
            root->right=insert_(root->right,data);
        }

    return root;
    }

    bst * delete_(bst * root,int n)
    {
        if(root==NULL)
        {
            cout<<"does not exists";

        }
        else if(root->data> n)
        {
            root->left=delete_(root->left,n);
        }
        else if(root->data<n)
        {
            root->right=delete_(root->right,n);
        }
        else
        {
            cout<<"no found";
            if(root->left && root->right)
            {
                int x=findmax(root->left);
                root->data=x;
                root->left=delete_(root->left,x);

            }
            else
            {
            if(root->left==NULL)
            {
                temp=root;
                delete temp;
                temp=NULL;
                root=root->right;

            }
           else if(root->right==NULL)
            {
                temp=root;
                delete temp;
                temp=NULL;
                root=root->left;


            }

        }
        }
        return root;

    }


    void pre(bst *root)
    {
        if(root==NULL)
            {
                return;
            }

        cout<<root->data;
        pre(root->left);
        pre(root->right);
    }
    int findmin(bst * root)
    {
        bst * ptr=root;
        while(ptr->left!=NULL)
        {

            ptr=ptr->left;
        }
        int x=ptr->data;
    return x;
    }

    int findmax(bst * root)
    {
    bst * ptr=root;
    while(ptr->right!=NULL)
    {
        ptr=ptr->right;
    }
    int x=ptr->data;
    return x;
    }
int isbst(bst * root)
{
   // cout<<"checking";

    if(root==NULL)
    {
        return 1;
    }
    else
    {
         if(!isbst(root->left) || !isbst(root->right))
    {
        return 0;
    }
    if(root->left!=NULL && (findmax(root->left))>root->data)
    {
        return 0;

    }
    if(root->right!=NULL && (findmin(root->right)<root->data))
    {

        return 0;
    }
    }
    return 1;
}

};
main()
{
    bst * root=NULL;
    int num;
    cin>>num;
    while(num!=-1)
    {
    root=root->insert_(root,num);
    cin>>num ;
    }
   cout<<"enter the no to be deleted";
    int n;
    cin>>n;
    root=root->delete_(root,n);
   int a;
  a=root->isbst(root);
  if(a==1)
    cout<<"is bst";
  else
    cout<<"not";
   root->pre(root);
}
