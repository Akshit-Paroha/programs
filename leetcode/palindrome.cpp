#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // Step 1: Handle negative numbers and numbers ending with 0 (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int reversed_half = 0;
        // Step 2: Reverse half of the number
        while (x > reversed_half)
        {
            reversed_half = reversed_half * 10 + x % 10;
            x /= 10;
        }

        // Step 3: Check if original half matches reversed half
        return x == reversed_half || x == reversed_half / 10;
    }
};

/*
int main()
{
    Solution sol;
    cout << sol.isPalindrome(121) << endl;  // Output: true
    cout << sol.isPalindrome(-121) << endl; // Output: false
    cout << sol.isPalindrome(10) << endl;   // Output: false
    return 0;
}
* /
