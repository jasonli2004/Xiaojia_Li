
import java.util.Random;

// RandomUtils - based on Sedgewick and Wayne's StdRandom class

public class RandomUtils {

	static Random rand = new Random();

	static void setSeed(long seed) {
		rand.setSeed(seed);
	}

	// Returns a value in the half-open [lo,hi).
	static int uniform(int lo, int hi) {
		return lo + (int)(rand.nextDouble() * (hi - lo));
	}
	
	static int uniform(int n) {
		return uniform(0, n);
	}

	static boolean bernoulli(double p) {
		return rand.nextDouble() < p;
	}
	
	// Adapted from Sedgewick and Wayne's _Algorithms 4th Edition_, page 32.
	static <T> void shuffle(T[] a) {
		int n = a.length;
		for (int i = 0; i < n; i++) {
			int r = i + uniform(n-i);
			T t = a[i];
			a[i] = a[r];
			a[r] = t;
		}
	}
}
