#include<iostream>
using namespace std;

class employee
{
private:
    string name;
    string id;
    int salary;
public:
    employee ()
    {
        name ="nothing";
        id ="xyz";
        salary = 10000;
    }
    employee(string n, string i, int s)
    {
        name = n;
        id = i;
        salary = s;
    }

    void display()
    {
        cout<<"Employee name:"<<name<<endl;
        cout<<"Employee ID:"<<id<<endl;
        cout<<"Employee Salary:"<<salary<<endl;
    }
};

int main()
{
    employee e1;
    employee e2("Akshit","dhkfj54",60000);
    e2.display();
    e1.display();
}