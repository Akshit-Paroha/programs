#include<iostream>
using namespace std;

class swapB;

class swapA
{
    public:
        int a;
        swapA() 
        {
            a = 10;
            }

        friend void swaping(swapA &a, swapB &b);
};

class swapB
{
    public:
        int b;
        swapB() 
        {
            b = 20; 
        }

        friend void swaping(swapA &a, swapB &b);
};

void swaping(swapA &a, swapB &b)
{
    int temp = a.a;
    a.a = b.b;
    b.b = temp;
}

int main()
{
    swapA objA;
    swapB objB;

    cout << "A before swapping: " << objA.a << endl;
    cout << "B before swapping: " << objB.b << endl;

    swaping(objA, objB);

    cout << "A after swapping: " << objA.a << endl;
    cout << "B after swapping: " << objB.b << endl;

}
