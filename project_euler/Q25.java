import java.math.BigInteger;
import java.util.ArrayList;


public class Q25 {

	public static void main(String[] args) {
		BigInteger result = new BigInteger("1");
		ArrayList<BigInteger> list = new ArrayList<BigInteger>();
		list.add(result);
		list.add(result);
		for (int i = 3; i > 0; i++){
			result = list.get(0).add(list.get(1));
			if (result.toString().length() == 1000){
				System.out.println(i);
				System.exit(0);
			}
			list.add(result);
			list.remove(0);
		}

	}
	
	

}
