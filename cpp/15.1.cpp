#include <iostream>
using namespace std;

template <typename T>
void max(T &a, T &b, T &c)
{
    if (a > b && a > c)
    {
        printf("%d is greater!!\n", a);
    }
    else if (b > a && b > c)
    {
        printf("%d is greater!!\n", b);
    }
    else
    {
        printf("%d is greater!!\n", c);
    }
}

int main()
{
    int int1 = 10, int2 = 20, int3 = 15;
    // float float1 = 1.5, float2 = 2.5,float3=3.2;
    cout << "NUMBERS:\n"<< endl;
    cout << "int1 = " << int1 << ", int2 = " << int2 << ", int3 = " << int3 << endl;
    // cout<< "float1 = " << float1 << ", float2 = " << float2 << ", float3 = " << float3 <<endl;
    max(int1, int2, int3);
    return 0;
}