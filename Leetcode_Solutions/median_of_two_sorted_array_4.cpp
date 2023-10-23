class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lo = 0;
        int num1len = nums1.size();
        int num2len = nums2.size();
        int hi = num1len - 1;
        int medianpos = (num1len + num2len + 1)/2;
        if (num1len > num2len){
            return findMedianSortedArrays(nums2, nums1);
        }
        while (lo <= hi){
            int mid = lo + (hi-lo)/2;
            if (nums1[mid] < nums2[medianpos - mid -1]){
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }
        int m1 = lo;
        int m2 = medianpos - lo;
        int c1 = max(m1 <= 0? INT_MIN : nums1[m1-1], m2 <= 0? INT_MIN : nums2[m2-1]);

        if ((num1len+num2len) % 2 ==1){
            return c1;
        }
        int c2 = min(m1 >= num1len ? INT_MAX : nums1[m1], m2>=num2len? INT_MAX : nums2[m2]);
        return (c1+c2) * 0.5;

    }
};