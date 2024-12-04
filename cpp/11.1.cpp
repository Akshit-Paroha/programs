#include<iostream>
#include<string>
using namespace std;

class BankAccount
{
	float balance;
	double fixed_bal;
	
	public:
		BankAccount(float bal):balance(bal){}
		
		void operator-()
		{
			fixed_bal=100.0;
			balance-=fixed_bal;
			cout<<"Deducted Balance is : "<<balance<<endl;
		}
		
		void display()
		{
			cout<<"Current Balance is : "<<balance<<endl;
		}
};

int main()
{
	BankAccount A(500);
	A.display();
	-A;
	
	return 0;
}