

public class Q45 {

	public static void main(String[] args) {
		int start = 40755;
		for (int i = 286; i > 0; i++){
			start += i;
			if (ispentagonal(start)){
				if(ishexagonal(start)){
					System.out.println(start);
					System.exit(0);
				}
			}
		}

	}
	
	public static boolean ispentagonal(int number){
		int current = 1;
		int power = 1;
		while (current < number){
			current += (power * 3 + 1);
			power++;
		}
		return (current == number);
			
	}
	public static boolean ishexagonal(int number){
		int current = 1;
		int power = 1;
		while (current < number){
			current += (power * 4 + 1);
			power++;
		}
		return (current == number);
			
	}

}
