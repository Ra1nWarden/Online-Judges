import java.util.ArrayList;


public class Q2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		ArrayList<Integer> Fib = new ArrayList<Integer>();
		boolean loop = true;
		Fib.add(1);
		Fib.add(2);
		int index = 3;
		while (loop){
			if (GenerateFib(index) < 4000000){
				Fib.add(GenerateFib(index));
				index++;
			}
			else
				loop = false;
		}
		int sum = 0;
		for (int i = 1; i < Fib.size(); i += 3){
			sum += Fib.get(i);
		}
		System.out.println(sum);
	}
	
	public static int GenerateFib(int n){
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		else return (GenerateFib(n-1) + GenerateFib(n-2));
	}

}
