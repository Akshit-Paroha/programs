#include<iostream>
#include<string>
using namespace std;

class library
{
    public:
    string student;
    int fine;

    void input()
    {
        cout<<"Enter student name:";
        cin>>student;
        cout<<"Enter fine:";
        cin>>fine;
    }

    void display()
    {
        cout<<"student name:"<<student<<endl;
        cout<<"fine:"<<fine<<endl;
        
    }

    friend calculatetotalfine(const library &l1,const library &l2)
};

int calculatetotalfine(const library &l1,const library &l2)
{return l1.fine+l2.fine}

int main()
{
    library l1,l2;
    l1.input();
    l1.display();
    l2.input();
    l2.display();
    cout<<"Total fine:"<<int calculatetotalfine();
}
