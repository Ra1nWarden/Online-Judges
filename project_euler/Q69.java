import java.util.ArrayList;
import java.util.Arrays;


public class Q69 {

	public static void main(String[] args) {
		int number = 0;
		int maxcount = 1;
		double result = ((double) number) / maxcount;
		for(int i = 2; i <= 1000000; i++){
			int currentnumber = i;
			int currentcount = findcoprime(i);
			System.out.println(currentnumber);
			System.out.println(currentcount);
			double currentresult = ((double) currentnumber) / currentcount;
			if(currentresult > result){
				number = i;
				maxcount = currentcount;
				result = currentresult;
			}
		}
		System.out.println(number);

	}

	public static ArrayList<Integer> finddivisor(int number){
		int length = (int) Math.sqrt(number);
		boolean[] halfnumbers = new boolean[length];
		Arrays.fill(halfnumbers, true);
		for(int i = 0; i < length; i++){
			if(halfnumbers[i] && i != 0){
				int gap = i + 1;
				for(int j = i + gap; j < length; j += gap)
					halfnumbers[j] = false;
			}
		}
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int i = 1; i < length; i++){
			if(halfnumbers[i]){
				if(number % (i+1) == 0){
					result.add(i+1);
					int remainder = number / (i+1);
					if(number % remainder == 0)
						result.add(remainder);
				}
			}
				
		}
		return result;
	}

	public static int findcoprime(int number){
		boolean[] listofno = new boolean[number-1];
		Arrays.fill(listofno, true);
		ArrayList<Integer> divisor = finddivisor(number);
		for(int one : divisor){
			if(one != 1){
				for(int i = one - 1; i < listofno.length; i += one)
					listofno[i] = false;
			}
		}
		int count = 0;
		for(int i = 0; i < listofno.length; i++){
			if(listofno[i])
				count++;
		}
		return count;
	}
	//Check out Euler's Totient function on Wiki. This takes too long to run. T_T
	//However, some parts of this code are useful! :)
}
