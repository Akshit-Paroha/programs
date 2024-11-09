#include <iostream>
using namespace std;

class Shape
{
public:
    void displayShape()
    {
        cout << "This is a shape." << endl;
    }
};

class TwoDShape : public Shape
{
public:
    void display2DShape()
    {
        cout << "This is a 2D shape." << endl;
    }
};

class Rectangle : public TwoDShape
{
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area()
    {
        return length * width;
    }

    void displayRectangle()
    {
        cout << "This is a rectangle with area: " << area() << endl;
    }
};

int main()
{
    Rectangle rect(7.0, 2.0);

    rect.displayShape();    
    rect.display2DShape(); 
    rect.displayRectangle();

    return 0;
}
