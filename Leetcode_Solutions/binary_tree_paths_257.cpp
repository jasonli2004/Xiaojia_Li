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
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> path;
        string curpath = "";
        dfs(root, path, curpath);
        return path;
    }
    void dfs(TreeNode* root, vector<string>& path, string& curpath){
        if (root == nullptr){
            return;
        }
        int len = curpath.size();
        curpath +=  ("->" + to_string(root->val));
        if (root->left == nullptr && root->right == nullptr){
            path.push_back(curpath.substr(2, curpath.size()-2));
        } else {
            dfs(root->left, path, curpath);
            dfs(root->right, path, curpath);
        }
        curpath.erase(len);  // Rollback to the previous state.
    }
};
