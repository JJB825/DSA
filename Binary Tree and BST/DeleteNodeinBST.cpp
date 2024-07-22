#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *left, *right;
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
    struct node *root = nullptr;
    void insert(int value)
    {
        node *ptr = new node(value);
        if (root == nullptr)
        {
            root = ptr;
        }
        else
        {
            node *p = root;
            node *q = nullptr;
            while (p != nullptr)
            {
                q = p;
                (ptr->info > p->info) ? p = p->right : p = p->left;
            }
            (ptr->info > q->info) ? q->right = ptr : q->left = ptr;
        }
    }
    void inorder(node *root)
    {
        if (root != nullptr)
        {
            inorder(root->left);
            cout << root->info << " ";
            inorder(root->right);
        }
    }
    struct node *inorder_successor(int key)
    {
        node *c = search(key);
        if (c == nullptr)
        {
            return c;
        }
        if (c->right != nullptr)
        {
            node *temp = c->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }
            return temp;
        }
        else
        {
            node *p = root;
            node *q = nullptr;
            while (p->info != key)
            {
                if (p->info > key)
                {
                    q = p;
                    p = p->left;
                }
                else
                {
                    p = p->right;
                }
            }
            return q;
        }
    }
    struct node *search(int key)
    {
        node *temp = root;
        while (temp != nullptr && temp->info != key)
        {
            if (temp->info > key)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        return temp;
    }
    struct node *findParent(int key)
    {
        node *temp = root;
        node *parent = nullptr;
        while (temp != nullptr && temp->info != key)
        {
            if (temp->info > key)
            {
                parent = temp;
                temp = temp->left;
            }
            else
            {
                parent = temp;
                temp = temp->right;
            }
        }
        return parent;
    }
    void deleteNode(int key)
    {
        node *c = search(key);
        if (c == nullptr)
        {
            cout << "Node to be deleted not found.\n";
            return;
        }
        else
        {
            node *par = findParent(key);
            if (c->left == nullptr)
            {
                if (par == nullptr)
                {
                    root = c->right;
                }
                else if (par->left == c)
                {
                    par->left = c->right;
                }
                else
                {
                    par->right = c->right;
                }
                delete c;
            }
            else if (c->right == nullptr)
            {
                if (par == nullptr)
                {
                    root = c->left;
                }
                else if (par->left == c)
                {
                    par->left = c->left;
                }
                else
                {
                    par->right = c->left;
                }
                delete c;
            }
            else
            {
                node *iosucc = inorder_successor(key);
                int succ = iosucc->info;
                deleteNode(iosucc->info);
                c->info = succ;
            }
        }
    }
};
int main()
{
    BST bst;
    int num, e;
    cout << "Enter number of elements to be inserted : ";
    cin >> num;
    cout << "Enter elements one by one : ";
    for (int i = 1; i <= num; i++)
    {
        cin >> e;
        bst.insert(e);
    }
    cout << "Elements : ";
    bst.inorder(bst.root);
    cout << endl;
    int val = 0;
    while (true)
    {
        cout << "Enter -1 if you want to exit.\nEnter the element to be deleted : ";
        cin >> val;
        if (val == -1)
        {
            break;
        }
        bst.deleteNode(val);
        cout << "Elements (after deleting) : ";
        bst.inorder(bst.root);
        cout << endl;
    }
    return 0;
}