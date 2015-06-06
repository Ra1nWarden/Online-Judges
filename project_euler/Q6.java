
public class Q6 {


	public static void main(String[] args) {
		long result = 0;
		for (int i = 1; i < 100; i++){
			for (int j = i+1; j <= 100; j++){
				result += i*j;
			}
		}
		System.out.println(result*2);

	}

}
