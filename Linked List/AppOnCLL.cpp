#include <iostream>
using namespace std;
struct node
{
    int info;
    node *next;
    node(int data)
    {
        this->info = data;
        this->next = NULL;
    }
};
class circularlinkedlist
{
public:
    node *last = NULL;
    void insert(int data)
    {
        node *p = new node(data);
        if (last == NULL)
        {
            last = p;
            p->next = last;
        }
        else
        {
            p->next = last->next;
            last->next = p;
            last = p;
        }
    }
    void display()
    {
        node *temp = last->next;
        do
        {
            cout << temp->info << " ";
            temp = temp->next;
        } while (temp != last->next);
        cout << endl;
    }
    void JohnsCounter(int k)
    {
        node *p = last;
        while (true)
        {
            for (int i = 1; i < k; i++)
            {
                p = p->next;
            }
            if (p->next == p)
            {
                cout << p->info << " ";
                last = nullptr;
                break;
            }
            if (p->next == last)
            {
                last = p;
            }
            cout << p->next->info << " ";
            p->next = p->next->next;
            cout << " ";
        }
        cout << endl;
    }
};
int main()
{
    circularlinkedlist cll;
    int num, e;
    cout << "Enter number of elements to be inserted : ";
    cin >> num;
    cout << "Enter elements one by one : ";
    for (int i = 1; i <= num; i++)
    {
        cin >> e;
        cll.insert(e);
    }
    cll.display();
    int counter;
    cout << "Enter value of counter : ";
    cin >> counter;
    cll.JohnsCounter(counter);
    return 0;
}