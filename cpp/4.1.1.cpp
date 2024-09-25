#include<iostream>
using namespace std;

class swapB;

class SwapA
{
    private:
        int A;

    public:
       void inputA()
        {
            cout<<"enter your first number: ";
            cin>>A;
        }
        
        friend int display(int &A, int &B);
};

class swapB
{
    private:
        int B;

    public:
         void inputB()
        {
            cout<<endl<<"Enter Your second number: ";
            cin>>B;
        }
        friend int display(int &A, int &B);
};

int display(SwapA &A,swapB &B)
{
    int temp;
    cout<<"Your number before swap are: A="<<A;
    cout<<"B="<<B<<endl;
    temp=A;
    A=B;
    B=temp;
    cout<<"Your number After swap are: A="<<A<<"B="<<B<<endl;
}

int main()
{
    SwapA::inputA();
    swapB::inputB();
    int display();
}
