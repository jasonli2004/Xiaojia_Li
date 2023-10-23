public class QuickSort { //quicksort algorithm && find nth element with quicksort
   
   public static <T extends Comparable<T>> void sort(T[] list){
      //StdRandom.shuffle(list);
      show(list);
      sort(list, 0, list.length - 1);
   }
   private static <T extends Comparable<T>> void sort(T[] list, int lo, int hi){
      if (hi <= lo) return;
      int j = partition(list, lo, hi);
      sort(list, lo, j - 1);
      sort(list, j + 1, hi);
   }
   private static <T extends Comparable<T>> int partition(T[]list, int lo, int hi){
      int i = lo;
      int j = hi+1 ;
      T v = list[lo];
      int cnt = 0;
      System.out.println("partition: "+v);
      while (true){
         cnt++;
         while(less(v, list[--j])){
            cnt ++;
            if (j == lo){
               break;
            }
         }
         if (lo+1 == j ){
            break;
         }
         cnt++;
         while (less(list[++i],v)){
            cnt++;
            if (i == hi){
               break;
            }
         }
         if (i >= j) {
            break;
         }
         //this if statement would reduce one comparison
         if (i == j - 1){
            exchange(list, i, j);
            show(list);
            j = i;
            break;
         }
         exchange(list, i, j);
         show(list);
      }
      exchange(list,lo,j);
      show(list);
      System.out.println("cnt is "+cnt);
      return j;
   }
   private static <T extends Comparable<T>> boolean less(T a, T b){
      return a.compareTo(b) < 0;
   }

   public static <T> void exchange(T[] list, int a, int b){
      T temp = list[a];
      list[a] = list[b];
      list[b] =  temp;
   }

   private static <T> void show(T[] list){
      for (int i = 0; i < list.length; i++){
         System.out.print(list[i]+" ");
      }
      System.out.println();
   }

   public static <T extends Comparable<T>> boolean isSorted(T[] list){
      for (int i = 1; i < list.length; i++){
         if (less(list[i],list[i-1])){
            return false;
         }
      }
      return true;
   }
   public static <T extends Comparable<T>> T nthElement(T[] list, int k){
      StdRandom.shuffle(list);
      return nthElement(list, 0, list.length, k);
   }
   public static <T extends Comparable<T>> T nthElement(T[] list, int lo, int hi, int k){
      int j = -1;
      while (j!=k){
         j = partition(list, lo, hi - 1);
         if (j < k){
            lo = j + 1;
         }
         if (j > k){
            hi = j;
         }
      }
      return list[j];
   }

   public static void main(String args[]){
      //Integer[] list = { 27, 82, 115, 41, 1,2,3, 222,916,0,34, 124, 94, 62, 31, 94, 47, 142, 71, 214, 27 };
      Integer[] list = {1,1,1,1,1};
      sort(list);
      System.out.println(isSorted(list));
      //Integer[] list = {79,86,38,47,98,99,70,63,10,80,25,92,43,16,69,51};
      //Integer[] lee = {44,74,81,84,25,53,82,23,80,35,16,92,39,71,59,60};
      //sort(lee);


   }
}
