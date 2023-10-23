public class OrderedMap<Kt extends Comparable<Kt>, Vt> implements Map<Kt,Vt>
{
   int max;
   int num;
   Kt[] keySet;
   Vt[] valueSet;
   OrderedMap(int maxSize)
   {
      keySet = (Kt[])new Comparable[maxSize];
      valueSet = (Vt[])new Object[maxSize];
      this.max = maxSize;
      this.num = 0;
   };
   @Override
   public void put(Kt key, Vt value) 
   {
      int idx = 0;
      idx = BinarySearch.lowerBound(keySet, 0, num, key);
      if (idx == num || !keySet[idx].equals(key))
      {
         keySet[num] = key;
         valueSet[num++] = value;
         ArrayUtils.rotateRight(keySet, idx, num);
         ArrayUtils.rotateRight(valueSet, idx, num);
      }
      else
      {
         valueSet[idx] = value;
      }
   }

   @Override
   public Vt get(Kt key) 
   {
      int idx = BinarySearch.lowerBound(keySet, 0, num, key);
      if (idx == num || !keySet[idx].equals(key))
      {
         return null;
      }
      return valueSet[idx];
   }

   @Override
   public boolean contains(Kt key) 
   {
      return BinarySearch.exists(keySet,0,num, key);
   }

   @Override
   public Kt maxKey() 
   {
      return keySet[num - 1];
   }

   @Override
   public Kt minKey() 
   {
      return keySet[0];
   }

   @Override
   public int size() 
   {
      return num;
   }

   @Override
   public boolean isEmpty() 
   {
      if (num == 0)
      {
         return true;
      }
      return false;
   }
   
   public String toString()
   {
      String s = "[";
      for (int i = 0; i < num; i++)
      {
         s = s + " (" + keySet[i] + " " + valueSet[i] + ")";
      }
      s = s + " ]";
      return s;
   }
}
