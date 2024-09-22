#include<iostream>
#include<string>
using namespace std;
int add(int a,int b)
{
    return a+b;
}
double add(double a,double b)
{
    return a+b;
}
string add(const string& a, const string& b)
{
    return a+b;
}
int main()
{
    int int1=5,int2=10;
    double double1=5.5, double2=10.5;
    string str1="Hello",str2=" World!";
    cout<<"sum of integers:"<<add(int1,int2)<<endl;
    cout<<"sum of doubles:"<<add(double1,double2)<<endl;
    cout<<"concantenation of strings:"<<add(str1,str2);
    return 0;
}
