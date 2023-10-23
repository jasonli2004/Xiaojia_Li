class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int plant = 0;
        if (flowerbed.size() == 1){
            if (flowerbed[0] == 1){
                return n == 0;
            }
            else{
                return 1 >= n;
            }
        }
 
        if (flowerbed[0] == 0 && flowerbed[1] == 0){
            plant++;
            flowerbed[0] = 1; 
        }
        for (int i = 1; i < flowerbed.size()-1; i++){
            if (flowerbed[i] == 1){
                continue;
            }
            else if (flowerbed[i-1] == 1){
                flowerbed[i] = -1;
            }
            else {
                if (flowerbed[i+1] == 0){
                plant++;
                flowerbed[i] = 1;
                }
            }
        }
        if (flowerbed[flowerbed.size()-1] == 0 && flowerbed[flowerbed.size()-2] == -1){
            plant++;
        }
        return plant >= n;
    }
};