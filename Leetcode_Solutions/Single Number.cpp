// #include <iostream>
// #include <unordered_set>
// using namespace std;
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_set<int> set;
//         for (int i = 0; i < nums.size(); i++){
//             if (set.find(nums[i]) == set.end()){
//                 set.insert(nums[i]);
//             }
//             else {
//                 set.erase(nums[i]);
//             }
//         }
//         return *(set.begin());
//     }
// };
    
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++){
//             if (i % 2){
//                 sum = sum - nums[i];
//             }
//             else{
//                 sum = sum + nums[i];
//             }
//         }
//         return sum;
//     }
// };

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < nums.size()-1; i = i + 2){
//             if (nums[i] != nums[i + 1]){
//                 return nums[i];
//             }
//         }
//         return nums[nums.size()-1];
//     }
// };
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i : nums){
            ans ^= i;
        }
        return ans;
    }
};