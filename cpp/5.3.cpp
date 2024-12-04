#include <iostream>
using namespace std;

class book
{
private:
    string title;
    string author;
    int price;    
public:
    book()
    {
        title = "Object oriented programming";
        author = "Akshit Paroha";
        price = 6000;
    }
    book(string t,string a,int p)
    {
        title = t;
        author = a;
        price = p;
    }
    book(book &b)
    {
        title = b.title;
        author=b.author;
        price=b.price;
    }

    void display()
    {
        cout<<"BOOK TITLE:"<<title<<endl;
        cout<<"BOOK AUTHOR:"<<author<<endl;
        cout<<"BOOK PRICE:"<<price<<endl;
    }
};

int main()
{
    book b1("DSA","XYZ",1000);
    book b2;
    book b3(b1);
 
    b1.display();
    b2.display();
    b3.display();
}