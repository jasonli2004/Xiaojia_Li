class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> buckets;
        vector<pair<int, int>> sorted;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++){
            buckets[nums[i]]++;
        }
        for (auto i:buckets){
            sorted.push_back(make_pair(i.second, i.first));
        }
        sort(sorted.begin(), sorted.end(),greater<>());
        for (int i = 0; i < k; i++){
            result.push_back(sorted[i].second);
        }
        return result;
    }
};