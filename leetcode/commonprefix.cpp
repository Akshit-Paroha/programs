#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        // Start with the first string as the initial prefix
        string prefix = strs[0];

        // Check each string in the array
        for (int i = 1; i < strs.size(); i++)
        {
            // Shrink the prefix until it matches the start of the current string
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.size() - 1);
                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};

/*
int main()
{
    Solution sol;
    vector<string> strs1 = {"flower", "flow", "flight"};
    cout << sol.longestCommonPrefix(strs1) << endl; // Output: "fl"

    vector<string> strs2 = {"dog", "racecar", "car"};
    cout << sol.longestCommonPrefix(strs2) << endl; // Output: ""

    return 0;
}
*/
