#include<iostream>
using namespace std;

class ticket
{
    public:
        int basecost,choice,gold,sliver,bronze,available_seats,selectseats;
        ticket()
        {
            basecost=5000;
            available_seats=50;
        }

        void display_deatails()
        {
            cout<<"Ed sheran concert!!"<<endl;
            cout<<"Time of show- 19:30"<<endl;
            cout<<"1)bronze: 5000"<<endl;
            cout<<"2)silver: 10000"<<endl;
            cout<<"3)Gold: 15000"<<endl;
            cout<<"a)total seats available: "<<available_seats<<endl;
        }

        void selection()
        {
        	cout<<endl;
            cout<<"select your ticket choice(1,2 or 3): ";
            cin>>choice;
            cout<<"Enter the number of seats you want to book: ";
            cin>>selectseats;
        }

        int ticket_price()
        {
            return basecost*choice*selectseats+((18/100)*basecost*choice);
        }

        
        int total_seats()
        {
            return available_seats-selectseats;
        }
        
        void bill()
        {
        		cout<<endl;
        	    cout<<"Your total bill is:"<<ticket_price()<<endl;
    			cout<<"Total seats available now- "<<total_seats()<<endl;
		}
};

int main()
{
    ticket a;
    a.display_deatails();
    a.selection();
    a.bill();
}
