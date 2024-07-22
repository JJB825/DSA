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
    int val;
    cout << "Enter the element to be searched : ";
    cin >> val;
    if (bst.search(val) == nullptr)
    {
        cout << "Value not found\n";
    }
    else
    {
        cout << "Value " << bst.search(val)->info << " found.\n";
    }
    int value;
    cout << "Enter the value whose successor is to be found out : ";
    cin >> value;
    if (bst.inorder_successor(value) == nullptr)
    {
        cout << value << " doesn't have inorder successor.\n";
    }
    else
    {
        cout << "Inorder successor of " << value << " is " << bst.inorder_successor(value)->info << endl;
    }
    return 0;
}