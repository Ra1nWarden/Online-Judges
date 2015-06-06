
public class Q46 {

	public static void main(String[] args) {
		int odd = 33;
		while (true){
			odd += 2;
			if (!isprime(odd)){
				boolean found = false;
				for (int i = 1; 2 * Math.pow(i, 2) < odd; i++){
					if (isprime((int) (odd-2*Math.pow(i,2)))){
						found = true;
						break;
					}	
				}
				if (!found){
					System.out.println(odd);
					System.exit(0);
				}
			}
			
		}
		

	}
	
	public static boolean isprime(int number){
		boolean prime = true;
		if (number == 1)
			prime = false;
		else if (number == 2)
			prime = true;
		else{
			for (int i = 2; i < Math.sqrt(number); i++){
				if (number % i == 0){
					prime = false;
					break;
				}
			}
		}
		return prime;
	}

}
