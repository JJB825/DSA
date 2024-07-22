#include <iostream>
using namespace std;
#define MAX 100
template <class T>
class queue
{
    int rear = -1, front = -1;
    T arr[MAX];

public:
    bool isempty()
    {
        return ((front == -1 && rear == -1) || (front > rear)) ? true : false;
    }
    bool isfull()
    {
        return (rear == MAX - 1) ? true : false;
    }
    void insert_element(T n)
    {
        if (isfull())
        {
            cout << "Queue is full.\n";
            return;
        }
        else
        {
            arr[++rear] = n;
        }
        if (rear == 0)
        {
            front = 0;
        }
    }
    T delete_element()
    {
        if (isempty())
        {
            cout << "Queue is empty.\n";
            return T();
        }
        else
        {
            return arr[front++];
        }
    }
    T peek()
    {
        if (isempty())
        {
            cout << "Queue is empty.\n";
            return T();
        }
        else
        {
            return arr[front];
        }
    }
    int size()
    {
        return rear - front + 1;
    }
    void reinitialize()
    {
        front = -1;
        rear = -1;
    }
};
template <class T>
class stack
{
    queue<T> q1;
    queue<T> q2;

public:
    bool isempty()
    {
        return (q1.isempty() && q2.isempty()) ? true : false;
    }
    bool isfull()
    {
        return (q1.isfull()) ? true : false;
    }
    void push(T e)
    {
        if (isfull())
        {
            cout << "Stack is full.\n";
        }
        else
        {
            q1.insert_element(e);
        }
    }
    T pop()
    {
        if (isempty())
        {
            cout << "Stack is empty.\n";
            return T();
        }
        else
        {
            while (q1.size() != 1)
            {
                q2.insert_element(q1.delete_element());
            }
            T x = q1.delete_element();
            q1.reinitialize();
            while (!q2.isempty())
            {
                q1.insert_element(q2.delete_element());
            }
            q2.reinitialize();
            return x;
        }
    }
    T peek()
    {
        if (isempty())
        {
            cout << "Stack is empty.\n";
            return T();
        }
        else
        {
            while (q1.size() != 1)
            {
                q2.insert_element(q1.delete_element());
            }
            T x = q1.peek();
            q1.reinitialize();
            while (!q2.isempty())
            {
                q1.insert_element(q2.delete_element());
            }
            q2.reinitialize();
            return x;
        }
    }
};
int main()
{
    stack<int> s;
    int choice, num, e, i = 1;
    while (true)
    {
        cout << "Choose any one : \n1. Check Empty\n2. Check Full\n3. Insertion\n4. Display\n5. Exit\nEnter choice code : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            (s.isempty()) ? cout << "Stack is empty\n" : cout << "Stack is not empty\n";
            continue;
        case 2:
            (s.isfull()) ? cout << "Stack is full\n" : cout << "Stack is not full\n";
            continue;
        case 3:
            i = 1;
            cout << "Enter number of elements to be pushed : ";
            cin >> num;
            cout << "Enter elements one by one : \n";
            while (i <= num)
            {
                cin >> e;
                s.push(e);
                i++;
            }
            continue;
        case 4:
            cout << "Stack elements : ";
            while (!s.isempty())
            {
                cout << s.pop() << " ";
            }
            cout << endl;
            continue;
        case 5:
            cout << "Do you wish to continue ? (y/n) : ";
            char ch;
            cin >> ch;
            if (ch == 'y')
            {
                continue;
            }
            else
            {
                cout << "Thank you\n";
                break;
            }
        default:
            cout << "Invalid Choice\n";
        }
        break;
    }
    return 0;
}
