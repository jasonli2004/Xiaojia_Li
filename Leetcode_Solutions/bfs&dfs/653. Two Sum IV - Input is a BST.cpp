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
    bool find_helper(TreeNode* root, TreeNode* cur, int k){
        TreeNode* temp = root;
        if (cur == nullptr){
            return false;
        }
        int cur_val = cur->val;
        while (temp != nullptr){
            if (k -  temp->val == cur_val && temp != cur){
                return true;
            }
            else if(k - temp->val > cur_val){
                temp = temp->right;
            }   
            else if (k - temp->val < cur_val){
                temp = temp->left;
            }
            else{
                break;
            }
        }
        return find_helper(root, cur->left, k) || find_helper(root, cur->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return find_helper(root, root, k);
    }
};