class Solution {
public:
    int digitsum(int n){
        int sum  = 0;
        while (n > 0){
            sum += (n%10) * (n%10);
            n = n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int fast = n;
        int slow = n;
        slow = digitsum(slow);
        fast = digitsum(fast);
        fast = digitsum(fast);
        if (slow == 1 || fast == 1){
            return true;
        }
        while (slow != fast){
            slow = digitsum(slow);
            fast = digitsum(fast);
            fast = digitsum(fast);
            if (fast == 1){
                return true;
            }
        }
        return false;
    }
};