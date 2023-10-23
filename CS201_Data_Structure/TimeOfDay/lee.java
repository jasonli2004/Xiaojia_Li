import java.util.Arrays;

public class lee {
   public static int midterm(int[] a, int[] b){
      Integer[] aCopy = new Integer[a.length];
      for (int i = 0; i< a.length; i++){
         aCopy[i] = a[i];
      }
      Arrays.sort(a);
      int count = 0;
      for (int i = 0; i < b.length; i++){
         int idx = BinarySearch.lowerBound(a, 0, a.length, b[i]);
         if (idx != aCopy.length && aCopy[idx] == b[i]){
            count ++;
        }
      }
      return count;
   }   
   public static void main(String[] args){
      int[] a = {3,2,1,6,5};
      Arrays.sort(a);
      for (int i = 0; i<a.length; i++){
         System.out.println(a[i]);
      }
      
   }
}
