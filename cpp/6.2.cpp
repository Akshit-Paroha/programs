#include<iostream>
using namespace std;

class triangle
{
private:
    double base,height;
public:
    triangle()
    {
        base= 0;
        height=0;
    }
    triangle( b,  h)
    {
        base = b;
        height = h;
    }

    double calculate()
    {
        return 1/2*base*height;
    }

    void display()
    {
        cout<<"Area of your triangle:"<<calculate();
    }
}

int main()
{
    
}