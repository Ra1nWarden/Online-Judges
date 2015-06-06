import java.math.BigInteger;


public class Q94 {
	
// The problem with this brute-force approach is due to the precision of the double type of variables.
// When the number to be taken square root becomes large enough, the integer part will take all the precisions. (double a == (int) a)
//	public static void main(String args[]) {
//		int side = 2;
//		BigInteger ans = BigInteger.ZERO;
//		while (3 * side + 1 < 1000000000) {
//			if (check(side, side + 1)) {
//				ans = ans.add(new BigInteger(Integer.toString(3 * side + 1)));
//				System.out.println(side + " " + side + " " + (side + 1));
//			}
//			if (check(side, side - 1)) {
//				ans = ans.add(new BigInteger(Integer.toString(3 * side - 1)));
//				System.out.println(side + " " + side + " " + (side-1));
//			}
//			side++;
//		}
//		System.out.println(ans);
//	}
//	
//	public static boolean check(int side, int other) {
//		if (other % 2 == 0) {
//			double squared = Math.pow(side, 2) - Math.pow(other / 2, 2);
//			return Math.sqrt(squared) == (int) Math.sqrt(squared);
//		}
//		else
//			return false;
//	}
	
// Use Pell's Equation x^2 - ny^2 = 1 with x1 = 2 y1 = 1 n = 3
// xk+1 = x1 * xk + n * y1 * yk
// yk+1 = x1 * yk + y1 * xk
	public static void main(String args[]) {
		int x1 = 2;
		int y1 = 1;
		int x = 2;
		int y = 1;
		BigInteger result = BigInteger.ZERO;
		outerloop:
		while (true) {
			if ((2 * x + 1) % 3 == 0) {
				int a = (2 * x + 1) /3;
				int b = a + 1;
				if (3 * a + 1 < 1000000000) {
					if ((b * y) % 2 == 0) {
						System.out.println(a + " " + a + " " + b);
						result = result.add(new BigInteger(Integer.toString(3 * a + 1)));
					}
				}
				else
					break outerloop;
			}
			if ((2 * x -1) % 3 == 0) {
				int a = (2 * x - 1) /3;
				int b = a - 1;
				if (3 * a - 1 < 1000000000) {
					if ((b * y) % 2 == 0 && b != 0) {
						System.out.println(a + " " + a + " " + b);
						result = result.add(new BigInteger(Integer.toString(3 * a - 1)));
					}
				}
				else
					break outerloop;
			}
			int xclone = x;
			x = x1 * x + 3 * y1 * y;
			y = x1 * y + y1 * xclone;
		}
		System.out.println(result);
	}

}
