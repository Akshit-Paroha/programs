#include<iostream>
#include<string>
using namespace std;
class bankaccount
{
	public:
		string name;
		string account_number;
		int balance;
		int withdraw;
		int deposit;
		
		void getdetails()
		{
			cout<<"Enter account holder name: ";
			cin>>name;
			cout<<"Enter account number: ";
			cin>>account_number;
			cout<<"enter account balance: ";
			cin>>balance;
			cout<<endl;
		}
		
		void display()
		{
			cout<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Account number: "<<account_number<<endl;
			cout<<"Balance:"<<balance<<endl;
			cout<<endl;
		}
		
		int withdrawl()
		{
			cout<<endl;
			cout<<"Enter amount to withdraw: ";
			cin>>withdraw;
			return balance-withdraw;
			cout<<endl;
		}
		
		int deposited()
		{
			cout<<endl;
			cout<<"Enter amount to deposit: ";
			cin>>deposit;
			return balance+deposit;
			cout<<endl;
		}
		
		
		void newbalancew()
		{
			cout<<"Your new balance after withdrawl is:"<<withdrawl()<<endl;
		}
		
		void newbalanceD()
		{
			cout<<"Your new balance after deposit is:"<<deposited()<<endl;
		}
};

int main()
{
	bankaccount a;
	a.getdetails();
	a.display();
	a.newbalancew();
	a.newbalanceD();
}
