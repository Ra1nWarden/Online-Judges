import java.math.BigInteger;


public class Q100 {
	
// This brute force approach takes too long.

//	public static void main(String[] args) {
//		BigInteger large = new BigInteger("1000000000000");
//		int count = 0;
//		while(true) {
//			BigInteger small = large.subtract(BigInteger.ONE);
//			BigInteger product = null;
//			if (count % 2 == 0) {
//				product = small.multiply(large.divide(new BigInteger("2")));
//			}
//			else
//				product = large.multiply(small.divide(new BigInteger("2")));
//			BigInteger squareroot = sqrt(product);
//			BigInteger newproduct = squareroot.multiply(squareroot.add(BigInteger.ONE));
//			if(newproduct.compareTo(product) == 0) {
//				System.out.println(squareroot);
//			}
//			count++;
//			large = large.add(BigInteger.ONE);
//		}
//	}
//	
//	public static BigInteger sqrt(BigInteger number) {
//		BigDecimal currentnumber = new BigDecimal(number);
//		BigDecimal result = BigDecimal.ONE;
//		BigDecimal two = new BigDecimal("2");
//		BigDecimal nextresult = BigDecimal.ONE;
//		do {
//			result = nextresult;
//			nextresult = result.add(currentnumber.divide(result, 11, BigDecimal.ROUND_DOWN));
//			nextresult = nextresult.divide(two, 10, BigDecimal.ROUND_DOWN);
//		} while(nextresult.toBigInteger().compareTo(result.toBigInteger()) != 0);
//		return result.toBigInteger();
//	}

	// Convert the problem into finding integer solutions to a quadratic equation with two unknowns.
	// Complete squares to form a Pell's Equation
	// X^2-nY^2=1
	// Xk+1 = X1Xk + nY1Yk
	// Yk+1 = X1Yk + Y1Xk
	// Use the recursive formula.
	
	public static void main(String[] args) {
		BigInteger blue = new BigInteger("15");
		BigInteger total = new BigInteger("21");
		BigInteger target = new BigInteger("1000000000000");
		do {
			BigInteger bluecopy = blue;
			BigInteger totalcopy = total;
			total = totalcopy.multiply(new BigInteger("3")).add(bluecopy.multiply(new BigInteger("4"))).subtract(new BigInteger("3"));
			blue = bluecopy.multiply(new BigInteger("3")).add(totalcopy.multiply(new BigInteger("2"))).subtract(new BigInteger("2"));
		} while(total.compareTo(target) < 0);
		System.out.println(blue);
		System.out.println(total);
	}

}
