#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class admin
{
    private:
        string username;
        string pass;
    public:

        int login()
        {
            cout<<"Enter your username:";
            cin>>username;
            cout<<"Enter your password:";
            cin>>pass;
            if (username=="Admin" && pass=="password")
            {
                cout<<"Welcome to the Jewelry management system!"<<endl;
                return 1;
            }
            else
            {
                cout<<"invalid credentials!!";
                return 0;
            }  
        }
};

class jewellery
{
    public:
        static int nextitem;
        string itemcode,itemname;
        int goldprice; //current price of gold for each gram in inr
        int weight;
        int karat,stone,finalprice,item,stoneprice,qty;

        jewellery()
        {
            goldprice=7700;
            item=nextitem++;
            finalprice = calculateprice();
            stoneprice=calculatestoneprice();
            itemcode = "jw"+ itemname + to_string(item);
        }

        void input()
        {
            cout<<"Enter jewellry name:";
            cin>>itemname;
            cout<<"Enter gold weight of jewellery in grams:";
            cin>>weight;
            cout<<"select your stone:\n1)Diamond\n2)Emerald\n3)ruby\n4)Opal\n5)no stone"<<endl;
            cin>>stone;
            cout<<"Enter Quantity:";
            cin>>qty;
            //cout<<"Enter your gold purity in karat:"
            
        }
        int calculatestoneprice()
        {
            if (stone==1)
            {
                return 25000;
            }
            else if(stone==2)
            {
                return 15000;
            }
            else if(stone==3)
            {
                return 20000;
            }
            else if(stone==4)
            {
                return 10000;
            }
            else
            {
                return 0;
            }
        }

        /*int calculatekarat()
        {
            if(karart>=23)
            {
                return 0.95;
            }
        }*/

        int calculateprice()
        {
            return goldprice*weight+stoneprice;
        }

        void displaydetails()
        {
            cout<<"Jewellry name:"<<itemname<<endl;
            cout<<"Jwellry code:"<<itemcode<<endl;
            cout<<"Price:"<<calculateprice()<<"INR"<<endl;
        }

        void writefile()
        {
            ofstream ofile("detail.txt",ios::app);
            if (!ofile)
            {
                cerr<<"failed to open file!!";
            }
            else
            {
                ofile<<"Jewellry name:"<<itemname<<endl;
                ofile<<"Jwellry code:"<<itemcode<<endl;
                ofile<<"Price:"<<calculateprice()<<"INR"<<endl;
            }  
        }
};
int jewellery::nextitem =1001;

int main()
{
    admin*ptra = new admin;
    ptra->login();
    delete ptra;
    jewellery j;
    j.input();
    j.calculateprice();
    j.displaydetails();
    j.writefile();
    return 0;
}