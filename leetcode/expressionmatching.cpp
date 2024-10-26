#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        // Base case: empty pattern matches empty string
        dp[0][0] = true;

        // Initialize for patterns like "a*", "a*b*", "a*b*c*"
        for (int j = 2; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2];
            }
        }

        // Fill the DP table
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    // '*' matches zero occurrences
                    dp[i][j] = dp[i][j - 2];

                    // '*' matches one or more occurrences
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1])
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
/*
int main()
{
    Solution sol;
    cout << sol.isMatch("aa", "a") << endl;  // Output: false
    cout << sol.isMatch("aa", "a*") << endl; // Output: true
    cout << sol.isMatch("ab", ".*") << endl; // Output: true
    return 0;
}
* /
