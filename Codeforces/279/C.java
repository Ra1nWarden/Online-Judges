import java.math.BigInteger;
import java.util.Scanner;
import java.lang.*;

public class C {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String code = sc.nextLine();
	BigInteger a = sc.nextBigInteger();
	BigInteger b = sc.nextBigInteger();
	boolean success = false;
	for(int i= 0; i < code.length() - 1; i++) {
	    if(code.charAt(i+1) != '0') {
		BigInteger first = new BigInteger(code.substring(0, i+1));
		BigInteger second = new BigInteger(code.substring(i+1));
		if(first.mod(a).compareTo(BigInteger.ZERO) == 0 && second.mod(b).compareTo(BigInteger.ZERO) == 0) {
		    success = true;
		    System.out.println("YES");
		    System.out.println(first);
		    System.out.println(second);
		    break;
		}
	    }
	}
	if(!success)
	    System.out.println("NO");
    }
    
}
