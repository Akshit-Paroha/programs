#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream infile("files2.txt");
    if (infile.is_open())
    {
        string line;
        int linecount=0;
        while (getline(infile,line))
        {
            linecount++;
        }
        infile.close();
        cout<<"Number of lines in files2.txt= "<<linecount<<endl;
    }
    else 
    {
        cerr<<"Failed to open file!!";
    }
    return 0;
}