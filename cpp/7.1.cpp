#include<iostream>
using namespace std;

class person
{
	protected:
		string name;
		int age;
		
	public:
		
		void setpersondetails(string n, int a)
		{
			name = n;
			age = a;
		}
		
		void displaypersondetails()
		{
			cout<<"Name: "<<name<<endl<<"age: "<<age<<endl;
		}
};

class student : public person
{
	private:
		float marks;
		
	public:
		
		void setstudentdetails(string n, int a,float m)
		{
			setpersondetails(n,a);
			marks = m;
		}
		
		void displaystudentdetails()
		{
			displaypersondetails();
			cout<<"Marks: "<<marks<<endl;
		}
};


int main()
{
	student s;
	s.setstudentdetails("Akshit Paroha",17,89.67);
	s.displaystudentdetails();
}
