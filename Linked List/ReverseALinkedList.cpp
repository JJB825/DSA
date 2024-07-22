#include <iostream>
using namespace std;
struct node
{
    int info;
    struct node *next;
    node(int data)
    {
        this->info = data;
        this->next = NULL;
    }
};
struct node *start = NULL;
class linkedlist
{
public:
    void insertnode(int data)
    {
        node *p = new node(data);
        if (start == NULL)
        {
            start = p;
        }
        else
        {
            node *temp = start;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = p;
        }
    }
    void display()
    {
        node *temp = start;
        while (temp != NULL)
        {
            cout << temp->info << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
void createlinkedlist(int num)
{
    linkedlist ll;
    int e;
    for (int i = 1; i <= num; i++)
    {
        cin >> e;
        ll.insertnode(e);
    }
}
void reverselinkedlist()
{
    linkedlist ll;
    node *curr = start;
    node *prev = NULL;
    node *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    start = prev;
}
int main()
{
    linkedlist ll;
    int num;
    cout << "Enter number of elements to be inserted : ";
    cin >> num;
    cout << "Enter elements one by one : ";
    createlinkedlist(num);
    cout << "Before reversal : ";
    ll.display();
    reverselinkedlist();
    cout << "After reversal : ";
    ll.display();
    return 0;
}