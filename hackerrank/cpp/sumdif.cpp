#include <iostream>
using namespace std;

void update(int *a, int *b)
{
    int sum = *a + *b;
    int diff = *a > *b ? *a - *b : *b - *a;
    *a = sum;
    *b = diff;
}

int main()
{
    int a, b;
    cin>>a;
    cin>>b;
    update(&a, &b);
    cout<<a<<endl<<b<<endl;
    return 0;
}