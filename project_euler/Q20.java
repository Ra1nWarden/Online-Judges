import java.math.BigInteger;


public class Q20 {

	public static void main(String[] args) {
		BigInteger product = new BigInteger("1");
		for (int i = 100; i > 1; i--){
			product = product.multiply(new BigInteger(Integer.toString(i)));
		}
		String answer = product.toString();
		int sumofdigit = 0;
		for (int i = 0; i < answer.length(); i++){
			sumofdigit += Integer.parseInt(answer.substring(i,i+1));
		}
		System.out.println(sumofdigit);
	}

}
