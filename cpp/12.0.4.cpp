#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream i("12.0.3.txt");
    ofstream o("12.0.4.txt",ios::app);
    if(!o||!i)
    {
        cerr<<"failed to open file!!"<<endl;
        return 1;
    }

    string line;
    while (getline(i,line))
    {
        o<<line<<endl;
    }
    cout<<"Data copied from one file to other successfully!"<<endl;
    i.close();
    o.close();
    return 0; 
}