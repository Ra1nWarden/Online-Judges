
public class Q53 {

	public static void main(String[] args) {
		int count = 0;
		for (int i = 23; i <= 100; i++){
			for (int j = 1; j < i; j++){
				if(choose(i,j)>1000000)
					count++;
			}
		}
		System.out.println(count);

	}
	
	public static double choose(int total, int choice){
		return ((factorial(total))/(factorial(choice)*factorial(total-choice)));
	}
	
	public static double factorial(int number){
		if (number == 1)
			return 1;
		else return (number*factorial(number-1));
	}

}
