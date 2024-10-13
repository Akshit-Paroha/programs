#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream i("story.txt");
    if(!i)
    {
        cerr<<"failed to open file!"<<endl;
        return 1;
    }
    string line;
    string find;
    int linecount = 0;
    bool found = false;

    cout<<"Enter word to find in 'story.txt': ";
    cin>>find;
    while (getline(i,line))
    {
        linecount++;
        if(line.find(find)!=string::npos)
        {
            cout<<"Word found in line number:"<<linecount;
            found=true;
        }
    }

    if(!found)
    {
        cout<<"Word was not found!";
    }
    i.close();
    return 0;
}