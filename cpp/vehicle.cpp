#include<iostream>
using namespace std;

class vehicle
{
	protected:
		string make, model;
		
	public:
		
		void setvehicledetails(string mk,string m)
		{
			make = mk;
			model= m;
		}
		
		void displayvehicleDetails()
		{
			cout<<"make: "<<make<<endl<<"model: "<<model<<endl;
		}
};

class car : public vehicle
{
	private:
		int doors;
		
	public:
		
		void setcardetails(string mk,string m,int d)
		{
			setvehicledetails(mk,m);
			doors = d;
		}
		
		void displaycardetails()
		{
			displayvehicleDetails();
			cout<<"doors: "<<doors<<endl;
		}
};

int main()
{
	car c;
	c.setcardetails("dec 2020","527A",4);
	c.displaycardetails();
}
