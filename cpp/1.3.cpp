#include<iostream>
using namespace std;

class rectangle
{
	public:	
		int calculatearea(int length,int breadth=1)
		{
			return length*breadth;
		}
};

int main()
{
	rectangle a;
	cout<<"Your area of rectangle is: "<<a.calculatearea(10,20)<<endl;
	cout<<"your area of square is: "<<a.calculatearea(10)<<endl;
}

