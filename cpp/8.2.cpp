#include<iostream>
#include<string>
using namespace std;

class Appliance{
	protected:
		string brand;
	public:
		Appliance(string n) : brand(n){}
		
		void displayApplianceData(){
			cout<<"Appliance Name : "<<brand<<endl;
		}
};

class WashingMachine : public Appliance{
	protected:
		int launchyear;
	public:
		WashingMachine(string n , int l ) : Appliance(n) , launchyear(l){}
		
		void displayWashingMachineData(){
			cout<<"Launching Year : "<<launchyear<<endl;
		}
};	

class Refrigerator : public Appliance{
	protected:
		int launchyear;
	public:
		Refrigerator(string n , int l) : Appliance(n) , launchyear(l) {}
		
		void displayRefrigeratorData(){
			displayApplianceData();
			cout<<"Launching Year : "<<launchyear<<endl;
		}
};

class SmartFridge : public Refrigerator{
	protected:
		float price;
	public:
		SmartFridge(string n , int l , int p) : Refrigerator( n , l ) , price(p){}
		
		void displaySmartFridge(){
			displayRefrigeratorData();
			cout<<"Price : "<<price<<endl;
		}
};

int main(){
	SmartFridge sf("samsung" , 2024 , 20000);
	cout<<"Smart Fridge Details!!"<<endl;
	sf.displaySmartFridge();
}