
public class Sort {

	private static <T extends Comparable<T>> boolean less(T a, T b) {
		return a.compareTo(b) < 0;
	}

	private static <T extends Comparable<T>> int partition(T[] a, int lo, int hi) {
		// Adapted from Sedgewick and Wayne to use the half-open
		// range a[lo,hi) rather than a closed range.
		int i = lo, j = hi;
		T p = a[lo];
		while (true)
		{
			// Replacing less() with a direct call to compareTo actually slowed
			// down the code.  TODO: figure out why!
			// Important note: we also stop when we find something
			// equal to p; otherwise, we get N^2 behavior with
			// arrays containing all the same value.
			while (less(a[++i], p)) if (i == hi-1) break;
			while (less(p, a[--j])) if (j == lo) break;
			if (i >= j) break;

			// Moving swap() in-line doesn't make this any faster.
			ArrayUtils.swap(a, i, j);
		}
		ArrayUtils.swap(a, lo, j);
		return j;
	}

	private static <T extends Comparable<T>> void quicksort(T[] a, int lo, int hi) {
		if ((hi - lo) <= 1) {
			return;
		}
		int j = partition(a, lo, hi);
		quicksort(a, lo, j);
		quicksort(a, j+1, hi);
	}

	public static <T extends Comparable<T>> void quicksort(T[] a) {
		RandomUtils.shuffle(a);
		quicksort(a, 0, a.length);
	}
}
