#include <iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    Complex()
    {
        real = 0;
        imag = 0;
    } 

    Complex(float r, float i) 
    {
        real = r;
        imag = i;
    }

    Complex(const Complex &c)
    {
        real = c.real;
        imag = c.imag;
    }

    Complex add(const Complex &c)
    {
        Complex result;
        result.real = real + c.real;
        result.imag = imag + c.imag;
        return result;
    }

    void display()
    {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main()
{
    Complex c1(2.5, 3.5); 
    Complex c2(c1);       
    Complex c3;           

    c3 = c1.add(c2); 

    cout << "Complex number c1: ";
    c1.display();

    cout << "Complex number c2 (copy of c1): ";
    c2.display();

    cout << "Sum of c1 and c2: ";
    c3.display();

    return 0;
}
