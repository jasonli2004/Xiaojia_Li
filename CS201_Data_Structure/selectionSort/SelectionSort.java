public class SelectionSort {
   private static <T extends Comparable<T>> boolean less(T a, T b){
      return a.compareTo(b) < 0;
   }
   public static <T extends Comparable<T>> void sort(T[] list){
      int n = list.length;
      for (int i = 0 ; i < n; i++){
         int min = i;
         for (int j = i + 1; j < n; j++){
            if (less(list[j],list[min])){
               min = j;
            }
         }
         exchange(list, i, min);
         show(list);
         //show(list);
      }

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

   public static void main(String args[]){
      Integer[] list = { 27, 82, 41, 124, 62, 31, 94, 47, 142, 71, 214 };
      sort(list);
      System.out.println(isSorted(list));
      show(list);
   }
}
