#include <iostream>
#define MAX 100
using namespace std;

struct object
{
    int info, priority;
};

class priorityQueue
{
    object obj[MAX];
    int size = -1;

public:
    void insert(int d, int p)
    {
        if (size == MAX - 1)
        {
            cout << "Overflow\n";
            return;
        }

        int i = size;
        while (i >= 0 && obj[i].priority > p)
        {
            obj[i + 1] = obj[i];
            i--;
        }

        if (obj[i].priority == p && obj[i].info > d)
        {
            obj[i + 1] = obj[i];
            obj[i].info = d;
            obj[i].priority = p;
            size++;
        }

        else
        {
            obj[i + 1].info = d;
            obj[i + 1].priority = p;
            size++;
        }
    }

    int extract()
    {
        if (size == -1)
        {
            return -1;
        }

        int x = obj[size].info;
        size--;
        return x;
    }

    void display()
    {
        for (int i = 0; i <= size; i++)
        {
            cout << obj[i].info << " ";
        }
        cout << endl;
    }
};

int main()
{
    priorityQueue pQ;
    int num, val, p;

    cout << "Enter number of elements to be inserted: ";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        cout << "Enter priority: ";
        cin >> p;
        pQ.insert(val, p);
    }

    cout << "The elements in the priority queue: ";
    pQ.display();

    if (pQ.extract() == -1)
    {
        cout << "Empty queue\n";
    }
    cout << "The value with the highest priority is: " << pQ.extract() << endl;

    cout << "Remaining elements in the priority queue: ";
    pQ.display();

    return 0;
}