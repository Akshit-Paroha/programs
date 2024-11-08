#include <iostream>
using namespace std;

class book
{
public:
    string title;
    string author;

    void bookdetails(string t, string a)
    {
        title = t;
        author = a;
    }

    void displaybook()
    {
        cout << "title:" << title << endl
             << "author:" << author << endl;
    }
};

class textbook : public book
{
public:
    string subject;

    void textbookdetails(string t,string a, string s)
    {
        bookdetails(t,a);
        subject=s;
    }
    void displaytextbook()
    {
        displaybook();
        cout<<"subject:"<<subject;
    }
};

int main()
{
    book b;
    textbook t;
    b.bookdetails("the title is title","Akshit");
    b.displaybook();
    t.textbookdetails("Basic mathematics","RD Sharma","Math");
    t.displaytextbook();
}