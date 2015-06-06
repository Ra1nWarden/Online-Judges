import java.math.BigInteger;


public class Q63 {

	
	public static void main(String[] args) {
		int totalcount = 0;
		for(int i = 1; i > 0; i++){
			int currentadd = powerdigit(i);
			totalcount += currentadd;
			System.out.println(totalcount);
		}
		
	
	}
	
	public static int powerdigit(int number){
		
		int count = 0;
		for(int i = 1; i < 10; i++){
			BigInteger digit = new BigInteger(Integer.toString(i));
			BigInteger result = digit.pow(number);
			if(result.toString().length() == number)
				count++;
		}
		return count;
	}

}
