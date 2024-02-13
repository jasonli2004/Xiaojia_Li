class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> l = new ArrayList<String>();
        if (n == 0){
            return l;
        }
        l.add("()");
        for (int i = 1; i < n; i++){
            l = combine(l);
        }
        return l;
    }
    private List<String> combine(List<String> s){
        List<String> l = new ArrayList<String>();
        for (int i = 0; i < s.size(); i++){
            if (("()"+s.get(i)).equals(s.get(i)+"()")){
                l.add("()"+s.get(i));
            }
            else{
                l.add("()"+s.get(i));
                l.add(s.get(i)+"()");
            }
            l.add("("+s.get(i)+")");
        }
    }
}