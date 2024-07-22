#include<iostream>
#include<cstring>
using namespace std;
template <class T>
class stack
{
    int top=-1;
    T arr[100];
    public:
    bool isempty()
    {
        return (top==-1)? true:false;
    }
    bool isfull()
    {
        return (top==99)? true:false;
    }
    void push(T n)
    {
        if(isfull())
        {
            cout<<"Stack Overflow.\n";
            return;
        }
        else
        {
            arr[++top]=n;
        }
    }
    T pop()
    {
        if(isempty())
        {
            cout<<"Stack Underflow.\n";
            return T();
        }
        else
        {
            return arr[top--];
        }
    }
    T peek()
    {
        if(isempty())
        {
            cout<<"Stack Underflow.\n";
            return T();
        }
        else
        {
            return arr[top];
        }
    }
};
bool checkPalindrome(char *n)
{
    stack <char>s;
    char a[50];
    strcpy(a,n);
    int i=0;
    while(a[i]!='\0')
    {
        s.push(a[i]);
        i++;
    }
    i=0;
    while(n[i]!='\0')
    {
        if(n[i]!=s.pop())
        {
            return false;
            break;
        }
        i++;    
    }
    return true;
}
int main()
{
    char temp[50];
    cout<<"Enter anything : ";
    cin>>temp;
    if(checkPalindrome(temp))
    {
        cout<<"It is palindrome.\n";
    }
    else
    {
        cout<<"It is not palindrome.\n";
    }
    return 0;
}