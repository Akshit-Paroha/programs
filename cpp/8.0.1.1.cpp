#include<iostream>
using namespace std;

class person
{
    protected:
        string name;
        int age;
    
    public:
        person(string n,int a)
        {
            name=n;
            age=a;
        }

        void displayperson()
        {
            cout<<"Name:"<<name<<endl<<"Age:"<<age<<endl;
        }
};

class employee: public person
{
    private:
        int employeeID;
    
    public:

        employee(string n,int a,int id):person(n,a)
        {
            employeeID=id;
        }
        
       void displayemployeedetails()
       {
            cout<<"employee ID: "<<employeeID<<endl;
       }
};

int main()
{
    employee emp1("Akshit Paroha",17,2313602);
    emp1.displayemployeedetails();
}


