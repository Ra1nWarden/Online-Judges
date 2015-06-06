
public class Q4 {

	public static void main(String[] args) {
		for (int i = 8; i >= 0; i--){
			for (int j = 9; j >=0; j--){
				int number = 9*100000 + i*10000 + j*1000 + j*100 + i*10 + 9;
				if (FindhundredFactor(number)){
					System.out.println(number);
					System.exit(0);
				}
			}
		}

	}
	
	public static boolean FindhundredFactor(int number){
		int test = 100;
		while(test != number && test < 1000){
			if (number % test == 0){
				int dividend = number/test;
				if (dividend > 99 && dividend < 1000){
					return true;
				}
			}
			test++;
		}
		return false;
	}

}
