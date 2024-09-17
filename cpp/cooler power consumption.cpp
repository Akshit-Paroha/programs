#include <iostream>
using namespace std;

#define days 31
#define PF 3.5
#define hrs 8

class cooler 
{
public:
    int blades;
    double size;

    void input() 
    {
        cout << "Enter the number of blades in your cooler: ";
        cin >> blades;
        cout << "Enter the size of your cooler: ";
        cin >> size;
    }

    double daily_consumption() 
    {
        return PF * hrs * blades * size;
    }

    double monthly_consumption()
    {
        return PF * hrs * blades * size * days;
    }

    void display() 
    {
        cout << "Your daily consumption is: " << daily_consumption() << endl;
        cout << "Monthly consumption is: " << monthly_consumption() << endl;
    }
};

int main() 
{
    cooler c;
    c.input();
    c.display();
    return 0;
}