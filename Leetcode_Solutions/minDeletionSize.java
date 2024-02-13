class Solution {
    public int minDeletionSize(String[] strs) {
        int cnt = 0;
        int len = strs.length;
        int len1 = strs[0].length();
        for (int i = 0; i < len1; i++){
            char prev = strs[0].charAt(cnt);
            for (int j = 0; j <len ; j++){
                if (strs[j].charAt(cnt) < prev){
                    for (int k = 0; k < len; k++){
                        strs[k] = removeCharAt(strs[k], cnt);
                    }
                    cnt--;
                    break;
                }
                prev = strs[j].charAt(cnt);
            }
            cnt++;
        }
        return len1 -cnt;
    }
    private static String removeCharAt(String s, int pos) {
        return s.substring(0, pos) + s.substring(pos + 1);
     }
}