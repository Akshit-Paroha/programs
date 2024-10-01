#include<iostream>
using namespace std;

class product
{
    private:
        string name;
        string id;
        int price;
    public:
        void setproduct(string n,string i,int p)
        {
            name=n;
            id=i;
            price=p;
        }

        void displayproduct()
        {
            cout<<"Product name:"<<name<<endl;
            cout<<"product id:"<<id<<endl;
            cout<<"Product price:"<<price<<endl;
        }
};

int main()
{
    const int size=3;
    product*ptrP[size];
    for (int i = 0; i < size; i++)
    {
        ptrP[i]=new product();
    }
    
    ptrP[0]->setproduct("music system","245az85",10000);
    ptrP[1]->setproduct("TV","992zya21",31000);
    ptrP[2]->setproduct("laptop","la237z",40000);

    for (int i = 0; i < size; i++)
    {
        ptrP[i]->displayproduct();
        cout<<"---------------------"<<endl;
    }

    for (int i = 0; i < size; i++)
    {
        delete ptrP[i];
    }
    
    
}