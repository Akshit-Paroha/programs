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
        {
            cout<<"Name:"<<name<<endl;
            cout<<"ID:"<<id<<endl;
            cout<<"Salary:"<<salary<<endl;
        }
};

int main()
{
    const int size =3;
    employee emp[size];
    emp[0].setdetails("Alice",101,55000);
    emp[1].setdetails("bob",102,65000);
    emp[2].setdetails("Charlie",103,60000);

    cout<<"employee details: "<<endl;

    for (int i = 0; i < size; i++)
    {
        emp[i].displaydetails();
        cout<<"--------------"<<endl;
    }
    
}
