#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream infile("files2.txt");
    if(!infile)
    {
        cerr<<"Failed to open file";
    }
    else 
    {
        string line;

        while (getline(infile,line))
        {
            cout<<line<<endl;
        }
        infile.close();
    }
    return 0;
}