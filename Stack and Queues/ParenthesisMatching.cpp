#include <iostream>
#include <string>
#define MAX 100
using namespace std;
template <class T>
class stack
{
    int top = -1;
    T arr[MAX];

public:
    bool isempty()
    {
        return (top == -1) ? true : false;
    }
    bool isfull()
    {
        return (top == MAX - 1) ? true : false;
    }
    void push(T n)
    {
        if (isfull())
        {
            cout << "Stack Overflow.\n";
            return;
        }
        else
        {
            arr[++top] = n;
        }
    }
    T pop()
    {
        if (isempty())
        {
            cout << "Stack Underflow.\n";
            return T();
        }
        else
        {
            return arr[top--];
        }
    }
    T peek()
    {
        if (isempty())
        {
            cout << "Stack Underflow.\n";
            return T();
        }
        else
        {
            return arr[top];
        }
    }
};
bool check(string e)
{
    stack<char> s;
    for (int i = 0; i < e.size(); i++)
    {
        if ((e[i] == '(') || (e[i] == '{') || (e[i] == '['))
        {
            s.push(e[i]);
        }
        else if ((e[i] == ')') || (e[i] == '}') || (e[i] == ']'))
        {
            char popped = s.pop();
            if ((e[i] == ')' && popped == '(') || (e[i] == '}' && popped == '{') || (e[i] == ']' && popped == '['))
            {
                continue;
            }
            else
            {
                return false;
                break;
            }
        }
    }
    if (s.isempty())
        return true;
    else
        return false;
}
int main()
{
    string exp;
    cout << "Enter any expression : ";
    cin >> exp;
    (check(exp)) ? cout << "Valid Expression\n" : cout << "Invalid Expression\n";
    return 0;
}