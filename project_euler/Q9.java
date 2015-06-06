
public class Q9 {

	public static void main(String[] args) {
		for (double i = 2; i < 1000; i++){
			double product = (Math.pow(1000, 2) - 2000*i)/2;
			double sum = 1000 - i;
			for (double j = 1; j < sum; j++){
				if (j * (sum-j) == product)
					System.out.println(i*j*(1000-i-j));
			}
			
		}

	}

}
