class Solution {
public:

    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int l = 0;
        int r = height.size() - 1;
        int cur_max = (r-l) * min(height[l], height[r]);
        while (l < r - 1){
            if (height[l] <= height[r]){
                l++;
            }
            else{
                r--;
            }
            cur_max = max(cur_max, (r-l) * min(height[l], height[r]));
        }
        return cur_max;
    }
};