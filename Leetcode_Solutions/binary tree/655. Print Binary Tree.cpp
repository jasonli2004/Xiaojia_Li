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
    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<int>> matrix;
        queue<TreeNode*> que;
        que.push(root);
        TreeNode* nextLevel = root->left;
        bool all_empty = false;
        int cnt = 0;

        while (!all_empty){
            vector<int> row;
            all_empty = true;
            for (int i = que.size(); i >= 1; i--){
                TreeNode* temp = que.front();
                if (temp == nullptr){
                    que.push(nullptr);
                    que.push(nullptr);
                    row.push_back(-100);
                    que.pop();
                    continue;
                }
                row.push_back(temp->val);
                if (temp->left != nullptr || temp->right != nullptr){
                    all_empty = false;
                }
                que.push(temp->left);
                que.push(temp->right);
                que.pop();
            }
            matrix.push_back(row);
            cnt++;
        }    
        int total = pow(2, cnt) - 1;
        vector<vector<string>> ans(cnt, vector<string>(total, ""));
        int start = 0;
        int middle = 1;
        for (int i = cnt - 1; i >= 0; i--){
            vector<string> level;
            for(int j = 0; j < matrix[i].size(); j++){
                if (matrix[i][j] != -100){
                    ans[i][start+(middle+1) * j] = to_string(matrix[i][j]);
                }
            }
            start = start * 2 + 1;
            middle = middle * 2 + 1;
        }
        return ans;
    }
};