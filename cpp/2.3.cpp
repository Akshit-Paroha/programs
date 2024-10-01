#include<iostream>
#include<string>
using namespace std;

class concatenate
{
    public:
        string concat(string a, string b)
        {
            return a + b;
        }
        string concat(string a, string b, string c)
        {
            return a + b + c;
        }
        string concat(string a, int d)
        {
            return a + to_string(d); // Convert int to string before concatenating
        }
};

int main()
{
    concatenate a;
    cout << "Two strings added: " << a.concat("hello", " Akshit") << endl;
    cout << "Three strings added: " << a.concat("C++ ", "programming ", "Language") << endl;
    cout << "String and int added: " << a.concat("Hello ", 2313602) << endl;
}
