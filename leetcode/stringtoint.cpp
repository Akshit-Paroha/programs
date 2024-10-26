#include <iostream>
#include <string>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, sign = 1, result = 0;

        // Step 1: Ignore leading whitespace
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }

        // Step 2: Determine the sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Read the digits and convert
        while (i < s.size() && isdigit(s[i]))
        {
            int digit = s[i] - '0'; // Convert char to int

            // Step 4: Check for overflow and underflow
            if (result > (INT_MAX - digit) / 10)
            {
                return sign == 1 ? INT_MAX : INT_MIN; // Return bounds if overflow
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result; // Return the final result
    }
};

/*
int main()
{
    Solution sol;
    cout << sol.myAtoi("42") << endl;            // Output: 42
    cout << sol.myAtoi("   -042") << endl;       // Output: -42
    cout << sol.myAtoi("1337c0d3") << endl;      // Output: 1337
    cout << sol.myAtoi("0-1") << endl;           // Output: 0
    cout << sol.myAtoi("words and 987") << endl; // Output: 0
    return 0;
}
* /
