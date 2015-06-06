import java.util.ArrayList;


public class Q27 {

	public static void main(String[] args) {
		ArrayList<Integer> primelist = new ArrayList<Integer>();
		primelist.add(2);
		for (int i = 3; i < 1000; i++){
			boolean prime = true;
			for (int one : primelist){
				if (i % one == 0){
					prime = false;
					break;
				}
			}
			if (prime)
				primelist.add(i);
		}
		primelist.add(0, 1);
		int maxa = 0;
		int maxb = 0;
		int maxno = 0;
		for (int i = 0; i < primelist.size(); i++){
			int b = primelist.get(i);
			for (int j = -999; j < 1000; j+=2){
				int a = j;
				int n = 0;
				while (isprime(n*(n+a)+b)){
					n++;
				}
				if (n > maxno){
					maxa = a;
					maxb = b;
					maxno = n;
				}
			}
		}
		System.out.println(maxa*maxb);

	}
	
	public static boolean isprime(int number){
		boolean prime = true;
		if (number < 0)
			prime = false;
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
