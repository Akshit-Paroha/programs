#include <iostream>
using namespace std;

class calculator
{
    public:
    double a;
    double b;

    void input()
    {
        cout<<"Enter your first number:";
        cin>>a;
        cout<<"Enter your second number:";
        cin>>b;
    }

    double add()
    {
        return a+b;
    }
    
    double sub()
    {
        return a-b;
    }

    double mul()
    {
        return a*b;
    }

    double div()
    {
        return a/b;
    }

    void display()
    {
        cout<<"Your sum is:"<<add()<<endl;
        cout<<"your difference is:"<<sub()<<endl;
        cout<<"Your product is:"<<mul()<<endl;
        cout<<"Your division is:"<<div()<<endl;
    }
};

int main()
{
    calculator c;
    c.input();
    c.display();
    return 0;
}