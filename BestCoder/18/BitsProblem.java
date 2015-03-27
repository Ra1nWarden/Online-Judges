import java.math.BigInteger;
import java.util.Scanner;

public class BitsProblem {

    public static BigInteger choose(int n, int c) {
	if(c == 0)
	    return BigInteger.ONE;
	BigInteger result = BigInteger.ONE;
	int numerator = n;
	for(int i= 1; i <= c; i++) {
	    result = result.multiply(new BigInteger(Integer.toString(numerator)));
	    result = result.divide(new BigInteger(Integer.toString(i)));
	    numerator--;
	}
	return result;
    }
    
    public static void main(String args[]) {
	Scanner sc = new Scanner(System.in);
	int n = sc.nextInt();
	BigInteger r = sc.nextBigInteger();
	String bits = r.toString(2);
	System.out.println(bits);
	BigInteger result = BigInteger.ZERO;
	if(n <= bits.length()) {
	    for(int i = 0; i < bits.length(); i++) {
		if(bits.charAt(i) == '1') {
		    result = result.add(choose(bits.length() - 1 - i, n));
		    n--;
		    if(n == 0) {
			result = result.add(BigInteger.ONE);
			break;
		    }
		}
	    }
	}
	System.out.println(result.mod(new BigInteger("1000000007")));
    }

}
