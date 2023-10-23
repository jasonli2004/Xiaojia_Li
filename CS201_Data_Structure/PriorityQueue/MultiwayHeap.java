public class MultiwayHeap<Key extends Comparable<Key>>
{
   private Key[] pq;
   private int n = 0;
   private int multi = 0;
   public MultiwayHeap(int maxNum, int multi){
      pq = (Key[]) new Comparable[maxNum+1];
      this.multi = multi;
   }
   private boolean less(int i, int j){
      return pq[i].compareTo(pq[j]) < 0;
   }
   
   public boolean isEmpty(){
      return n == 0;
   }
   public int size(){
      return n;
   }
   public void insert(Key v){
      pq[++n] = v;
      swim(n);
   }
   public Key delMax(){
      Key max  = pq[1];
      exch(1,n--);
      sink(1);
      return max;
   }
   public Key max(){
      return pq[1];
   }

   private void exch(int i, int j){
      Key temp = pq[i];
      pq[i] = pq[j];
      pq[j] = temp;
   }
   private void swim(int k){
      while (k > 1 && less((k+(multi/2))/multi, k)){
         //System.out.println((k+(multi/2))/multi);
         exch(k,(k+(multi/2))/multi);
         k = (k+(multi/2))/multi;
      }
   }

   private void sink(int k){
      while (multi * k <= n){
         int j = multi * k - multi/2;
         int origin = j;
         for (int l = 1; l < multi; l++){
         if (j < n && less(j,origin+l)){
            j = origin + l;
         }
         }
         //System.out.println((!less(k,j)));
         if (!less(k,j)){
            break;
         }
         exch(k, j);
         k = j;
     
      }
   }
   public String toString(){
      String s = "";
      int j = 0;
      int k = 1;
      int levels = (int) Math.pow(this.n,0.5);
      for (int i = 1; i <=n; i++){
         s = s + i+"( " + pq[i]+" ";
         j = j + 1;
         if (j == k){
            j = 0;
            k = k * multi;
            s = s + "\n";
         }
      }
      return s;
   }
   public static void main(String[] args) {
      MultiwayHeap<Integer> pr = new MultiwayHeap<Integer>(170,3);
     // System.out.println(pr.isEmpty());
      pr.insert(22);
    //  System.out.println(pr.size());
      pr.insert(33);
      pr.insert(11);
      pr.insert(23);
      pr.insert(55);
      pr.insert(4);
      pr.insert(129);
      pr.insert(100);
      pr.insert(33);
      pr.insert(11);
      pr.insert(23);
      pr.insert(55);
      pr.insert(4);
      pr.insert(129);
      pr.insert(100);
      pr.insert(33);
      pr.insert(11);
      pr.insert(23);
      pr.insert(55);
      pr.insert(4);
      pr.insert(129);
      pr.insert(100);
      pr.insert(128);
      pr.insert(127);
  //    System.out.println(pr.delMax());
    //  System.out.println(pr.delMax());
      //System.out.println(pr.delMax());
     // System.out.println(pr.delMax());
      System.out.println(pr.delMax());

    //  pr.insert(55);
//      System.out.println(pr.delMax());
     // System.out.println(pr.size());
      System.out.println(pr.toString());
   }
}



