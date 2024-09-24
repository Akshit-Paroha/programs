#include <iostream>
using namespace std;

class MultiplyB;

class MultiplyA 
{
private:
    int valueA;
public:
    MultiplyA(int a) : valueA(a) {}
    friend void multiplyValues(const MultiplyA&, const MultiplyB&);
};

class MultiplyB 
{
private:
    int valueB;
public:
    MultiplyB(int b) : valueB(b) {}
    friend void multiplyValues(const MultiplyA&, const MultiplyB&);
};

void multiplyValues(const MultiplyA& a, const MultiplyB& b) {
    int result = a.valueA * b.valueB;
    cout << "The product of the values is " << result << endl;
}

int main() 
{
    MultiplyA a(5);
    MultiplyB b(4);
    multiplyValues(a, b);

}