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
    void traverse(TreeNode* root, queue<int>& q){
        if (root == nullptr){
            return;
        }
        if (root->left == nullptr && root->right == nullptr){
            q.push(root->val);
            return;
        }
        traverse(root->left,q);
        traverse(root->right,q);
        return;
    }
    bool traverse_check(TreeNode* root, queue<int>& q){
        if (root == nullptr){
            return true;
        }
        if (root->left == nullptr && root->right == nullptr){
            if (root->val == q.front()){
                q.pop();
                return true;
            }
            return false;
        }
        return traverse_check(root->left,q) && traverse_check(root->right,q);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        queue<int> q1;
        traverse(root1, q1);
        return traverse_check(root2,q1) && q1.empty();
    }
  
};