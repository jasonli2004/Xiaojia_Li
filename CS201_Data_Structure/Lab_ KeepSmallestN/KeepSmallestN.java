import java.util.Scanner;

public class KeepSmallestN {

	public static void main(String[] args) {
		int nToKeep = Integer.parseInt(args[0]);
		MaxPQ<Integer> list = new HeapMaxPQ(nToKeep);
		Scanner sc = new Scanner(System.in);
		
		int temp = 0;
		int n = 0;

		while (sc.hasNextInt()){
			temp = sc.nextInt();
			list.insert(temp);
		   n++;
			if (n>nToKeep){
				list.delMax();
			}
		}
		if (n < nToKeep){
			nToKeep = n;
		}
		for (int i = 0; i < nToKeep ; i++){
			System.out.println(list.delMax());
		}

		sc.close();
	}
}
