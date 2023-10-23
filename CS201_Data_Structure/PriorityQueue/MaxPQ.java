private class MaxPQ<Key extends Comparable<Key>>
{
   private Key[] pq;
   private int n = 0;
   public MaxPQ(int maxNum){
      pq = (Key[]) new Comparable[maxNum+1];
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
      while (k > 1 && less(k/2, k)){
         exch(k,k/2);
         k = k/2;
      }
   }

   private void sink(int k){
      while (2 * k <= n){
         int j = 2 * k;
         if (j < n && less(j,j+1)){
            j++;
         }
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
            k = k * 2;
            s = s + "\n";
         }
      }
      return s;
   }
   public String listing(){
      String s = "";
      for (int i = 1; i <= n; i++){
         s = s + pq[i] + " ";
      }
      return s;
   }
   public static void main(String[] args) {
    /* MaxPQ<Integer> pr = new MaxPQ<Integer>(170);
     // System.out.println(pr.isEmpty());
      pr.insert(44);
      pr.insert(74);
      pr.insert(81);
      pr.insert(84);

      pr.insert(25);
      pr.insert(53);
      pr.insert(82);
      pr.insert(23);

      pr.delMax();
      pr.delMax();

      pr.insert(80);
      pr.insert(35);
      pr.insert(16);
      
      pr.delMax();
      pr.delMax();*/
//      System.out.println(pr.delMax());
     // System.out.println(pr.size());
     MaxPQ<String> pr = new MaxPQ<String>(170);
     pr.insert("P");
     pr.insert("R");
     pr.insert("E");
     pr.insert("F");
     pr.insert("C");
     pr.insert("T");
     pr.insert("S");
     System.out.println(pr.delMax());

      System.out.println(pr);
      System.out.println(pr.listing());

    
   }
}



