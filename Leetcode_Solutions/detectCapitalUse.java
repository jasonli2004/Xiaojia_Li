class Solution {
    public boolean detectCapitalUse(String word) {
        if ( word.length() == 1 ){
            return true;
        }
        boolean FirstC = false;
        if ( (int) word.charAt(0) >= 65 && (int) word.charAt(0) <= 90){
            FirstC = true;
        }
        if ( (int) word.charAt(1) >= 65 && (int) word.charAt(1) <= 90){
            if (FirstC){
                FirstC = true;
            }
            else{
                return false;
            }
        }
        else{
            if (FirstC){
                FirstC = false;
            }
        }
        if (FirstC){
            for (int i = 2; i < word.length(); i++){
                if ( (int) word.charAt(i) < 65 || num > (int) word.charAt(i)){
                    return false;
                }
            }
        }
        else{
            for (int i = 2; i < word.length(); i++){
                if ( (int) word.charAt(i) >= 65 && (int) word.charAt(i) <= 90){
                    return false;
                }
            }
        }
        return true;
    }
}