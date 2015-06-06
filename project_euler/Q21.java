import java.util.ArrayList;


public class Q21 {

	public static void main(String[] args) {
		ArrayList<Integer> amicable = new ArrayList<Integer>();
		for (int i = 1; i < 10000; i++){
			if (!amicable.contains(i)){
				int sum = sumofdivisor(i);
				int sum2 = sumofdivisor(sum);
				if (sum2 == i && i != sum){
					amicable.add(i);
					amicable.add(sum);
				}
			}
		}
		int sumofamicable = 0;
		for (int one : amicable){
			sumofamicable += one;
		}
		System.out.println(sumofamicable);
	}
	
	public static int sumofdivisor(int number){
		ArrayList<Integer> divisor = new ArrayList<Integer>();
		for (int i = 1; i <= Math.sqrt(number); i++){
			if (number % i == 0){
				divisor.add(i);
				if (number / i != i && i != 1)
					divisor.add(number / i);
			}
		}
		int sum = 0;
		for (int one : divisor)
			sum += one;
		return sum;
	}

}
