#include<iostream>
using namespace std;

class student
{
    private:
        string name;
        int rollno,marks;
    public:

        student()
        {
            name="Akshit";
            rollno=2313602;
            marks=89;
        }

        student(string n,int r,int m)
        {
            name=n;
            rollno=r;
            marks=m;
        }

        student(const student &s)
        {
            name=s.name;
            rollno=s.rollno;
            marks=s.marks;
        }

        void display()
        {
            cout<<"Name:"<<name<<endl;
            cout<<"Roll number:"<<rollno<<endl;
            cout<<"Marks:"<<marks<<endl;
        }
};

int main()
{
    student s1;
    student s2("Akshit",2313602,89);
    student s3=s2;

    s1.display();
    s2.display();
    s3.display();
}