#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfSteps(int num)
    {
        int steps = 0;
        while (num > 0)
        {
            if (num % 2 == 0)
            {
                num /= 2;
            }
            else
            {
                num -= 1;
            }
            steps++;
        }
        return steps;
    }
};

/*
int main()
{
    Solution solution;
    int num = 14; // Change this value to test different inputs
    int result = solution.numberOfSteps(num);
    cout << "Number of steps to reduce " << num << " to zero: " << result << endl;
    return 0;
}
* /
