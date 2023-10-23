import java.util.*;
class Solution {
   public int myAtoi(String s) {
   int sum = 0;
   int cnt = 0;
   boolean positive = true;
   int temp = 0;
   boolean start = false;
   Stack<Integer> st = new Stack<Integer>();
   for (int i = 0; i < s.length(); i++){
      char current = s.charAt(i);
      temp = (int) current;
      if (start && !(temp >= 48 && temp <= 57) ){
         break;
      }
      if (current == '-' || current =='+' || (temp >= 48 && temp <= 57)){
         start = true;
      }
      else{
         if (current != ' '){
            break;
         }
      }
      if ( temp >= 48 && temp <= 57){
          if (temp == 48 && st.empty()){}
          else{
         st.push((Integer) (temp - 48));
         cnt ++;
          }
      }
      if (current == '-' && st.empty() == true){
         positive = false;
      }
   }
   int mult = 1;
   while (!st.empty()){
      temp = st.pop();
      if ((long)((long)2147483647 - (long)((long)temp*(long)mult)) < (long)sum || cnt >= 11){
         if (positive){
            return 2147483647;
         }
         else{
            return -2147483648;
         }
      }
      else{
         sum = sum + temp * mult;
         mult = mult * 10;
      }
   }
   if (!positive){
      sum = 0 - sum;
   }
    return sum ;
   }
}