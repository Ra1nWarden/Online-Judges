import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;


public class Q87 {

	public static void main(String[] args) {
		// This is a rather brute force approach. I have not come up with a faster solution.
		ArrayList<Integer> primelist = sieve(7071);
		ArrayList<Double> second = new ArrayList<Double>();
		for(int one : primelist) 
			second.add(Math.pow(one, 2));
		ArrayList<Double> third = new ArrayList<Double>();
		primelist = sieve(368);
		for(int one : primelist)
			third.add(Math.pow(one, 3));
		ArrayList<Double> fourth = new ArrayList<Double>();
		primelist = sieve(84);
		for(int one : primelist)
			fourth.add(Math.pow(one, 4));

		ArrayList<Double> possibilities = new ArrayList<Double>();
		for (int k = fourth.size() - 1; k >=0 ; k--) {
			for (int j = 0; j < third.size(); j++) {
				double sum = fourth.get(k) + third.get(j);
				if (sum > 50000000)
					break;
				else {
					for (int i = 0; i < second.size(); i++) {
						double nextsum = sum + second.get(i);
						if (nextsum > 50000000)
							break;
						else {
							// I am not sure whether it can be proved that the sum is unique.
							if (!possibilities.contains(nextsum))
								possibilities.add(nextsum);
						}
					}	
				}
			}
		}
		int totalcount = possibilities.size();
		System.out.println(totalcount);
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
