public class Q16 {


	public static void main(String[] args) {
		String number = "2";
		for (int i = 0; i < 999; i++){
			int length = number.length();
			String answer = "";
			int forward = 0;
			for (int j = length-1; j >= 0; j--){
				int result = Integer.parseInt(number.substring(j, j+1)) * 2 + forward;
				int digit = result % 10;
				forward = result / 10;
				answer = Integer.toString(digit) + answer;
				if (j == 0){
					if (forward != 0)
						answer = Integer.toString(forward) + answer;
					number = answer;
				}
			}
		}
		System.out.println(number);
		int sumdigit = 0;
		for (int k = 0; k < number.length(); k++){
			sumdigit += Integer.parseInt(number.substring(k, k+1));
		}
		System.out.println(sumdigit);
	}

}
