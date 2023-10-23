class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0;
        int r = nums.size() - 1;
        k = nums.size() - k ;
        while (l <= r){
            int pivotpos = quickselect(nums, l, r);
            // for (int i = 0; i < nums.size(); i++){
            //     cout << "," << nums[i];
            // }
            // cout << endl;
            if (pivotpos == k){
                return nums[pivotpos];
            }
            else if (pivotpos > k){
                r = pivotpos - 1;
            }
            else{
                l = pivotpos + 1;
            }
        }
        return nums[l];
    }
    int quickselect(vector<int>& nums, int l, int r){
        int pivot = nums[l];
        int lo = l + 1;
        int hi = r;
        while (lo <= hi){
            while (lo <= r && nums[lo] <= pivot){
                lo++;
            }
            while (hi > l && nums[hi] >= pivot){
                hi--;
            }
            if (lo < hi){
                swap(nums[lo], nums[hi]);
            }
        }
        swap(nums[hi], nums[l]);
        return hi;
    }
};