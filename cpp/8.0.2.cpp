#include<iostream>
using namespace std;

class vehicle
{
	protected:
		string make;
	
	public:
		vehicle (string m)
		{
			make=m;
		}
		
		void makedetails()
		{
			cout<<"Make:"<<make<<endl;
		}
};

class car:public vehicle
{
	protected:
		string model;
		
	public:
		car(string m,string mdl):vehicle(m)
		{
			model=mdl;
		}
		
		void displaycar()
		{
			makedetails();
			cout<<"Car model:"<<model;
		}
};

class sportscar:public car
{
	private:
		int horsepower
}
