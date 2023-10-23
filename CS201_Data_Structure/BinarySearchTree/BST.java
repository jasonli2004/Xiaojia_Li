public class BST<T extends Comparable<T>> implements Set<T>{
   private class Node{
      T key;
      Node left = null;
      Node right = null;
      boolean isRed = true;
      Node(T key){
         this.key = key;
      }
   }
   private Node root;
   private int numElement;
   private int level = 0;

   private Node add(Node subtreeNode, T value) {
      if (subtreeNode == null){
         Node n = new Node(value);

         numElement++;
         return n;
      }      
      int cmp = value.compareTo(subtreeNode.key);
      if (cmp > 0){subtreeNode.right = add(subtreeNode.right, value);}
      if (cmp < 0){subtreeNode.left = add(subtreeNode.left, value);}
      return subtreeNode;

   }

   private boolean contains(Node subtreeNode,T value) {
      if (subtreeNode == null){
         return false;
      }
      int cmp = value.compareTo(subtreeNode.key);
      if (cmp > 0){contains(subtreeNode.right, value);}
      if (cmp < 0){contains(subtreeNode.left, value);}
      return true;
   }
  
   @Override
   public boolean contains(T value) {
      return contains(root, value);
   }
   @Override
   public int countRange(T lo, T hi) {
      // TODO Auto-generated method stub
      return 0;
   }
   @Override
   public int size() {
      return numElement;
   }
   @Override
   public boolean isEmpty() {
      return numElement == 0;
   }



   @Override
   public void add(T value) {
      if (root == null){
         root = new Node(value);
         numElement++;
         return;
      }
      add(root, value);
   }

   private void show(Node subtreeNode, int num, T[] list){
      if (subtreeNode == null){
         return;
      }
      list[num] = subtreeNode.key;
      show(subtreeNode.left,num*2,list);
      show(subtreeNode.right,num*2 + 1,list);
      int temp = (int) (Math.log(num)/Math.log(2));
      if (temp > level){
         level = temp;
      }
      
   }

   public void show(Node subtreeNode){
      T[] list = (T[]) new Comparable[1000];
      show(subtreeNode,1,list);
      String s = "";
      int j = 0;
      int k = 1;
      int currentlevel = 0;
      for (int f = 0; f < (int) Math.pow(2,level)/2- Math.pow(2,currentlevel); f++){
         s = s + "      ";
      }
      s = s + "   ";
   for (int i = 1; i <= Math.pow(2,level+1) - 1; i++){

      /*for (int i = 0; i<=20; i++){
         if (list[i] == null){
            System.out.print("nu ");
         }
         else{
            System.out.print(list[i] + " ");
         }
      } */

      if (list[i]!=null){
         s = s + i +"[" + list[i]+"] ";
      }
      else{
         s = s + i+"["+ "nu"+"] ";
      }
         j = j + 1;
         if (j == k){
            j = 0;
            currentlevel++;
            k = k * 2;
            s = s + "\n";
            for (int f = 0; f < (int) Math.pow(2,level)/2 - Math.pow(2,currentlevel)/2; f++){
               s = s + "      ";
            }
         }
      }
      System.out.print(s);
      System.out.println("level = "+(level+1));

   }

   

   //search the subtree identified with the given root.

   public static void main(String[] args){
      BST<Integer> s = new BST<Integer>();
      //System.out.println(s.isEmpty());
      /*s.add(11);
     // System.out.println(s.isEmpty());
      s.add(13);
      //s.add(72);
      s.add(23);
      s.add(18);
      s.add(14);
      s.add(28);
      s.add(1);
      s.add(12);*/
      Integer[] lee = {44,74,81,84,25,53,82,23,80,35,11,22,33,44,55,66,77,88};
      for (int i = 0; i < lee.length; i++){
         s.add(lee[i]);
      }

  //    System.out.println(s.size());
    //  System.out.println(s.root.key);
      s.show(s.root);
      
   }
  
}