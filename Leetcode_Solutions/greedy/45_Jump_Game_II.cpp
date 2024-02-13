//version 1
class Solution {
public:
    int jump(vector<int>& nums) {
        int target = nums.size() - 1;
        int cnt = 0;
        while (target != 0){
            for (int i = 0; i < target; i++){
                if (i + nums[i] >= target){
                    target = i;
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};

//version 2 O(n) Greedy

class Solution {
public:
    int jump(vector<int>& nums) {
        int last = 0, cover = 0, cnt = 0;
        for (int i = 0; i < nums.size() - 1; i++){
            cover = max(cover, i + nums[i]);
            if (i == last){
                cnt++;
                last = cover;
            }
        }
        return cnt;
    }
};