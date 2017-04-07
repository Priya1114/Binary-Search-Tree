#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class a
{
    struct node
    {
        int data;
        struct node *left;
        struct node * right;
    };
    queue<struct node *>que;
    struct node * root=NULL;
    struct node * new_node;
    struct node * ptr;
public:
    void create()
    {
        int num;
        cin>>num;
        while(num!=-1)
        {
            new_node =new node;
            new_node->data=num;
            new_node->left=NULL;
            new_node->right=NULL;

            if(root==NULL)
            {
root=new_node;
            }
            else
            {
                ptr=root;
                while(1)
                {
                    if(ptr->data<num)
                    {
                        if(ptr->right==NULL)
                        {
                            ptr->right=new_node;
                            break;
                        }

                    else
                    {
                        ptr=ptr->right;

                    }
                    }
                    else
                    {
                        if(ptr->left==NULL)
                        {
                            ptr->left=new_node;
                            break;

                        }
                        else
                        {

                            ptr=ptr->left;
                        }

                    }

                }

            }

            cin>>num;
        }
    }
    void search_()
    {
        int num;
        cout<<"enter the no to be searched";
        cin>>num;
        ptr=root;
        int f=1;
        while(1)
        {
            if(ptr->data==num)
            {
                f=1;
                cout<<"found";
                break;
            }
            else if(ptr->data<num && ptr->right!=NULL)
            {
                f=1;
                ptr=ptr->right;
            }
            else if(ptr->data>num && ptr->left!=NULL)
            {
                f=1;
                ptr=ptr->left;
            }
            else
            {

                cout<<"not found";
                break;
            }
        }

    }
    void level()
    {
    que.push(root);
    while(!que.empty())
    {
        ptr=que.front();
        cout<<ptr->data<<" ";
        que.pop();
        if(ptr->left!=NULL)
        {
            que.push(ptr->left);
        }
        if(ptr->right!=NULL)
            que.push(ptr->right);
    }
    }
    void pre()
    {
        stack<struct node *> stk;
        stk.push(root);
        while(!stk.empty())
        {
            ptr=stk.top();
            stk.pop();
            cout<<ptr->data<<" ";
            if(ptr->right!=NULL)
                stk.push(ptr->right);
            if(ptr->left!=NULL)
                stk.push(ptr->left);

        }
    }
    void in()
    {
        stack<struct node *> stk;
        while(1)
        {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
            if(!stk.empty())
            {
                root=stk.top();
                stk.pop();
                cout<<root->data<<" ";
                root=root->right;
            }
            else
            {
                break;
            }

        }
    }
    void min_max()
    {

        ptr=root;
        while(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        cout<<ptr->data<<"min ele";

    ptr=root;
    while(ptr->right!=NULL)
    {
        ptr=ptr->right;
    }
    cout<<ptr->data<<"max elem"<<" ";
    }
};
main()
{

    a ob;
    ob.create();
    ob.search_();
    ob.min_max();
    ob.level();
    ob.pre();
    ob.in();

}
