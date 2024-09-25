#include<iostream>
#include<string.h>
using namespace std;
class cars{
	private:
	string model;
	int charges;
	int ncars;
	public:
		void bookcar(int days)
		{
			if(ncars>0)
			{
				double charges = charges*days;
				double serviceTax = charges*0.12;
				double charges+service Tax;
			}		
		}
		ncars--;
		cout<<" your booking confirmed"<<model<<endl<<days<<"days"<<endl;
	
	else
	{
		cout<<"sorry"<<model<<"is not available for rent"<<endl;
	}
void displaydetails()
{
	cout<<"available cars"<<ncars<<endl;
}
		int main(){
			int choice,days;
			cout<<"enter your choice"<<endl;
			cin>>choice;
			switch(choice){
				case 1:
					cout<<"mercedes"<<endl;
					break;
				case 2:
					cout<<"BMW"<<endl;
					break;
				case 3:
					cout<<"scorpio"<<endl;
						break;
				default:
					cout<<"sorry that cars is not availble"<<endl;
					break;
					
			}
			return 0;
		}
