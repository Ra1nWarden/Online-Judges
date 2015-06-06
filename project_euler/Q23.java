import java.util.ArrayList;


public class Q23 {

	public static void main(String[] args) {
		ArrayList<Integer> cannotbewritten = new ArrayList<Integer>();
		for (int i = 1; i <= 28123; i++){
			boolean status = true;
			for (int j = 1; j <= i/2; j++){
				if (checkabundant(j)){
					if (checkabundant(i-j)){
						status = false;
						break;
					}
				}
			}
			if (status)
				cannotbewritten.add(i);
		}
		long sum = 0;
		for (int one : cannotbewritten)
			sum += one;
		System.out.println(sum);

	}
	
	public static boolean checkabundant(int number){
		int sum = 0;
		for (int i = 1; i <= Math.sqrt(number); i++){
			if (number % i == 0){
				sum += i;
				if (i != 1 && i != Math.sqrt(number))
					sum += number/i;
			}
		}
		return (sum > number);
	}

}
