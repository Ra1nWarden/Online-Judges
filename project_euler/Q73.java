import java.util.ArrayList;
import java.util.Arrays;


public class Q73 {

	public static void main(String[] args) {
		int result = 0;
		for(int i = 3; i <= 12000; i++)
			result += countfrac(i);
		System.out.println(result);
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
	
	public static int countfrac(int number){
		int start = (number/3) + 1;
		int end = number/2;
		int count = 0;
		ArrayList<Integer> primelist = finddivisor(number);
		for(int i = start; i <= end; i++){
			boolean status = true;
			for(int one : primelist){
				if(i % one == 0){
					status = false;
					break;
				}
			}
			if(status)
				count++;
		}
		return count;
	}

}
