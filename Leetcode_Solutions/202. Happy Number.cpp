class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> invalid;
        while (n != 1){
            int temp = 0;
            if (invalid.find(n) != invalid.end()){
                return false;
            }
            invalid.insert(n);
            while (n > 0){
                temp += (n % 10) * (n % 10);
                n = n/10;
            }
            n = temp; 
        }
        return true;
    }
};