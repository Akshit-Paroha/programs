#include<iostream>
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
                cout<<"Welcome to the Jewelry management system!!";
                return 1;
            }
            else
            {
                cout<<"invalid credentials!!";
                return 0;
            }  
        }
};

int main()
{
    admin*ptra = new admin;
    ptra->login();
    delete ptra;
    return 0;
}