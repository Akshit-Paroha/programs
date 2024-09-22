#include<iostream>
using namespace std;

class volume
{
    public:

        double calculate(double side)
        {
            return side*side*side;
        }

        double calculate(double length,double breadth,double height)
        {
            return length*breadth*height;
        }

        double calculate(double radius,double height)
        {
            return 3.14*radius*radius*height;
        }
};

int main()
{
    volume v;
    cout<<"volume of cube:"<<v.calculate(2)<<endl;
    cout<<"volume of cuboid:"<<v.calculate(2,10,3)<<endl;
    cout<<"volume of cylinder:"<<v.calculate(3,10)<<endl;
    return 0;
}

