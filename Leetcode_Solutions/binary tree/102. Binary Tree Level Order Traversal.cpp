
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        while (!q.empty()){
            vector<int> temp;
            int s =  q.size();
            for (int i = 0; i < s; i++){
                TreeNode* cur = q.front();
                temp.push_back(cur->val);
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
                q.pop();
            }
            ans.push_back(temp);
        }
        return ans;
    }
};