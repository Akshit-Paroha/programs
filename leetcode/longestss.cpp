#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.size(); ++end)
        {
            char currentChar = s[end];

            if (charIndex.count(currentChar) && charIndex[currentChar] >= start)
            {
                start = charIndex[currentChar] + 1;
            }

            charIndex[currentChar] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};
/*
int main()
{
    Solution solution;

    // Test case 1
    string s1 = "abcabcbb";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s1) << endl; // Expected: 3

    // Test case 2
    string s2 = "bbbbb";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s2) << endl; // Expected: 1

    // Test case 3
    string s3 = "pwwkew";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << solution.lengthOfLongestSubstring(s3) << endl; // Expected: 3

    return 0;
}
*/
