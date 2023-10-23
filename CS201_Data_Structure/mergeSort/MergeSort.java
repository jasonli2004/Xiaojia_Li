public class MergeSort {
   private static <T extends Comparable<T>> boolean less(T a, T b){
      return a.compareTo(b) < 0;
   }
   public static <T extends Comparable<T>> void sort(T[] list){
      T[] aux  = (T[]) new Comparable[list.length];
      sort(list, aux, 0, list.length - 1);
   }
   private static <T extends Comparable<T>> void sort(T[] list,T[] aux, int lo, int hi){
      if (hi <= lo){
         return;
      }
      int mid = lo + (hi-lo)/2;
      sort(list, aux, lo, mid);
      sort(list, aux, mid + 1, hi);
      if (list[mid].compareTo(list[mid+1]) < 0){return;}
      merge(list, aux, lo, mid, hi);
      System.out.println((lo+1) + " " + (hi+1));
      show(list);

   }

   public static <T extends Comparable<T>> void busort(T[] list){ //bottom-up sort
      T[] aux = (T[]) new Comparable[list.length];
      int n = list.length;
      for (int len = 1; len < n; len = len * 2){
         for (int lo = 0; lo < n - len; lo = lo + 2 * len){
            merge(list, aux, lo, lo + len - 1, Math.min(lo+len+len-1, n -1));
            show(list);
         }
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

   public static <T extends Comparable<T>>void merge(T[] list,T[] aux,int lo, int mid, int hi){
      int i = lo;
      int j = mid + 1;
      for (int k = lo; k <= hi; k++){
         aux[k] = list[k];
      }
      for (int k = lo; k <= hi; k++){
         if (i > mid){
            list[k] = aux[j++];
         }
         else if(j > hi){
            list[k] = aux[i++];
         }
         else if (less(aux[j],aux[i])){
            list[k] = aux[j++];
         }
         else{
            list[k] = aux[i++];
         }
      }
   }

   public static void main(String args[]){
      Integer[] list = { 27, 82, 41, 124, 62, 31, 94, 47 };
     // Integer[] list = {1,2,3,4,5,6,7,8};
      sort(list);
      System.out.println(isSorted(list));
      show(list);
   }
}
