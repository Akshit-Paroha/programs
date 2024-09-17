#include<iostream>
using namespace std;

class student
{
    public:
    string name;
    string branch;
    int age;

    student(){
        name="Akshit";
        age=16;
    }

    void display()
    {
       cout<<" information of student";
        cout<<"name:"<<name;
        cout<<"branch:"<<branch;
        cout<<"age:"<<age;
    }
}

int main()
{
    student s;
    s.display();
}


