public class DoublingTest{
   public static double timeTrial(int n){
      int MAX = 1000000;
      int[] a  = new int[n];
      for (int i = 0; i < n; i++){
         a[i] = StdRandom.uniform(-MAX, MAX);
      }
      Stopwatch timer = new Stopwatch();
      int count  = ThreeSum.count(a);
      return timer.elapsedTime();
   }
   public static void main(String[] args){
      for (int i =0; i <3; i++){
      int n = 16000;
     // for (double n = 250; n <= 250*1028*4; n*=2){
         double time = timeTrial((int)n);
         System.out.println((int)n+" "+time);
     }
      //}
   } 


}