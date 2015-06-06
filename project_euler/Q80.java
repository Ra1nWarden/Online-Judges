import java.math.BigDecimal;
import java.math.BigInteger;


public class Q80 {

//	public static void main(String[] args) {
//		double totalsum = 0;
//		for(int i = 2; i < 100; i++){
//			if((int) Math.sqrt(i) != Math.sqrt(i)){
//				BigDecimal target = new BigDecimal(i);
//				BigDecimal firstresult = calculate(BigDecimal.ONE, target, 1);
//				BigDecimal nextresult = BigDecimal.ONE;
//				int degree = 2;
//				while(!firstresult.equals(nextresult)){
//					firstresult = nextresult;
//					nextresult = calculate(BigDecimal.ONE, target, degree);
//					degree++;
//				}
//				
//				System.out.println(digitsum(nextresult));
//				totalsum += digitsum(nextresult);
//			}
//		}
//		System.out.println(totalsum);
//	}
//	
//	public static BigDecimal calculate(BigDecimal number, BigDecimal target, int degree){
//		if(degree == 0)
//			return number;
//		else{
//			BigDecimal result = (number.add(target.divide(number, 500, BigDecimal.ROUND_HALF_UP))).divide(new BigDecimal("2"), 500, BigDecimal.ROUND_HALF_UP);
//			return calculate(result, target, degree-1);
//		}
//	}
//	
//	public static int digitsum(BigDecimal number){
//		int result = 0;
//		String numberins = number.toString().substring(2, 102);
//		System.out.println(numberins);
//		for(int i = 0; i < numberins.length(); i++){
//			result += Integer.parseInt(numberins.substring(i, i+1));
//		}
//		return result;
//	}
// This method uses newton's iteration. I will use another method.
// UPDATE: There is nothing wrong with the method above (Yes, the answer is also correct)
	
// This method does not involve any decimal calculation (integers only).
// To find the square root of n.
// 1. a = 5n b = 5
// 2. if a >= b
//    a = a-b b = b+10
//    if a < b
//    add two zeros to the end of a
//    add one zero right before the last digit of b (last digit of b is always 5)
// The digit of b will approach the digits of sqrt(n)
	
	public static void main(String[] args){
		int total = 0;
		for(int i = 1; i < 100; i++){
			if((int) Math.sqrt(i) != Math.sqrt(i)){
				BigInteger sqrt = find(i);
				for(int j = 0; j < 100; j++){
					total += Integer.parseInt(sqrt.toString().substring(j, j+1));
				}
			}
		}
		System.out.println(total);
		System.out.println(find(2));
	}
	
	public static BigInteger find(int number){
		BigInteger a = new BigInteger(Integer.toString(number*5));
		BigInteger b = new BigInteger("5");
		while(b.toString().length() < 105){
			if(a.compareTo(b) >= 0){
				a = a.subtract(b);
				b = b.add(new BigInteger("10"));
			}
			else{
				a = a.multiply(new BigInteger("100"));
				String bins = b.toString();
				int length = bins.length();
				b = new BigInteger(bins.substring(0, length-1) + "0" + bins.substring(length-1));
			}
		}
		return b;
	}
	
}
