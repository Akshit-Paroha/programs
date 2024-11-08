#include <iostream>
using namespace std;

class Date
{
private:
    int day, month, year;

public:
    Date()
    {
        day = 1;
        month = 1;
        year = 2000;
    }

    Date(int d, int m)
    {
        day = d;
        month = m;
        year = 2000;
    }

    Date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void display() const
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    Date date1;
    Date date2(31, 8);
    Date date3(25, 9, 2024);
    cout << "Default date: ";
    date1.display();
    cout << "Date with specific day and month: ";
    date2.display();
    cout << "Date with specific day, month, and year: ";
    date3.display();

    return 0;
}
