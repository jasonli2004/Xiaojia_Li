public interface Map<Kt, Vt> {
   void put(Kt key, Vt value);
   Vt get(Kt key);
   boolean contains(Kt key);
   Kt maxKey();
   Kt minKey();
   int size();
   boolean isEmpty();
}
