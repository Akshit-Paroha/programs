#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream outfile("files.txt");
    if (outfile.is_open())
    {
        outfile<<"Hello, world!";
    
    outfile.close();
    }
    else
    {
        cout<<"failed to open file";
    }
    return 0;
    
}