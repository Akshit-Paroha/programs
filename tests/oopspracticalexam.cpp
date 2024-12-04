#include<iostream>
using namespace std;

class triangle
{
    private:
        double base,height;
    public:
    triangle()
    {
        base= 2;
        height=10;
    }
    triangle(double b,double h)
    {
        base = b;
        height =h;
    }
    double calculate()
    {
        return 0.5*base*height;
    }

    void display()
    {
        cout<<"Area of your triangle is:"<<calculate();
    }
};

int main()
{
    triangle t1;
    triangle t2(20,10);
    cout<<"Area of Your triangle using default constructor is:"<<t1.calculate()<<endl;
    cout<<"Area of your triangle using parameterized constructor is:"<<t2.calculate()<<endl;
}