import java.math.BigInteger;
import java.util.ArrayList;


public class Q65 {

	public static void main(String[] args) {
		ArrayList<BigInteger> list = new ArrayList<BigInteger>();
		for(int i = 1; i <= 33; i++){
			BigInteger current = new BigInteger(Integer.toString(i));
			list.add(new BigInteger("1"));
			list.add(current.multiply(new BigInteger("2")));
			list.add(new BigInteger("1"));
		}
		BigInteger[] firstresult = next(list.get(97), new BigInteger("1"), list.get(98));
		
		for(int i = 96; i >= 0; i--){
			BigInteger[] nextresult = next(list.get(i), firstresult[0], firstresult[1]);
			firstresult = nextresult;
		}
		
		BigInteger[] finalresult = next(new BigInteger("2"), firstresult[0], firstresult[1]);
		String finalnum = finalresult[1].toString();
		int digitsum = 0;
		for(int i = 0; i < finalnum.length(); i++){
			digitsum += Integer.parseInt(finalnum.substring(i, i+1));
		}
		System.out.println(digitsum);

	}
	
	public static BigInteger[] next(BigInteger a, BigInteger b, BigInteger c){
		BigInteger[] result = new BigInteger[2];
		result[0] = c;
		result[1] = a.multiply(c).add(b);
		return result;
	}

}
