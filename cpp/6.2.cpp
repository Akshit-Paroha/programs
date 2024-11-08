#include <iostream>
using namespace std;

class triangle
{
private:
    double base, height;

public:
    triangle()
    {
        base = 10;
        height = 2;
    }
    triangle(int b, int h)
    {
        base = b;
        height = h;
    }

    double calculate()
    {
        return 0.5 * base * height;
    }

    void display()
    {
        cout << "Area of your triangle:" << calculate();
    }
};

int main()
{
    triangle t1;
    triangle t2(2, 20);
    cout << "Area of triangle using default constructor:" << t1.calculate() << endl;
    cout << "Area of triangle using paramaterized constructor:" << t2.calculate() << endl;
}