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
    int find_incomplete(TreeNode* root){
        int cnt = 0;
        while (root != nullptr){
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    int find_left(TreeNode* root){
        int cnt = 0;
        while (root != nullptr){
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    bool node_exist(int num, int total, int level,TreeNode* root){
        int sum = 0;
        int cur_level = 0;
        while (num >= sum){
            if (num < sum + total/2){
                root = root->left;
            }
            else{
                root = root->right;
                sum = sum + total/2;
            }
            total = total / 2;
            cur_level++;
            if (level == cur_level){
                return root != nullptr;
            }
        }
        return true;
    }

    int countNodes(TreeNode* root) {
        int level = find_incomplete(root);
        int level_2 = find_left(root);
        int total = pow(2,level);
        if (level == level_2){
            return total -1;
        }
        int l = 0;
        int r = total;
        if (root == nullptr){
            return 0;
        }
        while (l < r){
            int mid = l + (r - l) / 2;
            if (node_exist(mid, total,level, root)){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l + total - 1; 
    }
};