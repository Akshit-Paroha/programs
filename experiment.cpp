#include <iostream>
using namespace std;

class Complex
{
public:
    int real, imag;

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const &obj)
    {
        return Complex(real + obj.real, imag + obj.imag);
    }
};

int main()
{
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2; // Uses overloaded + operator
    cout << c3.real << " + i" << c3.imag << endl;
    return 0;
}
