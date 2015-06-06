
public class Q36 {

	public static void main(String[] args) {
		int sum = 0;
		for (int i = 1; i < 1000000; i++){
			String current = Integer.toString(i);
			if (checkpandi(current)){
				String converted = convert(i);
				if (checkpandi(converted))
					sum += i;
			}
		}
		System.out.println(sum);
	}

	public static boolean checkpandi(String str){
		boolean status = true;
		for (int i = 0; i < str.length(); i++){
			if (str.charAt(i) != str.charAt(str.length()-1-i)){
				status = false;
				break;
			}
		}
		return status;
	}
	
	public static String convert(int number){
		String ans = "";
		while (number > 0){
			ans = Integer.toString(number % 2) +ans;
			number /= 2;
		}
		return ans;
	}
}
