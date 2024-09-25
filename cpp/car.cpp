#include<iostream>
using namespace std;

class engine
{
	private:
		int horsepower;
		
	public:
		
		void sethorsepower(int hp)
		{
			horsepower=hp;
		}
		
		void displayhorsepower()
		{
			cout<<"horsepower: "<<horsepower<<"HP"<<endl;
		}
};

class transmission
{
	private:
		string type;
		
	public:
		
		void settransmission(string t)
		{
			type = t;
		}
		
		void displaytransmission()
		{
			cout<<"Transmission: "<<type<<endl;
		}
};

class car : public engine ,public transmission
{
	private:
		int price;
		
	public:
		
		void setcar(int hp,string t,int p)
		{
			sethorsepower(hp);
			settransmission(t);
			price = p;
		}
		
		void displaycar()
		{
			displayhorsepower();
			displaytransmission();
			cout<<"Price: "<<price<<endl;
		}
};

int main()
{
	car c;
	c.setcar(600,"automatic",1200000);
	c.displaycar();
}
