#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end());
        vector<string> result;
        string last = "";

        for (const string &f : folder)
        {
            if (last == "" || f.find(last + "/") != 0)
            {
                result.push_back(f);
                last = f;
            }
        }

        return result;
    }
};

/*
int main()
{
    vector<string> folder = {"/a/b/c", "/a/b/ca", "/a/b/d"};
    vector<string> result = Solution().removeSubfolders(folder);

    for (const string &f : result)
    {
        cout << f << endl;
    }

    return 0;
}
* /
