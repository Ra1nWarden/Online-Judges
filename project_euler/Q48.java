import java.math.BigInteger;


public class Q48 {


	public static void main(String[] args) {
		BigInteger sum = new BigInteger("0");
		for (int i= 1; i <= 1000; i++){
			BigInteger current = new BigInteger(Integer.toString(i));
			current = current.pow(i);
			sum = sum.add(current);
		}
		String suminl = sum.toString();
		int length = suminl.length();
		System.out.println(suminl.substring(length - 10));

	}

}
