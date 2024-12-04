#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int Roll;
    float grade;

public:
    void setstudent(string n, int r, float g)
    {
        name = n;
        Roll = r;
        grade = g;
    }

    void displaystudent()
    {
        cout << "name:" << name << endl;
        cout << "Roll number:" << Roll << endl;
        cout << "grade:" << grade << "%" << endl;
    }
};

int main()
{
    const int size = 3;
    student *ptrstudent[size];
    for (int i = 0; i < size; i++)
    {
        ptrstudent[i] = new student();
    }
    ptrstudent[0]->setstudent("Akshit Paroha", 2313602, 89);
    ptrstudent[1]->setstudent("Priyanshu pethe", 2313048, 92);
    ptrstudent[2]->setstudent("shashwat Vaidya", 2313064, 94);

    for (int i = 0; i < size; i++)
    {
        ptrstudent[i]->displaystudent();
        cout << "----------------------" << endl;
    }

    for (int i = 0; i < size; i++)
    {
        delete ptrstudent[i];
    }
}