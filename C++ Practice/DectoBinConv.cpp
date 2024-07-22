#include<iostream>
using namespace std;
int main()
{
    int dec_num;
    cout<<"Enter a number : ";
    cin>>dec_num;
    long b_num = 0;
    while (dec_num != 0)
    {
        b_num += dec_num % 2;
        dec_num /= 2;
    }
    cout<<"The corresponding binary number is : "<<b_num<<endl;
    return 0;
}