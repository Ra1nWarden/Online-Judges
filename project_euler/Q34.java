import java.util.ArrayList;


public class Q34 {

	public static void main(String[] args) {
		int sum = 0;
		for (int i = 10; i < 2540160; i++){
			int factorialsum = 0;
			int number = i;
			while (number > 0){
				factorialsum += factorial(number % 10);
				number /= 10;
			}
			if (factorialsum == i)
				sum += i;
		}
		System.out.println(sum);

	}
	
	public static int factorial(int number){
		if (number == 1 || number == 0)
			return 1;
		else return number*factorial(number-1);
	}

}
