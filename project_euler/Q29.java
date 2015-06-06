import java.math.BigInteger;
import java.util.ArrayList;


public class Q29 {

	public static void main(String[] args) {
		ArrayList<BigInteger> list = new ArrayList<BigInteger>();
		for (int i = 2; i <= 100; i++){
			BigInteger a = new BigInteger(Integer.toString(i));
			for (int j = 2; j <= 100; j++){
				BigInteger result = a.pow(j);
				if (!list.contains(result))
					list.add(result);
			}
		}
		System.out.println(list.size());
	}

}
