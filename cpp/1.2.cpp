#include<iostream>
using namespace std;

class bankaccount
{
    public:
        string name;
        string account_number;
        int balance,withdraw,deposit;
        
        void getdetails()
        {
            cout << "Enter account holder name: ";
            cin >> name;
            cout << "Enter account number: ";
            cin >> account_number;
            cout << "Enter account balance: ";
            cin >> balance;
            cout << endl;
        }
        
        void display()
        {
            cout << endl;
            cout << "Name: " << name << endl;
            cout << "Account number: " << account_number << endl;
            cout << "Balance: " << balance << endl;
            cout << endl;
        }
        
        void withdrawl()
        {  
            cout << "Enter amount to withdraw: ";
            cin >> withdraw;
            if(withdraw > balance) 
			{
                cout << "Insufficient balance!" << endl;
            } 
			else 
			{
                balance -= withdraw;
                cout << "Amount withdrawn: " << withdraw << endl;
            }
        }
        
        void deposited()
        {
            cout << "Enter amount to deposit: ";
            cin >> deposit;
            balance += deposit;
            cout << "Amount deposited: " << deposit << endl;
        }
        
        void newbalance()
        {
            cout << "Your updated balance is: " << balance << endl;
        }
};

int main()
{
    bankaccount a;
    a.getdetails();
    a.display();
    a.withdrawl();
    a.newbalance();
    a.deposited();
    a.newbalance();
}
