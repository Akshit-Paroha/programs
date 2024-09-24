#include<iostream>
using namespace std;

class book
{
    private:
        string title;
        string author;
        float price;
    
    public:
        void setdetails(string t, string a, float p)
        {
            title =t;
            author=a;
            price = p;
        }

        void displaydetails()
        {
            cout<<"Title:"<<title<<endl;
            cout<<"Author:"<<author<<endl;
            cout<<"price:$"<<price<<endl;
        }
};

int main()
{
    book*ptrBook =new book;
    ptrBook->setdetails("programming in C++ language","Bjarne stroustrup",45.99);
    cout<<"Book details:"<<endl;
    ptrBook->displaydetails();
    delete ptrBook;
}