#include<iostream>
#define PI 3.14

class circle()
{
    public:
      double R;

      void getradius()
      {
        cout<<"Enter the radius of the circle:";
        cin>>R;
      }

      double area()
      {
        return PI*R*R
      }
};