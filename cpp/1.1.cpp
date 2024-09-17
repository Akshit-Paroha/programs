#include<iostream>
using namespace std;

class emplyoee
{
	public:
		string name,ID;
		
		int salary;
		
		void getdetails()
		{
			cout<<"Enter emplyoee name: ";
			cin>>name;
			cout<<"enter emplyoee ID: ";
			cin>>ID;
			cout<<"enter emplyoee salary: ";
			cin>>salary;
			cout<<endl;
		}
		
		void display()
		{
			cout<<endl<<"Emplyoee name: "<<name<<endl;
			cout<<"ID: "<<ID<<endl;
			cout<<"Salary: "<<salary<<endl;
		}
};

int main()
{
	emplyoee a;
	a.getdetails();
	a.display();
}
