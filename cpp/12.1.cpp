#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    ifstream i("story.txt");
    if (!i)
    {
        cerr<<"Failed to open file!"<<endl;
        return 1;
    }

    string line;
    int count=0;
    while (getline(i,line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            count++;
        }
    }
    i.close();
    cout<<"Number of words in file 'story.txt' ="<<count<<endl;
    return 0;
    
}
