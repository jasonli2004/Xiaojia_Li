
public class Sort3Way {
   private static <T extends Comparable<T>> void quickSort3Way(T[] list, int lo, int hi){
      if (hi - 1 <= lo){return;}
      int lt = lo; // less than list[i]
      int i = lo + 1; //pointer
      int gt = hi - 1; // larger than list[i]
      T a = list[lo]; // a is the partition element to compare to 
      while (i <= gt){
         int cmp = list[i].compareTo(a);
         if (cmp > 0){
            exchange(list, i, gt--);
         }
         else if (cmp < 0){
            exchange(list, lt++, i++);
         }
         else{
            i++;
         }
      }
      quickSort3Way(list, lo,lt);
      quickSort3Way(list, gt + 1, hi);
   }
   private static <T extends Comparable<T>> boolean less(T a, T b){
      return a.compareTo(b) < 0;
   }
   public static <T> void exchange(T[] list, int a, int b){
      T temp = list[a];
      list[a] = list[b];
      list[b] =  temp;
   }

	public static <T extends Comparable<T>> void quickSort3Way(T[] a) {
		RandomUtils.shuffle(a);
		quickSort3Way(a, 0, a.length);
	}
}
