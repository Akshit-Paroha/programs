#include<iostream>
using namespace std;

class shape
{
    public:
        virtual void area()
        {
            cout<<"Base class: Area calculation is not defined"<<endl;
        }
};

class circle : public shape
{
    private:
        double radius;
    public:
        circle(double r): radius(r){}
        void area()override
        {
            cout<<"Circle area: "<<3.14159*radius*radius<<endl;
        }
};

class rectangle:public shape
{
    private:
        double length,breadth;
    public:
        rectangle(double l, double b):length(l),breadth (b){}
        void area()override
        {
            cout<<"Area of rectangle:"<<length*breadth<<endl;
        }
};

int main()
{
    shape*shapeptr;
    circle circle(5.0);
    rectangle rectangle(4.0,10.0);

    shapeptr=&circle;
    shapeptr->area();

    shapeptr=&rectangle;
    shapeptr->area();
}
