class Solution {
    public List<String> letterCombinations(String digits) {
        String[] l = new String[270];
        if (digits.charAt(0) == '2'){
             l = new String[] {"a","b","c"};
        }
        if (digits.charAt(0) == '3'){
            l = new String[] {"d","e","f"};
        }
        if (digits.charAt(0) == '4'){
            l = new String[] {"g","h","i"};
        }
        if (digits.charAt(0) == '5'){
            l = new String[] {"j","k","l"};
        }
        if (digits.charAt(0) == '6'){
           l = new String[] {"m","n","o"};
        }
        if (digits.charAt(0) == '7'){
             l = new String[] {"p","q","r","s"};
        }
        if (digits.charAt(0) == '8'){
             l =new String[]  {"t","u","v"};
        }
        if (digits.charAt(0) == '9'){
            l = new String[] {"w","x","y","z"};
        }
        for (int i = 1; i < digits.length();i++){
            String s = new String();
            if (digits.charAt(i) == '2'){
                 s =  "abc";
            }
            if (digits.charAt(i) == '3'){
                 s = "def";
            }
            if (digits.charAt(i) == '4'){
                 s = "ghi";
            }
            if (digits.charAt(i) == '5'){
                 s = "jkl";
            }
            if (digits.charAt(i) == '6'){
               s = "mno";
            }
            if (digits.charAt(i) == '7'){
                 s = "pqrs";
            }
            if (digits.charAt(i) == '8'){
                 s = "tuv";
            }
            if (digits.charAt(i) == '9'){
                s = "wxyz";
            }
            l = combine(s,l);
        }
        int cnt = 0;
        List<String> list = new ArrayList<String>();
        while(l[cnt]!= null){
            list.add(l[cnt]);
            cnt++;
        }
    }
    private String[] combine(String s, String[] l1){
        int cnt1 = 0;
        int cnt2 = 0;
        String[] l2 = new String[270];
        for(int i = 0; i <= s.length(); i++){
            cnt1 = 0;
            String current = String.valueOf( s.charAt(i));
            while(l1[cnt1]!= null){
                l2[cnt2] = l1[cnt1] + current;
                cnt1++;
                cnt2++;
            }
        }
        return l2;
    }
}