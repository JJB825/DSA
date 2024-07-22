#include<iostream>
using namespace std;
struct node
{
    int info;
    node *left,*right;
    node(int data)
    {
        this->info = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class BST
{
    public:
    node *root = nullptr;
    void insert(int key)
    {
        node *ptr = new node(key);
        if (root == nullptr)
        {
            root = ptr;
        }
        else
        {
            node *p=root;
            node *q=nullptr;
            while(p!=nullptr)
            {
                q=p;
                (ptr->info > p->info)? p=p->right : p=p->left;
            }
            (ptr->info > q->info)? q->right=ptr : q->left=ptr;
        }
    }
    void inorder(node *root)
    {
        if(root!=nullptr)
        {
            inorder(root->left);
            cout<<root->info<<" ";
            inorder(root->right);
        }
    }
    struct node *search(int key)
    {
        node *temp=root;
        while(temp!=nullptr && temp->info!=key)
        {
            if(temp->info>key)
            {
                temp=temp->left;
            }
            else
            {
                temp=temp->right;
            }
        }
        return temp;
    }
    node *inorder_predecessor(int key)
    {
        node *c = search(key);
        if(c->left!=nullptr)
        {
            node *curr = c->left;
            while(curr->right!=nullptr)
            {
                curr = curr->right;
            }
            return curr;
        }
        else
        {
            node *p = root;
            node *pred = nullptr;
            while(p!=nullptr)
            {
                if(key<=p->info)
                {
                    p = p->left;
                }
                else
                {
                    pred = p;
                    p = p->right;
                }
            }
            return pred;
        }
    }
};
int main()
{
    BST bst;
    int num,e;
    cout<<"Enter number of elements to be inserted : ";
    cin>>num;
    cout<<"Enter elements one by one : ";
    for(int i=1;i<=num;i++)
    {
        cin>>e;
        bst.insert(e);
    }
    cout<<"Elements : ";
    bst.inorder(bst.root);
    cout<<endl;
    int value;
    cout<<"Enter the value whose predecessor is to be found out : ";
    cin>>value;
    if (bst.inorder_predecessor(value) == nullptr)
    {
        cout<<value<<" doesn't have inorder predecessor.\n";
    }
    else
    {
        cout<<"Inorder predecessor of "<<value<<" is "<<bst.inorder_predecessor(value)->info<<endl; 
    }
    return 0;
}