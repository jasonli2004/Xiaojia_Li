import java.util.HashSet;

public class TwoSum {

	public static int countSlow(int[] a) {
		
		int count = 0;

		for (int i = 0; i < a.length; i++) {
			for (int j = i+1; j < a.length; j++) {
				if (a[i] + a[j] == 0)
					count += 1;
			}
		}
		
		return count;
	}
	
	public static int countFast(int[] a) {
		int cnt = 0;
		HashSet<Integer> numSet = new HashSet<Integer>();
		for (int i : a){
			if (numSet.contains(-i)){
				cnt++;
			}
			else{
			numSet.add(i);
			}
		}
		return cnt;
	}
}
