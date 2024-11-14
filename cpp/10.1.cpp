#include <iostream>
using namespace std;

class payment
{
public:
    string name;
    int amount;
    payment(string n, int a) : name(n), amount(a) {}
    virtual void makepayment()
    {
        cout << "This is base class, makepayment not defined" << endl;
    }
};

class creditcard : public payment
{
private:
    string name;
    int amount;

public:
    creditcard(string n, int a) : name(n), amount(a) {}
    void makepayment() override
    {
        cout << "Payment made via credit card!" << endl;
        cout << "Amount:" << amount << endl;
        cout << "Name of recipient:" << name << endl;
    }
};

class cash : public payment
{
public:
    cash(string n, int a) : name(n), amount(a) {}
    void makepayment() override
    {
        cout << "Payment made via cash!" << endl;
        cout << "Amount:" << amount << endl;
        cout << "Name of recipient:" << name << endl;
    }
};

int main()
{
    payment *payptr;
    creditcard makepayment("Akshit", 10000);
    cash makepayment("Gourav", 20000);

    payptr = &creditcard;
    payptr->makepayment();

    payptr = &cash;
    payptr->makepayment();
}