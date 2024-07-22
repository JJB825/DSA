// Program to determine wheter a point is inside the circle or not.

#include<iostream>
#include<cmath>
using namespace std;
class Point;
class circle
{
    protected: 
    int xcor,ycor,rad;
    public:
    void getdata()
    {
        cout<<"Enter coordinates of center (xcor,ycor) : ";
        cin>>xcor>>ycor;
        cout<<"Enter radius of circle : ";
        cin>>rad;
    }
    friend bool inCircle(circle c1, Point p1);
};
class Point
{
    int x,y;
    public: 
    void getdata()
    {
        cout<<"Enter the coordinates of point P (x,y) : ";
        cin>>x>>y;
    }
    friend bool inCircle(circle c1, Point p1)
    {
        return ((float)(pow((p1.x-c1.xcor),2) + pow((p1.y-c1.ycor),2)) < (float)(pow((c1.rad),2))) ? true : false;
    }
};
int main()
{
    circle c;
    Point p;
    c.getdata();
    p.getdata();
    if(inCircle(c,p)==true)
        cout<<"The point is inside the circle.\n";
    else
        cout<<"The point is outside the circle.\n";
    return 0;
}