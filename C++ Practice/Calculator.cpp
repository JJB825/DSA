#include<iostream>
#include<cmath>
using namespace std;
class SimpleCalculator
{
    protected :
    float a,b,c,d,e,f;
    public :
    void setdata(float x,float y)
    {
        a = x;
        b = y;
    }
    void utility()
    {
        c = a + b;    
        d = a - b;
        e = a * b;
        f = a / b;
    }
};
class ComplexCalculator
{
    protected :
    float g,h,i,j,k,l,m;
    public :
    void setdata(float x,float y)
    {
        g = x;
        h = y;
    }
    void utility()
    {
        i = pow(g,h);
        j = log10(g);
        k = log10(h);
        l = cos(g);
        m = cos(h);
    }
};
class HybridCalculator : public SimpleCalculator, public ComplexCalculator
{
    public :
    void display1()
    {
        cout<<SimpleCalculator::a<<" + "<<SimpleCalculator::b<<" = "<<SimpleCalculator::c<<endl;
        cout<<SimpleCalculator::a<<" - "<<SimpleCalculator::b<<" = "<<SimpleCalculator::d<<endl;
        cout<<SimpleCalculator::a<<" * "<<SimpleCalculator::b<<" = "<<SimpleCalculator::e<<endl;
        cout<<SimpleCalculator::a<<" / "<<SimpleCalculator::b<<" = "<<SimpleCalculator::f<<endl;
    }
    void display2()
    {
        cout<<"pow(g,h) = "<<ComplexCalculator::i<<endl;
        cout<<"log10(g) = "<<ComplexCalculator::j<<endl;
        cout<<"log10(h) = "<<ComplexCalculator::k<<endl;
        cout<<"cos(g) = "<<ComplexCalculator::l<<endl;
        cout<<"cos(h) = "<<ComplexCalculator::m<<endl;
    }
};
int main()
{
    // SimpleCalculator s;
    // ComplexCalculator C;
    HybridCalculator h;
    float a,b,c,d;
    cout<<"Enter two values : ";
    cin>>a>>b;
    h.SimpleCalculator :: setdata(a,b);
    h.display1();
    cout<<"Enter two values : ";
    cin>>c>>d;
    h.ComplexCalculator :: setdata(c,d);
    h.display2();
    return 0;
}