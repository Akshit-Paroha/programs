#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream o("12.0.3.txt",ios::app);
    if(!o)
    {
        cerr<<"Failed to create file!!";
        return 1;
    }
    string name;
    int age;
    string address;

    cout<<"Enter your name:";
    getline(cin,name);
    cout<<"Enter your age:";
    cin>>age;
    cin.ignore();
    cout<<"Enter your address: ";
    getline(cin,address);

    o<<"Name:"<<name<<endl;
    o<<"Age:"<<age<<endl;
    o<<"Address:"<<address<<endl;

    o.close();
    cout<<"Data appended to file successfully."<<endl;
    return 0;    

}