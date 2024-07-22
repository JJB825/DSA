//Always use swapp name instead of swap
//because swap is predefined function
#include<iostream>
using namespace std;
void swap(int &a,int &b) //Here &a and &b are reference variables. 
                         //They are just different names of same variables.
{
    int temp = a;
    a = b;
    b = temp;
}
void swapPointer(int *a,int *b) //Here &a and &b are pointer variables.
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int a = 2, b = 3;
    cout<<"Values before swapping : \n";
    cout<<"a = "<<a<<"\tb = "<<b<<endl;
    //swap(a,b);
    //cout<<"Values after swapping : \n";
    //cout<<"a = "<<a<<"\tb = "<<b<<endl;
    swapPointer(&a, &b);
    cout<<"Values after swapping : \n";
    cout<<"a = "<<a<<"\tb = "<<b<<endl;
    return 0;
}