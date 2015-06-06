import java.math.BigInteger;
import java.util.ArrayList;


public class Q74 {

	public static void main(String[] args) {
		int count = 0;
		for(int i = 2; i < 1000000; i++){
			if(cyclecount(i) == 60)
				count++;
		}
		System.out.println(count);
	}
	
	public static int cyclecount(int number){
		BigInteger current = new BigInteger(Integer.toString(number));
		ArrayList<BigInteger> cycle = new ArrayList<BigInteger>();
		while(!cycle.contains(current)){
			cycle.add(current);
			current = next(current);
		}
		return cycle.size();
	}
	
	public static BigInteger next(BigInteger number){
		String numberinl = number.toString();
		BigInteger result = BigInteger.ZERO;
		for(int i = 0; i < numberinl.length(); i++){
			int digit = Integer.parseInt(numberinl.substring(i, i+1));
			result = result.add(new BigInteger(Integer.toString(factorial(digit))));
		}
		return result;
	}
	
	public static int factorial(int number){
		if(number == 0)
			return 1;
		else
			return number * factorial(number-1);
	}

}
