import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;


public class Q110 {
	
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
		BigInteger result = BigInteger.ONE;
		for(int i = 0; i < primes.length; i++)
			result = result.multiply(new BigInteger(Integer.toString(primes[i])));
		System.out.println(result);
		for(int length = 13; length > 1; length--) {
			int exponents[] = new int[length];
			Arrays.fill(exponents, 1);
			int increaseindex = 1;
			while(true) {
				two(exponents);
				if(exponents[0] < exponents[1])
					increaseindex++;
				else {
					BigInteger currentresult = prod(primes, exponents);
					if(currentresult.compareTo(result) < 0) {
						result = currentresult;
						System.out.println(result);
					}
					increaseindex = 1;
				}
				
				if(increaseindex >= length)
					break;
				exponents[increaseindex]++;
				fillArray(exponents, increaseindex);
			}
		}
		long end = System.currentTimeMillis();
		System.out.print((end - start) + " ms");

	}
	
	public static void two(int[] exponents) {
		int target = 2 * 4000000 - 1;
		int runningprod = 1;
		for(int i = 1 ; i < exponents.length; i++)
			runningprod *=  (2 * exponents[i] + 1);
		exponents[0] = (int) (((target / runningprod) - 1) / 2);
		while((exponents[0] * 2 + 1)* runningprod < target)
			exponents[0]++;
	}
	
	public static BigInteger prod(int[] primes, int[] exponents) {
		BigInteger product = BigInteger.ONE;
		for(int i = 0; i < exponents.length; i++) {
			BigInteger currentprod = new BigInteger(Integer.toString(primes[i]));
			currentprod = currentprod.pow(exponents[i]);
			product = product.multiply(currentprod);
		}
		return product;
	}
	
	public static void fillArray(int[] exponents, int index) {
		for(int i = 1; i < index; i++)
			exponents[i] = exponents[index];
	}
	
	
	

}
