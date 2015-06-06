import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;


public class Q75 {

	public static void main(String[] args) {
//		This method is correct but takes too long to run.
//		int count = 0;
//		for(int i = 2; i <= 1500000; i++){
//			if(check(i) != 0){
//				count++;
//				System.out.print(i);
//				System.out.println(" " + check(i));
//			}
//		}
//		System.out.println(count);
//	}
//	
//	public static double check(int number){
//		int half = number/2 - 1;
//		BigInteger numberinb = new BigInteger(Integer.toString(number));
//		BigInteger subtract = numberinb.pow(2).multiply(new BigInteger("2"));
//		int count = 0;
//		double resulthalf = 0;
//		while(half > 0){
//			BigInteger currenttest = new BigInteger(Integer.toString(half));
//			BigInteger result = currenttest.add(numberinb).pow(2).subtract(subtract);
//			if(result.compareTo(BigInteger.ZERO) == -1)
//				break;
//			else{
//				if(checksqr(result)){
//					count++;
//					resulthalf = half;
//				}
//			}
//			if(count > 1)
//				break;
//			half--;
//		}
//		if (count != 1)
//			resulthalf = 0;
//		return resulthalf;
//	}
//	
//	public static boolean checksqr(BigInteger number){
//		double numberint = Double.parseDouble(number.toString());
//		double sqrt = Math.sqrt(numberint);
//		return ((int) sqrt == sqrt);
		
/*	Check out wikipedia page : http://en.wikipedia.org/wiki/Pythagorean_triple
 * 	It could be seen that every integer pythagorean triple could be expressed as:
 * 	a = k(m^2+n^2) b = k(2mn) c = k(m^2-n^2)
 * 	Using this property, this problem could be solved at a much faster rate.
 */
	
//	sum = 2km(m+n)  halfsum = km(m+n) max m = 865
		
		int[] tally = new int[750000];
		for(int i = 1; i <= 865; i++){
			ArrayList<Integer> nvalues = findcoprime(i);
			for(int one : nvalues){
				int result = i*(i+one);
				int count = 750000/result;
				for(int j = 1; j <= count; j++)
					tally[result*j-1]++;
			}
		}
		int result = 0;
		for(int i = 0; i < tally.length; i++){
			if(tally[i] == 1)
				result++;
		}
		System.out.println(result);
		
	}
	
	public static ArrayList<Integer> findcoprime(int number){
		ArrayList<Integer> primefactor = finddivisor(number);
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int i = number-1; i > 0; i-=2){
			boolean status = true;
			for(int one : primefactor){
				if(i % one  == 0){
					status = false;
					break;
				}
			}
			if(status)
				result.add(i);
		}
		return result;
	}
	
	public static ArrayList<Integer> finddivisor(int test){
		int number = (int) Math.sqrt(test);
		ArrayList<Integer> primelist = sieve(number);
		ArrayList<Integer> result = new ArrayList<Integer>();
		if(primelist.size() == 0){
			if (test != 1)
				result.add(test);
			return result;
		}
		else{
			for(int one : primelist){
				if(test % one == 0){
					while(test % one == 0)
						test = test / one;
					result.add(one);
				}
			}
			if(result.size() == 0)
				result.add(test);
			else
				result.addAll(finddivisor(test));
			return result;
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
