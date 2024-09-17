#include <iostream>
#include <string>
using namespace std;

class product
{
public:
    static int nextid;
    int id;
    int price;
    string name;
    string category;

    product()
    {
        id = ++nextid;
    }

    void input()
    {
        cout << "Enter product category: ";
        cin >> category;
        cout << "Enter product name: ";
        cin >> name;
        cout << "Enter price: ";
        cin >> price;
    }

    void display()
    {
        cout << "Product ID: " << id << endl;
        cout << "Product name: " << name << endl;
        cout << "Product category: " << category << endl;
        cout << "Product price: " << price << endl;
    }
};

int product::nextid = 1000;

int main()
{
    product p1, p2;
    
    p1.input();
    p1.display();

    p2.input();
    p2.display();

    return 0;
}

