#include <iostream>
#include <cstring>
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
int prec(char op)
{
    switch (op)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}
void infixTopostfix(string e)
{
    stack<int> s;
    string postfix = "";
    for (int i = 0; i < e.size(); i++)
    {
        if (isalnum(e[i]))
        {
            postfix += e[i];
        }
        else if (e[i] == '(')
        {
            s.push(e[i]);
        }
        else if (e[i] == ')')
        {
            while (s.peek() != '(')
            {
                postfix += s.pop();
            }
            char ch = s.pop();
        }
        else
        {
            while (!s.isempty() && prec(s.peek()) >= prec(e[i]))
            {
                postfix += s.pop();
            }
            s.push(e[i]);
        }
    }
    while (!s.isempty())
    {
        postfix += s.pop();
    }
    cout << postfix << endl;
}
int main()
{
    string exp;
    cout << "Enter expression : ";
    cin >> exp;
    cout << "Postfix expression : ";
    infixTopostfix(exp);
    return 0;
}