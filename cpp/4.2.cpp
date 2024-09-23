#include <iostream>
using namespace std;

class CompareB;

class CompareA 
{
    private:
        int valueA;
    public:
        CompareA(int a) : valueA(a) {}
        friend void compareValues(const CompareA&, const CompareB&);
};

class CompareB 
{
    private:
        int valueB;
    public:
        CompareB(int b) : valueB(b) {}
        friend void compareValues(const CompareA&, const CompareB&);
};

void compareValues(const CompareA& a, const CompareB& b) 
{
    if (a.valueA > b.valueB) 
    {
        cout << "A has the larger value." << endl;
    } 
    
    else if (a.valueA < b.valueB) 
    {
        cout << "B has the larger value." << endl;
    } 
    else 
    {
        cout << "Both have the same value." << endl;
    }
}

int main() 
{
    CompareA a(10);
    CompareB b(20);
    compareValues(a, b);
}