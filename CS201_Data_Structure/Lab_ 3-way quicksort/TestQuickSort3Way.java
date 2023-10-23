
public class TestQuickSort3Way {

	public static void generate(Integer[] a, int m) {
		for (int i = 0, j = 0; i < a.length; i++, j = (j+1) % m) {
			a[i] = j;
		}
		RandomUtils.shuffle(a);
	}

	private static <T> void printArray(T[] a) {
		for (int i = 0; i < a.length; i++)
			System.out.print(a[i] + " ");
		System.out.println();
	}

	public static void main(String[] args) {
		final int n = 36;
		
		Integer[] a = new Integer[n];
		for (int m = n; m > 0; m /= 2) {
			generate(a, m);
			Sort3Way.quickSort3Way(a);
			printArray(a);
		}
	}
}
