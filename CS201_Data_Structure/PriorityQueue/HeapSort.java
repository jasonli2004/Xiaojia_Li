public class HeapSort {
   public static <T extends Comparable<T>> void sort(T[] list){
      int n = list.length;
      for (int k = n/2; k >=1; k--){
         sink(list, k, n);
      }
      while (n > 1){
         exch(list, 1, n);
         sink(list, 1, n);
      }
      
   }
   private static <T extends Comparable<T>> void sink(T[] list, int k, int n){
      while (2 * k <= n){
         int j = 2 * k;
         if (j < n && less(list[j],list[j+1])){
            j++;
         }
         if (!less(list[k],list[j])){
            break;
         }
         exch(list, k, j);
         k = j;
      }
   }
   private static <T extends Comparable<T>> boolean less(T a, T b){
      return a.compareTo(b) < 0;
   }
   public static <T> void exch(T[] list, int a, int b){
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


   public static void main(String args[]){
      //Integer[] list = { 27, 82, 41, 124, 62, 31, 94, 47, 142, 71, 214 };
      Integer[] list = {1,2,3,4,5,6,7,8};
      sort(list);
      System.out.println(isSorted(list));
      show(list);
   }

}

