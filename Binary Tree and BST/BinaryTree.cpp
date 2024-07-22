#include <bits/stdc++.h>
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
node *createNode(int key)
{
    node *ptr = new node(key);
    return ptr;
}
int countTotalnodes(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        return 1 + countTotalnodes(root->left) + countTotalnodes(root->right);
    }
}
int countleafNodes(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else if (!root->left && !root->right)
    {
        return 1;
    }
    else
    {
        return countleafNodes(root->left) + countleafNodes(root->right);
    }
}
int countNonleafNodes(node *root)
{
    if (root == nullptr || !root->left && !root->right)
    {
        return 0;
    }
    else
    {
        return 1 + countNonleafNodes(root->left) + countNonleafNodes(root->right);
    }
}
int maxDepth(node *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    else
    {
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        int maxdepth = 1 + max(leftDepth, rightDepth);
        return maxdepth;
    }
}
node *mirror(node *root)
{
    if (!root)
        return root;
    node *leftSubtree = mirror(root->left);
    node *rightSubtree = mirror(root->right);
    node *temp = leftSubtree;
    leftSubtree = rightSubtree;
    rightSubtree = temp;
    root->left = leftSubtree;
    root->right = rightSubtree;
    return root;
}
int countNodes(node *root)
{
    if (!root)
        return 0;
    int leftNodes = countNodes(root->left);
    int rightNodes = countNodes(root->right);
    cout << "For " << root->info << " : \n";
    cout << "Nodes in left subtree : " << leftNodes << endl;
    cout << "Nodes in right subtree : " << rightNodes << endl
         << endl;
    return 1 + leftNodes + rightNodes;
}
void preorder(node *root)
{
    if (root)
    {
        cout << root->info << " ";
        preorder(root->left);
        preorder(root->right);
    }
}
bool leftSkewedBt(node *root)
{
    if (root->left && !root->right)
    {
        return leftSkewedBt(root->left);
    }
    else if (root->right)
    {
        return false;
    }
    else if (!root->left && !root->right)
    {
        return true;
    }
}
int main()
{
    node *root = nullptr;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->left->left = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    if (countTotalnodes(root) % 2 != 0)
    {
        cout << "Strict Binary tree\n";
    }
    else
    {
        cout << "Not Strict binary tree\n";
    }
    cout << "Number of leafnodes is " << countleafNodes(root) << endl;
    cout << "Number of Nonleafnodes is " << countNonleafNodes(root) << endl;
    cout << "Depth of graph is " << maxDepth(root) << endl;
    preorder(root);
    cout << endl;
    root = mirror(root);
    preorder(root);
    cout<<endl;
    countNodes(root);
    if (leftSkewedBt(root))
    {
        cout << "Left Skewed Binary Tree\n";
    }
    else
    {
        cout << "Not left Skewed Binary Tree\n";
    }
    return 0;
}