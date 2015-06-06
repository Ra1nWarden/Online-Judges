
public class Q92 {
	
	public static void main(String args[]) {
		int count = 0;
		for (int i = 1; i <= 10000000; i++) {
			if (check(i))
				count++;
		}
		System.out.println(count);
	}
	
	public static int next(int number) {
		String numberinl = Integer.toString(number);
		int result = 0;
		for (int i = 0; i < numberinl.length(); i++)
			result += (int) Math.pow(Integer.parseInt(numberinl.substring(i, i+1)), 2);
		return result;
	}
	
	public static boolean check(int number) {
		while (number != 1) {
			if (number == 89)
				return true;
			number = next(number);
		}
		return false;
	}

}
