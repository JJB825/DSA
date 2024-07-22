#include <iostream>
#include <cstring>
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
int postfixEval(string e)
{
    stack<int> s;
    for (int i = 0; i < e.size(); i++)
    {
        if (isdigit(e[i]))
        {
            s.push(e[i] - '0');
        }
        else
        {
            int num1 = s.pop();
            int num2 = s.pop();
            switch (e[i])
            {
            case '+':
                s.push(num2 + num1);
                break;
            case '-':
                s.push(num2 - num1);
                break;
            case '*':
                s.push(num2 * num1);
                break;
            case '/':
                s.push(num2 / num1);
                break;
            default:
                break;
            }
        }
    }
    return s.pop();
}
int main()
{
    string exp;
    cout << "Enter valid postfix expression : ";
    cin >> exp;
    cout << "Value of Postfix evaluation : " << postfixEval(exp) << endl;
    return 0;
}