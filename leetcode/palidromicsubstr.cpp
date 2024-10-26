#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int start = 0, maxLength = 1;

        for (int i = 0; i < s.length(); i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if (right - left + 1 > maxLength)
                {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right])
            {
                if (right - left + 1 > maxLength)
                {
                    start = left;
                    maxLength = right - left + 1;
                }
                left--;
                right++;
            }
        }

        return s.substr(start, maxLength);
    }
};

/*
int main()
{
    Solution solution;

    string s = "babad";
    string result = solution.longestPalindrome(s);

    cout << "The longest palindromic substring is: " << result << endl;

    return 0;
}
* /
