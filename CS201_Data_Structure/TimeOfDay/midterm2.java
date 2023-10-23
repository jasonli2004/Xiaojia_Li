import java.util.Arrays;

public class midterm2 {
   public static int midterm(int[] a, int[] b){
      Integer[] aCopy = new Integer[a.length];
      for (int i = 0; i< a.length; i++){
         aCopy[i] = a[i];
      }
      Arrays.sort(a);
      int count = 0;
      for (int i = 0; i < b.length; i++){
         int idx = BinarySearch.lowerBound(aCopy, 0, aCopy.length, b[i]);
         if (idx != aCopy.length && aCopy[idx] == b[i]){
            count ++;
        }
      }
      return count;
   }   
}
