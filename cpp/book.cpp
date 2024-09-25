#include<iostream>
using namespace std;

class book
{
	private:
		string title,author;
		
	public:
		
		void setbookdetails(string t, string a)
		{
			title=t;
			author=a;
		}
		
		void displaybookdetails()
		{
			cout<<"Book title: "<<title<<endl<<"book author: "<<author<<endl;
		}
};

class textbook : public book
{
	protected:
		string subject;
		
	public:
		
		void settextbookdetails(string t, string a,string s)
		{
			setbookdetails(t,a);
			subject = s;
		}
		
		void displaytextbookdetails()
		{
			displaybookdetails();
			cout<<"subject: "<<subject<<endl;
		}
};


int main()
{
	textbook t;
	t.settextbookdetails("basic mathematics","S. Chand","Math");
	t.displaytextbookdetails();
}
