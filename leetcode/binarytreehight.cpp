#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    unordered_map<int, int> nodeHeight;

    int calculateHeight(TreeNode *node)
    {
        if (!node)
            return -1;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        int height = 1 + max(leftHeight, rightHeight);
        nodeHeight[node->val] = height;
        return height;
    }

    int getUpdatedHeight(TreeNode *node, int excludeVal)
    {
        if (!node || node->val == excludeVal)
            return -1;
        int leftHeight = getUpdatedHeight(node->left, excludeVal);
        int rightHeight = getUpdatedHeight(node->right, excludeVal);
        return 1 + max(leftHeight, rightHeight);
    }

public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries)
    {
        calculateHeight(root); // Precompute height of each node
        vector<int> result;

        for (int val : queries)
        {
            result.push_back(getUpdatedHeight(root, val));
        }

        return result;
    }
};
