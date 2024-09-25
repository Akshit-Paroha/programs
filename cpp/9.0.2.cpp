#include<iostream>
using namespace std;

class employee
{
    private:
        string name;
        int id;
        float salary;
    public:
        void setdetails(string n,int i, float s)
        {
            name =n;
            id=i;
            salary=s;
        }
        void displaydetails()
}