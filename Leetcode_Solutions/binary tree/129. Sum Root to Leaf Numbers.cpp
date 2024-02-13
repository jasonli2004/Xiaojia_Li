/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, "");
    }

    int dfs(TreeNode *root, string num)
    {
        string s = num + to_string(root->val);
        if (root->left == nullptr && root->right == nullptr)
        {
            return stoi(s);
        }
        if (root->left == nullptr)
        {
            return dfs(root->right, s);
        }
        if (root->right == nullptr)
        {
            return dfs(root->left, s);
        }
        return dfs(root->left, s) + dfs(root->right, s);
    }
};