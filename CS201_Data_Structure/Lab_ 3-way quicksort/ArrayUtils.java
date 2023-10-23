
public class ArrayUtils {

	public static <T> void swap(T[] a, int idx1, int idx2) {
		T t = a[idx1];
		a[idx1] = a[idx2];
		a[idx2] = t;
	}

	public static <T> void copy(T[] aFrom, T[] aTo, int lo, int hi) {
		for (int i = lo; i < hi; i++)
			aTo[i] = aFrom[i];
	}

	public static <T> void copy(T[] aFrom, int loFrom, int hiFrom, T[] aTo, int loTo) {
		for (int iFrom = loFrom, iTo = loTo; iFrom < hiFrom; iFrom++, iTo++) {
			aTo[iTo] = aFrom[iFrom];
		}
	}

	public static <T> void rotateRight(T[] a, int lo, int hi) {
		if (hi - lo < 2) return;
		T t = a[hi - 1];
		for (int i = hi - 1; i > lo; i--) {
			a[i] = a[i - 1];
		}
		a[lo] = t;
	}

	public static <T> void rotateLeft(T[] a, int lo, int hi) {
		if (hi - lo < 2) return;
		T t = a[lo];
		for (int i = lo+1; i < hi; i++)
			a[i-1] = a[i];
		a[hi-1] = t;
	}

	public static <T extends Comparable<T>> boolean isOrdered(T[] a) {
		for (int i = 1; i < a.length; i++) {
			if (a[i - 1].compareTo(a[i]) > 0)
				return false;
		}
		return true;
	}

	public static <T extends Comparable<T>> int lowerBound(T[] a, T value) {
		return lowerBound(a, 0, a.length, value);
	}

	public static <T extends Comparable<T>> int lowerBound(T[] a, int lo, int hi, T value) {
		// In all invariants, lo' and hi' are the original values
		// of lo and hi.
		// Note that due to the invariant that mid is in [lo,hi),
		// we will never get lo > hi.
		while (lo < hi) {
			// for all j in [lo',lo) a[mid] < value
			// for all j in [hi,hi') a[mid] >= value
			int mid = lo + (hi - lo) / 2;
			// mid in [lo,hi)
			if (a[mid].compareTo(value) < 0)
				lo = mid + 1;
				// for all j in [lo',lo) a[mid] < value
				// NOTE: mid + 1 is important to guarantee termination!
			else
				hi = mid;
				// for all j in [hi,hi') a[mid] >= value
		}
		// for all j in [lo',hi) a[mid] < value
		// for all j in [hi,hi') a[mid] >= value
		return hi;
	}

	public static <T extends Comparable<T>> int upperBound(T[] a, T value) {
		return upperBound(a, 0, a.length, value);
	}

	public static <T extends Comparable<T>> int upperBound(T[] a, int lo, int hi, T value) {
		// In all invariants, lo' and hi' are the original values
		// of lo and hi.
		// Note that due to the invariant that mid is in [lo,hi),
		// we will never get lo > hi.
		while (lo < hi) {
			// In all invariants, lo' and hi' are the original values
			// of lo and hi.
			// for all j in [lo',lo) a[mid] <= value
			// for all j in [hi,hi') a[mid] > value
			int mid = lo + (hi - lo) / 2;
			// mid in [lo,hi)
			if (a[mid].compareTo(value) <= 0)
				lo = mid + 1;
				// for all j in [lo',lo) a[mid] <= value
			else
				hi = mid;
				// for all j in [hi,hi') a[mid] > value
		}
		// for all j in [lo',hi) a[mid] <= value
		// for all j in [hi,hi') a[mid] > value
		return hi;
	}
}
