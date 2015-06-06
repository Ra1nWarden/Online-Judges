import java.util.ArrayList;
import java.util.Arrays;


public class Q77 {

	public static void main(String[] args) {
		int testnumber = 100;
		ArrayList<Integer> fivethousand = sieve(testnumber);
		int[] numbers = new int[testnumber+1];
		numbers[0] = 1;
		for(int i = 0; i < fivethousand.size(); i++){
			int currentprime = fivethousand.get(i);
			for(int j = currentprime; j < numbers.length; j++){
				if(numbers[j-currentprime] != 0){
					numbers[j] += numbers[j-currentprime];
				}
			}
		}
		System.out.println(numbers[10]);
		for(int i = 0; i < numbers.length; i++){
			if(numbers[i] > 5000){
				System.out.println(i);
				System.exit(0);
			}
		}
		System.out.println("Not Found!");
		
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
