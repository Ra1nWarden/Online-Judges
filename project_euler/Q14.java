import java.util.ArrayList;


public class Q14 {

	public static void main(String[] args) {
		ArrayList<Integer> sequencelength = new ArrayList<Integer>();
		for (int i = 999999; i > 0; i--){
			long currentno = i;
			int length = 1;
			while (currentno != 1){
				long next = nextInt(currentno);
				currentno = next;
				length++;
			}
			sequencelength.add(length);
		}
		int maxindex = 0;
		int max = 0;
		for (int i = 0; i < sequencelength.size(); i++){
			int test = sequencelength.get(i);
			if (test > max){
				max = test;
				maxindex = i;
			}
		}
		System.out.println(999999 - maxindex);

	}
	
	public static long nextInt(long number){
		if (number % 2 == 0){
			return number / 2;
		}
		else{
			return 3 * number + 1;
		}
	}

}
