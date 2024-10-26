#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> symbols = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string result = "";

        for (int i = 0; i < values.size() && num > 0; i++)
        {
            while (num >= values[i])
            {
                result += symbols[i];
                num -= values[i];
            }
        }

        return result;
    }
};
/*
int main()
{
    Solution sol;
    cout << sol.intToRoman(3749) << endl; // Output: "MMMDCCXLIX"
    cout << sol.intToRoman(58) << endl;   // Output: "LVIII"
    cout << sol.intToRoman(1994) << endl; // Output: "MCMXCIV"
    return 0;
}
*/
