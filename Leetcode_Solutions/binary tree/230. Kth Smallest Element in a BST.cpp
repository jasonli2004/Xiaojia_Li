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
    pair<int, bool> get_target_or_index(TreeNode* root, int k, int cur) {
        if (root == nullptr){
            return make_pair(cur, false);
        }
        auto it = get_target_or_index(root->left, k, cur);
        if (it.second){
            return make_pair(it.first, true);
        }
        if (it.first + 1 == k){
            return make_pair(root->val, true);
        }
        return get_target_or_index(root->right, k, it.first+1);
    }
    int kthSmallest(TreeNode* root, int k) {
        return get_target_or_index(root, k, 0).first;
    }
};
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
    pair<int, bool> get_target_or_index(TreeNode* root, int k, int cur) {
        if (root == nullptr) {
            return make_pair(cur, false);
        }

        auto left = get_target_or_index(root->left, k, cur);
        if (left.second) {
            // Found in left subtree
            return left;
        }

        int current_index = left.first + 1;
        if (current_index == k) {
            // Found the target at the current node
            return make_pair(root->val, true);
        }

        // Continue searching in right subtree
        return get_target_or_index(root->right, k, current_index);
    }

    int kthSmallest(TreeNode* root, int k) {
        return get_target_or_index(root, k, 0).first;
    }
};
