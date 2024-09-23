#include <iostream>
using namespace std;

class MathOperations 
{
public:
    static long long factorial(int number) 
    {
        if (number <= 1) return 1;
        return number * factorial(number - 1);
    }
};

int main() 
{
    int num = 5;
    cout << "Factorial of " << num << " is " << MathOperations::factorial(num) << endl;
}