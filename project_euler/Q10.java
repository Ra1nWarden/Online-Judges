import java.util.ArrayList;


public class Q10 {

	public static void main(String[] args) {
		ArrayList<Integer> primelist = new ArrayList<Integer>();
		primelist.add(2);
		for (int i = 3; i < 2000000; i++){
			int number = i;
			boolean prime = true;
			for (int j = 0; j < primelist.size(); j++){
				int test = primelist.get(j);
				if (test > Math.sqrt(number))
					break;
				else if (number % test == 0){
					prime = false;
					break;
				}
			}
			if (prime)
				primelist.add(number);
		}
		System.out.println(primelist);
		long sum = 0;
		for (int i = 0; i < primelist.size(); i++){
			sum += primelist.get(i);
		}
		System.out.println(sum);
	}
}

