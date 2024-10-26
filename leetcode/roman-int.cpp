#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        unordered_map<char, int> romanValues = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

        int total = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int value = romanValues[s[i]];
            // Check if the next character has a larger value
            if (i + 1 < s.size() && romanValues[s[i]] < romanValues[s[i + 1]])
            {
                total -= value;
            }
            else
            {
                total += value;
            }
        }

        return total;
    }
};
/*
int main()
{
    Solution sol;
    cout << sol.romanToInt("III") << endl;     // Output: 3
    cout << sol.romanToInt("LVIII") << endl;   // Output: 58
    cout << sol.romanToInt("MCMXCIV") << endl; // Output: 1994
    return 0;
}
*/
