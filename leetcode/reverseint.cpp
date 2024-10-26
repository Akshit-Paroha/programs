#include <iostream>
#include <climits>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long reversed = 0;
        while (x != 0)
        {
            int temp = x % 10;
            x /= 10;

            if (reversed > (INT_MAX / 10) || (reversed == (INT_MAX / 10) && digit > 7))
            {
                return 0;
            }
            if (reversed < (INT_MIN / 10) || (reversed == (INT_MIN / 10) && digit < -8))
            {
                return 0;
            }
            reversed = reversed * 10 + temp;
            /*
            if (x > INT_MAX|| x <INT_MIN)
            {
                return 0;
            }
            */
        }
        return static_cast<int>(reversed);
    }
};
/*
int main()
{
    Solution sol;
    int x = 123;
    cout << sol.reverse(x) << endl; // Output: 321
    x = -123;
    cout << sol.reverse(x) << endl; // Output: -321
    x = 120;
    cout << sol.reverse(x) << endl; // Output: 21
    return 0;
}
*/