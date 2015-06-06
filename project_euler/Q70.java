import java.util.ArrayList;
import java.util.Arrays;


public class Q70 {
	//This code takes a long period of time.
	
	public static void main(String[] args) {
		int number = 0;
		double minresult = 10;
		for(int i = 1; i <= 10000000; i++){
			int currentcount = findtotal(i);
			if(compare(i, currentcount)){
				System.out.println(i);
				System.out.println(currentcount);
				double currentresult = ((double) i) / currentcount;
				if(currentresult < minresult){
					minresult = currentresult;
					number = i;
				}
			}
		}
		System.out.println(number);
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

	public static boolean compare(int number1, int number2){
		String first = Integer.toString(number1);
		String second = Integer.toString(number2);
		if(first.length() != second.length())
			return false;
		else{
			boolean status = true;
			boolean[] checklist = new boolean[second.length()];
			Arrays.fill(checklist, true);
			for(int i = 0; i < first.length(); i++){
				char current = first.charAt(i);
				boolean found = false;
				for(int j = 0; j < second.length(); j++){
					if(checklist[j]){
						if(second.charAt(j) == current){
							checklist[j] = false;
							found = true;
							break;
						}
					}
				}
				if(!found){
					status = false;
					break;
				}
			}
			return status;
		}
	}
}
