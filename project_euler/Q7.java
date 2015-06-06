public class Q7 {

	public static void main(String[] args) {
		int prime = 1;
		int factor;
		int sum = 2;
		while (prime < 2000000){
			prime += 2;
			factor = 1;
			while (true){
				factor += 2;
				if (prime % factor == 0 && prime != factor)
					break;
				if (prime == factor){
					sum+=prime;
					break;
				}
			}
		}
		System.out.println(sum);
	
	}
	
}
