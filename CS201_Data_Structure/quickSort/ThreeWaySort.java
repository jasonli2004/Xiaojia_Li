public class ThreeWaySort {
   public static <T extends Comparable<T>> void sort(T[] list){
      StdRandom.shuffle(list);
      show(list);
      sort(list, 0, list.length - 1);
   }
   private static <T extends Comparable<T>> void sort(T[] list, int lo, int hi){
      if (hi <= lo){return;}
      int lt = lo; // less than list[i]
      int i = lo + 1; //pointer
      int gt = hi; // larger than list[i]
      T a = list[lo]; // a is the partition element to compare to 
      while (i <= gt){
         int cmp = list[i].compareTo(a);
         if (cmp > 0){
            exchange(list, i, gt--);
          //  show(list);
          //  System.out.println(lt + " " + gt + " " + i);
         }
         else if (cmp < 0){
            exchange(list, lt++, i++);
           // show(list);
           // System.out.println(lt + " " + gt + " " + i);

         }
         else{
            i++;
            //System.out.println(lt + " " + gt + " " + i);
         }
      }
      sort(list, lo,lt - 1);
      sort(list, gt + 1, hi);
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


   public static void main(String args[]){
      //Integer[] list = { 27, 82, 41, 124, 62, 31, 94, 47, 142, 71, 214 };
      Integer[] list = {1,2,3,4,5,6,7,8};
      sort(list);
      System.out.println(isSorted(list));
      show(list);
   }
}
