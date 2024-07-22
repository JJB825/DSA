#include<iostream>
#include<cstring>
using namespace std;
void mystrcpy(char *s2, char *s1)
{
    while(*s1)
    {
        *s2 = *s1;
        s2++;
        s1++;
    }
}
int main()
{
    char name1[20] = "Jishnu";
    char name2[25]; //always give large size here
    mystrcpy(name2, name1);
    cout<<name2<<endl;
    return 0;
}