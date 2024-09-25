#include<iostream>
using namespace std;

class printer
{
	private:
		string type;
		
	public:
		
		void settype(string t)
		{
			type= t;
		}
		
		void displaytype()
		{
			cout<<"printer type: "<<type<<endl;
		}
};

class scanner
{
	private:
		string brand;
		
	public:
		
		void setbrand(string b)
		{
			brand=b;
		}
		
		void displaybrand()
		{
			cout<<"scanner Brand: "<<brand<<endl;
		}
};

class all_in_one: public printer, public scanner
{
	private:
		int price;
		
	public:
		
		void setallInOne(string t,string b,int p)
		{
			settype(t);
			setbrand(b);
			price = p;
		}
		
		void displayAllInOne()
		{
			displaytype();
			displaybrand();
			cout<<"price: "<<price<<endl;
		}
};

int main()
{
	all_in_one a;
	a.setallInOne("Ink printer","HP",25400);
	a.displayAllInOne();
}
