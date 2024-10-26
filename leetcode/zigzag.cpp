#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.length())
            return s;

        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[curRow] += c;
            if (curRow == 0)
                goingDown = true;
            else if (curRow == numRows - 1)
                goingDown = false;

            curRow += goingDown ? 1 : -1;
        }

        string result;
        for (const string &row : rows)
        {
            result += row;
        }

        return result;
    }
};

/*
int main()
{
    Solution solution;

    string s = "PAYPALISHIRING";
    int numRows = 3;
    string result = solution.convert(s, numRows);

    cout << "Converted string: " << result << endl;

    return 0;
}
* /
