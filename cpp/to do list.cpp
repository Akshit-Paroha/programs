#include<iostream>
#include<string>
using namespace std;

class to_do_list
{
    public:
    static int nextday;
    int day;
    int taskdone;

    to_do_list()
    {
        day=++nextday
    }

    void tasks()
    {
        cout<<"enter 1 if task done. enter 0 if not done.";
        cout<<"study:";
        cin>>;
    }

}


