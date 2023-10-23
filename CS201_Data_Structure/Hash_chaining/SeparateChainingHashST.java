public class SeparateChainingHashST<Key,Value> {
   private int m;
   private SequentialSearchST<Key,Value>[] st;
   public SeparateChainingHashST(int m){
      this.m = m;
      st = (SequentialSearchST<Key,Value>[]) new SequentialSearchST[m];
      for(int i = 0; i < m; i++){
         st[i] = new SequentialSearchST();
      }   
   }
   private int hash(Key key){
      return (int) key % m;
      //return (Math.abs(key.hashCode())) % m;//& 0x7fffffff
   }
   public Value get(Key key){
      return (Value) st[hash(key)].get(key);
   }
   public void put (Key key, Value value){
      st[hash(key)].put(key, value);
   }
   public String toString(){
      String s = "";
      for (int i = 0; i < m; i++) {
          s = s + i + ") " + st[i].toString() + "\n"; 
      }
      return s;
   }
   //public Iterable<Key> keys(){}

public static void main(String args[]){
   SeparateChainingHashST<Integer, Integer> list = new SeparateChainingHashST<Integer,Integer>(11);
   Integer[] lee = {44,74,81,84,25,53,82,23,80,35,16,92,39,71,59,60};
   for (int i: lee){
      list.put(i,i);
   }
   System.out.println(list.toString());

   //String f = "SSSSSSSSSSSSSSSSSSSSSSSSSSSs";
   //System.out.println(f.hashCode());
}
}