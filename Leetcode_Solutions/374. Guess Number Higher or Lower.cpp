/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long hi = n;
        long long lo = 0;
        while (1){
            long long mid = (hi+lo)/2;
            int result = guess(mid);
            if (result == 0){
                return mid;
            }
            else if (result == -1){
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return 0;
    }
};