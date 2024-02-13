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
    int bfs(TreeNode* root, int time){
        if (root == nullptr || root->val == -1){
            return time;
        }
        root->val = -1;
        return max(bfs(root->left, time+1),bfs(root->right, time+1));
    }
    bool dfs(TreeNode* root, int target, stack<TreeNode*>& path){
        if (root == nullptr){
            return false;
        }
        if (root->val == target){
            path.push(root);
            return true;
        }
        path.push(root);
        if (dfs(root->left, target, path) || dfs(root->right, target, path)){
            return true;
        }
        path.pop();
        return false;
    }
    int amountOfTime(TreeNode* root, int start) {
        stack<TreeNode*> path;
        dfs(root, start, path);
        int cnt = -1;
        int cur_max = 0;
        while (!path.empty()){
            int temp = bfs(path.top(), cnt);
            cur_max = max(cur_max, temp);
            path.pop();
            cnt++;
        }
        return cur_max;
    }
};