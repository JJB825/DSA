#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
    node(int d)
    {
        this->info = d;
        this->next = nullptr;
    }
};
class linkedlist
{
public:
    node *start = nullptr;
    void insert(int val)
    {
        node *ptr = new node(val);
        if (start == nullptr)
        {
            start = ptr;
        }
        else
        {
            node *temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = ptr;
        }
    }
    void insertAlt(node *temp1, node *temp2)
    {
        node *p = temp1;
        node *q = temp2;
        if (p == nullptr)
        {
            cout << "LL 1 is empty\n";
            return;
        }
        if (q == nullptr)
        {
            cout << "LL 2 is empty\n";
            return;
        }
        while (temp1 != nullptr || temp2 != nullptr)
        {
            temp2 = temp2->next;
            q->next = p->next;
            p->next = q;
            temp1 = q->next;
            q = temp2;
            if (temp1 == nullptr)
            {
                p = p->next;
                continue;
            }
            p = temp1;
            if (temp2 == nullptr)
            {
                break;
            }
        }
    }
    void display()
    {
        node *temp = start;
        while (temp != nullptr)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    linkedlist ll1, ll2;
    int num, e;
    cout << "Enter number of elements to be inserted in LL1 : ";
    cin >> num;
    cout << "Enter values : ";
    for (int i = 0; i < num; i++)
    {
        cin >> e;
        ll1.insert(e);
    }
    cout << "Enter number of elements to be inserted in LL2 : ";
    cin >> num;
    cout << "Enter values : ";
    for (int i = 0; i < num; i++)
    {
        cin >> e;
        ll2.insert(e);
    }
    cout << "Elements in LL1 : ";
    ll1.display();
    cout << "Elements in LL2 : ";
    ll2.display();
    ll1.insertAlt(ll1.start, ll2.start);
    cout << "Elements in LL1 : ";
    ll1.display();
    return 0;
}