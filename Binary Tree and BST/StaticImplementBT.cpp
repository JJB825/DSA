#include <iostream>
#define MAX 15
using namespace std;
class binary_tree
{
    char tree[MAX];

public:
    void root(char key)
    {
        tree[0] = key;
    }
    void leftChild(char key, int parent)
    {
        tree[2 * parent + 1] = key;
    }
    void rightChild(char key, int parent)
    {
        tree[2 * parent + 2] = key;
    }
    void inorder(int root)
    {
        if (root < MAX)
        {
            inorder(2 * root + 1);
            if (tree[root] == '\0')
            {
                cout << "";
            }
            else
            {
                cout << tree[root] << " ";
            }
            inorder(2 * root + 2);
        }
    }
};
int main()
{
    binary_tree bt;
    bt.root('3');
    bt.leftChild('2', 0);
    bt.rightChild('6', 0);
    bt.leftChild('1', 1);
    bt.leftChild('5', 2);
    bt.rightChild('7', 2);
    bt.leftChild('4', 5);
    bt.rightChild('8', 6);
    bt.inorder(0);
    return 0;
}
