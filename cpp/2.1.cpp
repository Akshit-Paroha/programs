#include<iostream>
using namespace std;

class shape
{
	public:
		float area(float r)
		{
			return 3.14*r*r;
		}
		
		float area(float length,float breadth)
		{
			return length*breadth;
		}
		
		float triangle(float base,float height,bool istriangle=1)
		{
			return 0.5*base*height;
		}
};

int main()
{
	shape a;
	cout<<"Area of circle is: "<<a.area(10)<<endl;
	cout<<"area of rectangle is: "<<a.area(10,20)<<endl;
	cout<<"area of triangle is: "<<a.triangle(10,2)<<endl;
}
