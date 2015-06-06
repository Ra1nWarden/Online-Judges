import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;


public class Q108 {
	
	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		ArrayList<Integer> primes = sieve(100);
		BigInteger start = new BigInteger("5");
		while(true) {
			BigInteger squared = start.pow(2);
			Map<BigInteger, Integer> factorlist = new TreeMap<BigInteger, Integer>(); 
			for(int i = 0; i < primes.size(); i++) {
				BigInteger prime = new BigInteger(Integer.toString(primes.get(i)));
				if(prime.compareTo(start) <= 0) {
					if(squared.mod(prime) == BigInteger.ZERO) {
						int factorcount = 0;
						while(squared.mod(prime) == BigInteger.ZERO) {
							squared = squared.divide(prime);
							factorcount++;
						}
						factorlist.put(prime, factorcount);
					}
				}
				else
					break;
			}
			int totalpairs = 1;
			for(int one : factorlist.values())
				totalpairs *= (one+1);
			if(totalpairs >= 1999) {
				long endTime = System.currentTimeMillis();
				System.out.println(start);
				System.out.println(endTime - startTime);
				System.exit(0);
			}
			start = start.add(BigInteger.ONE);
		}

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

}
