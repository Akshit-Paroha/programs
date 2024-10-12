#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream in("12.0.1.txt");
    if (!in)
    {
        cerr<<"Failed to open file!";
        return 1;
    }
    string line;
    cout<<"Reading data from file..."<<endl;
    while (getline(in,line))
    {
        cout<<line<<endl;
    }
    in.close();
    return 0;
}