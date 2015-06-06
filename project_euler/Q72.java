import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;


public class Q72 {


	public static void main(String[] args) {
		BigInteger count = BigInteger.ZERO;
		for(int i = 2; i <= 1000000; i++)
			count = count.add(new BigInteger(Integer.toString(findtotal(i))));
		System.out.println(count);
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

	public static int findtotal(int number){
		int result = number;
		ArrayList<Integer> primefactor = finddivisor(number);
		for(int one : primefactor){
			result /= one;
			result *= (one-1);
		}
		return result;
	}

}
