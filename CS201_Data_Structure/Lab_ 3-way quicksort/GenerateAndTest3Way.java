
public class GenerateAndTest3Way {
	private static <T extends Comparable<T>> boolean isSorted(T[] a, int lo, int hi) {
		for (int i = lo + 1; i < hi; i++)
			if (a[i - 1].compareTo(a[i]) > 0)
				return false;
		return true;
	}

	private static <T extends Comparable<T>> boolean isSorted(T[] a) {
		return isSorted(a, 0, a.length);
	}

	private static void timeQuicksort(int[] a, int n, int m) {
		Integer[] aInt = new Integer[n];
		for (int i = 0; i < n; i++)
			aInt[i] = a[i];
		Timer sw = new Timer();
		Sort.quicksort(aInt);
		double elapsed = sw.elapsed();
		System.out.printf("Quicksort     : %d, %d, %7.3f\n", n, m, elapsed);
	}

	private static void timeQuicksort3Way(int[] a, int n, int m) {
		Integer[] aInt = new Integer[n];
		for (int i = 0; i < n; i++)
			aInt[i] = a[i];
		Timer sw = new Timer();
		Sort3Way.quickSort3Way(aInt);
		if (!isSorted(aInt))
			System.out.println("Sort failure!\n");
		double elapsed = sw.elapsed();
		System.out.printf("Quicksort3way : %d, %d, %7.3f\n", n, m, elapsed);
	}
	
	public static void main(String[] args) {
		
		//if (args.length != 2) {
			//System.out.println("usage: java GenerateAndTest3Way size numUnique");
			//return;
		//}
	
		// Get n and m from the command line, and allocate the array.
		//int n = Integer.parseInt(args[0]);
	//	int m = Integer.parseInt(args[1]);
	for (int j  = 0; j < 3; j++){
	int n = 4000000;
	int m = 1024; //4, 8, 16, 32, 64, 128, 256, 512, 1024 
		int[] a = new int[n];
		
		// Generate a random array.  Note that we set a seed so that
		// we get predictable values each time.
		RandomUtils.setSeed(0);
		for (int i = 0; i < n; i++)
			a[i] = RandomUtils.uniform(0, m);
		// Test the sorts.
		
		timeQuicksort(a, n, m);
		timeQuicksort3Way(a, n, m);
	
		System.out.println("Done");
	}
}
}
