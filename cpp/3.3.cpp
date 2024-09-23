#include <iostream>
using namespace std;

class GCD 
{
    public:
        static int findGCD(int a, int b) 
        {
            while (b != 0) 
            {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
};

int main() 
{
    int num1 = 56;
    int num2 = 98;
    cout << "GCD of " << num1 << " and " << num2 << " is " << GCD::findGCD(num1, num2) << endl;

}