// version1
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> cnt;
        map<int, int> dp;
        int cur_max = 0;
        int prev_max = 0;
        for (int num : nums)
        {
            cnt[num]++;
        }
        for (auto it : cnt)
        {
            int number = it.first;
            int count = it.second;
            int dp1;
            int dp2;
            if (dp.find(number - 2) == dp.end())
            {
                if (dp.find(number - 1) == dp.end())
                {
                    dp1 = cur_max + number * count;
                }
                else
                {
                    dp1 = prev_max + number * count;
                }
            }
            else
            {
                dp1 = dp[number - 2] + number * count;
            }
            if (dp.find(number - 1) == dp.end())
            {
                dp2 = cur_max;
            }
            else
            {
                dp2 = dp[number - 1];
            }
            prev_max = cur_max;
            cur_max = max(dp1, dp2);
            dp[number] = cur_max;
        }
        return cur_max;
    }
};

// version2

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> cnt(maxNum + 1, 0);
        vector<int> dp(maxNum + 1, 0);
        int cur_max = 0;
        int prev_max = 0;
        for (int num : nums)
        {
            cnt[num]++;
        }
        dp[1] = cnt[1];
        for (int i = 2; i <= maxNum; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
        }
        return dp[maxNum];
    }
};