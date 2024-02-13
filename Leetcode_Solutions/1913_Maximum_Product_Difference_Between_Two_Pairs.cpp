class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max_1 = -1;
        int max_2 = -2;
        int min_2 = 10001;
        int min_1 = 10001;
        for (int i : nums){
            if (i > max_2){
                if (i >= max_1){
                    max_2 = max_1;
                    max_1 = i;
                }
                else if(i < max_1){
                    max_2 = i;
                }
                else{

                }
            }
            if (i < min_2){
                if (i <= min_1){
                    min_2 = min_1;
                    min_1 = i;
                }
                else if(i > min_1){
                    min_2 = i;
                }
            }
        }
        return max_1*max_2 - min_1*min_2;
    }
};