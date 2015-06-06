import java.util.ArrayList;


public class Q12 {

	public static void main(String[] args) {
		int trinumber = 0;
		for (int i = 1; i > 0; i++){
			trinumber += i;
			if (numberofdivisor(trinumber) > 500){
				System.out.println(trinumber);
				break;
			}
		}

	}
	
	public static int numberofdivisor(int n){
		ArrayList<Integer> divisor = new ArrayList<Integer>();
		for (int i = 1; i < Math.sqrt(n); i++){
			if (n % i == 0){
				divisor.add(i);
				int dividend = n / i;
				if (dividend != i)
					divisor.add(dividend);
					
			}
		}
		return divisor.size();
	}

}
