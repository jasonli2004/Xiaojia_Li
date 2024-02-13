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
    int rangeSumBST(TreeNode* root, int low, int high) {
        int num = root->val;
        if (root->left == nullptr && root->right == nullptr){
            if (num >= low && num <= high){
                return num;
            }
            else{
                return 0;
            }
        }
        if (num >= low && num <= high){
            int left = 0;
            int right = 0;
            if (root->left != nullptr){
                left = rangeSumBST(root->left, low, high);
            }
            if (root->right != nullptr){
                right = rangeSumBST(root->right, low, high);
            }
            return num + left + right;
        }
        else if (num < low){
            if (root->right == nullptr){
                return 0;
            }
            return rangeSumBST(root->right, low, high);
        }
        else{
            if (root->left ==nullptr){
                return 0;
            }
            else{
                return rangeSumBST(root->left, low, high);
            }
        }
        return 0;
    }
};