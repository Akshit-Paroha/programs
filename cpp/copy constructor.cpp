#include<iostream>
using namespace std;

class point
{
    private:
        int x,y;
    
    public:
        point()
        {
            x=0;
            y=0;
        }
        point(int xcord,int ycord)
        {
            x=xcord;
            y=ycord;
        }
        point(const point &p)
        {
            x=p.x;
            x=p.y;
        }

        void display()
        {
            cout<<"point("<<x<<","<<y<<")"<<endl;
        }
};

int main()
{
    point p1;
    point p2(5,10);
    point p3=p2;

    p1.display();
    p2.display();
    p3.display();
}