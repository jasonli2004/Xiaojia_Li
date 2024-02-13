class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        int l,r;
        for (int i = 0; i < len; i++){
            int new_target = target - numbers[i];
            l = i + 1;  
            r = len;
            while (l < r){
                int mid = l + (r - l) / 2;
                if (numbers[mid] == new_target){
                    return {i+1, mid + 1};
                }
                else if (numbers[mid] > new_target){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
        }
        return {-1,-1};
    }
};