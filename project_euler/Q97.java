import java.math.BigInteger;


public class Q97 {

	public static void main(String[] args) {
		BigInteger result = new BigInteger("2");
		for (int i = 1; i < 7830457; i++) {
			result = result.multiply(new BigInteger("2"));
			int length = result.toString().length();
			if (length > 10)
				result = new BigInteger(result.toString().substring(length - 10));
		}
		result = result.multiply(new BigInteger("28433"));
		result = result.add(BigInteger.ONE);
		System.out.println(result);
	}

}
