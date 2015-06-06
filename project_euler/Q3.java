import java.util.ArrayList;


public class Q3 {

	public static void main(String[] args) {
		ArrayList<Long> factorlist = new ArrayList<Long>();
		long question = 600851475143L;
		boolean factorization = false;
		while (!factorization){
			long dividend = FindFactor(question);
			if (dividend != 1){
				factorlist.add(dividend);
				question = question/dividend;
			}
			else{
				factorlist.add(question);
				factorization = true;
			}
		}
		long answer = factorlist.get(0);
		for (Long one : factorlist){
			if (one > answer)
				answer = one;
		}
		System.out.println(answer);
	}
	
	public static long FindFactor(long number){
		long factor = 1; 
		boolean loop = true;
		long test = 2;
		while (loop && test != number){
			if (number % test == 0){
				factor = test;
				loop = false;
			}
			test ++;
		}
		return factor;
	}

}
