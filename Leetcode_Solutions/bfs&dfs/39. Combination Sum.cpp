class Solution
{
public:
    void combinationSum_helpher(vector<int> &candidates, vector<int> &temp, vector<vector<int>> &ans, int target, int pos)
    {
        for (int i = pos; i < candidates.size(); i++)
        {
            int num = candidates[i];
            if (target - num == 0)
            {
                temp.push_back(num);
                ans.push_back(temp);
                temp.pop_back();
            }
            else if (target - num < 0)
            {
                break;
            }
            else
            {
                temp.push_back(num);
                if (target - num == 7)
                {
                    cout << temp[0];
                }
                combinationSum_helpher(candidates, temp, ans, target - num, i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        combinationSum_helpher(candidates, temp, ans, target, 0);
        return ans;
    }
};