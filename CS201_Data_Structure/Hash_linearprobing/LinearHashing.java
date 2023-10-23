public class LinearHashing<Key, Value>{
  
   double alpha = 0.75;
   int m = 0;
   //int[] prime = {2,5,11,23,43};
   Key[] keyList;
   Value[] valueList;
   public int num = 0;
   @SuppressWarnings("unchecked")
   public LinearHashing(int m){
      this.m = m;
      this.keyList =(Key[]) new Object[m];
      this.valueList = (Value[]) new Object[m];
   }
   public void add(Key key, Value value){
      int idx = Math.abs(key.hashCode()) % m;
      int current = idx;
      while (current != m && keyList[current] != null){
         if (keyList[current].equals(key)){
            valueList[current] = value;
            return;
         }
         current++;
      }
      if (current == m){
         resize(2*m);
         add(key, value);
         return;
      }
      keyList[current] = key;
      valueList[current] = value;
      num++;
      if (((double)num/(double)m)>alpha){
         resize(2*m);
      }
      return;
   }

   public Value get(Key key){
      int idx = key.hashCode() % m;
      int current = idx;
      while (current != m && keyList[current] != null){
         if (keyList[current].equals(key)){
            return valueList[current];
         }
         current++;
      }
      return null;
   }
   public boolean contains(Key key){
      return get(key) != null;
   }
   public void resize(int cap){
      LinearHashing<Key,Value> t = new LinearHashing<Key,Value>(cap);
      for (int i = 0; i < m; i++){
         if (keyList[i] != null){
            t.add(keyList[i],valueList[i]);
         }
      }
      this.keyList = t.keyList;
      this.valueList = t.valueList;
      this.m = t.m;
   }

   public static void main(String args[]){
      LinearHashing<String, Integer> list = new LinearHashing<String, Integer>(3);
      list.add("s",9);
      list.add("d",10);
      list.add("a",1);
      list.add("ppdaf",5);
      System.out.println(list.contains("ppdaf"));
      list.add("s",20);
      list.add("s",21);
      list.add("0",22);
      list.add("sdsklf",23);
      list.add("seoirueao",30);
      list.add("serious?",29);
      list.add("f",1);
      list.add("sick",3);
      //list.resize(100);
      System.out.println(list.num);
      System.out.println(list.get("serious?"));
      System.out.println(list.contains("serious?"));
      
   }



}