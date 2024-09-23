#include <iostream>
using namespace std;

class NumberCheck 
{
public:
    static bool isEven(int number) 
    {
        return number % 2 == 0;
    }
};

int main() 
{
    int num = 4;
    if (NumberCheck::isEven(num)) 
    {
        cout << num << " is even." << endl;
    } 
    else 
    {
        cout << num << " is odd." << endl;
    }

}