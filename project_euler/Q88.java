import java.util.ArrayList;
import java.util.Arrays;


public class Q88 {

	public static void main(String args[]) {
		long start = System.currentTimeMillis();
		int[] minsum = new int[12001];
		Arrays.fill(minsum, 0);
		for(int i = 2; i < 15; i++)
			update(i, minsum);
		ArrayList<Integer> resultlist = new ArrayList<Integer>();
		int totalsum = 0;
		for(int i = 0; i < minsum.length; i++) {
			if (!resultlist.contains(minsum[i])) {
				resultlist.add(minsum[i]);
				totalsum += minsum[i];
			}
		}
		long end = System.currentTimeMillis();
		System.out.println(totalsum);
		System.out.println(end - start + "ms");
	}
	
	public static ArrayList<Integer> sieve(int number){
		boolean[] ticks = new boolean[number];
		Arrays.fill(ticks, true);
		ticks[0] = false;
		for(int i = 1; i < number; i++){
			if(ticks[i]){
				int gap = i + 1;
				for(int j = i+gap; j< number; j+=gap)
					ticks[j] = false;
			}
		}
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for(int i = 0; i < number; i++){
			if(ticks[i])
				primes.add(i+1);
		}
		return primes;
	}
	
	public static void update(int number, int[] minarray) {
		int[] nolist = new int[number];
		Arrays.fill(nolist, 2);
		double root = 1/((double) number);
		double maxvalue = Math.pow(24000, root);
		while(nolist[0] <= maxvalue) {
			int product = product(nolist);
			int sum = sum(nolist);
			int productsum = product - sum + number;
			if(productsum < minarray.length) {
				if (minarray[productsum] == 0 || minarray[productsum] > product)
					minarray[productsum] = product;
			}
			nolist = next(nolist);
		}
	}
	
	public static int[] next(int[] currentarray) {
		int[] tobereturned = currentarray.clone();
		for(int i = currentarray.length - 1; i >= 0; i--) {
			int nextdigit = currentarray[i] + 1;
			for(int j = i; j < currentarray.length; j++)
				tobereturned[j] = nextdigit;
			if (product(tobereturned) <= 240000)
				break;
		}
		return tobereturned;
	}
	
	public static int product(int[] array) {
		int result = 1;
		for(int i = 0; i < array.length; i++) 
			result = result * array[i];
		return result;
	}
	
	public static int sum(int[] array) {
		int result = 0;
		for(int i = 0; i < array.length; i++)
			result += array[i];
		return result;
	}
	
}
