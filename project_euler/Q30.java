import java.util.ArrayList;


public class Q30 {

	public static void main(String[] args) {
		ArrayList<Integer> target = new ArrayList<Integer>();
		for (int i = 10; i <= 354294; i++){
			String number = Integer.toString(i);
			int sum = 0;
			for (int k = 0; k < number.length(); k++){
				sum += Math.pow(Integer.parseInt(number.substring(k, k+1)), 5);
			}
			if (i == sum)
				target.add(i);
		}	
		int result = 0;
		for (int one : target)
			result += one;
		System.out.println(result);
	}

}
