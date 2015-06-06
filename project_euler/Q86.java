import java.util.ArrayList;


public class Q86 {

	public static void main(String[] args) {
		int number = 1;
		int totalcount = 0;
		while(totalcount < 1000000) {
			ArrayList<Integer> currentdigit = find(number);
			int count = count(currentdigit, number);
			totalcount += count;
			number++;
		}
		System.out.println(number - 1);
	}
	
	public static ArrayList<Integer> find(int number) {
		ArrayList<Integer> result = new ArrayList<Integer>();
		for(int i = 2; i <= 2*number; i++) {
			double squared = Math.pow(number, 2) + Math.pow(i, 2);
			if (Math.sqrt(squared) == (int) (Math.sqrt(squared)))
				result.add(i);
		}
		return result;
	}
	
	public static int count(ArrayList<Integer> list, int number) {
		int result = 0;
		for (int one : list) {
			for (int i = 1; i <= number; i++) {
				if (one - i >= i && one - i <= number)
					result++;
			}
		}
		return result;
	}
}
