import java.math.BigInteger;


public class Q76 {

//	public static void main(String[] args) {
//		System.out.println(count(100,99));
//
//	}
//	
//	public static BigInteger count(int number, int start) {
//		if (number == 0)
//			return BigInteger.ZERO;
//		else{
//			BigInteger result = BigInteger.ZERO;
//			if (start >= number) 
//				start = number;
//			while (start > 1){
//				if (count(number - start, start).equals(BigInteger.ZERO))
//					result = result.add(BigInteger.ONE);
//				else
//					result = result.add(count(number - start, start));
//				start--;
//			}
//			result = result.add(BigInteger.ONE);
//			return result;
//		}
//	}
	
// The above method seems to work but it takes too long.
// This method makes use of dynamic programming which is something worth learning.
// http://www.mathblog.dk/project-euler-31-combinations-english-currency-denominations/
	
	public static void main(String[] args) {
		int[] numbers = new int[101];
		numbers[0] = 1;
		for (int i = 1; i <= 99; i++){
			for (int j = i; j < 101; j++){
				numbers[j] += numbers[j-i];
			}
		}
		System.out.println(numbers[100]);
	}

}
