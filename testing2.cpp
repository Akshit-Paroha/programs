#include<iostream>
using namespace std;
class account
{
    int acc_no;
    string name;
    int balance;
    int i;

    public:
        void input()
        {
            cout<<"Enter account number:"<<endl;
            cin>>acc_no;
            cout<<"Enter accountant name:"<<endl;
            cin>>name;
            cout<<"Enter balance:"<<endl;
            cin>>balance;
        }
        void display()
        {
            cout<<"Account details:"<<endl;
            cout<<"Account number:"<<acc_no<<endl;
            cout<<"accountant name:"<<name<<endl;
            cout<<"Balance:"<<balance<<endl;
        }
        friend int checkbalance(account,balance);
};

int checkbalance(account,balance)
{
    if (balance<=1000)
    {
        cout<<"balance is less than 1000"<<endl;
    }
    else
    {
        cout<<"more than 1000"<<endl;
    }
}

int main()
{
    account a[i];
    int i;
    for ( i = 0; i < 8; i++)
    {
        a[i].input();
        a[i].display();
        a[i].checkbalance();
    }
    return 0;
}