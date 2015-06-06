
public class Q85 {
	
	public static void main(String[] args) {
		int minval = Integer.MAX_VALUE;
		int answer = 0;
		for(int i = 1; i <= 1999; i++) {
			int result = Integer.MAX_VALUE;
			int jans = 0;
			for(int j = 1; j <= i; j++) {
				if(calculate(i) * calculate(j) > 2000000) {
					int first = calculate(i) * calculate(j-1);
					int second = calculate(i) * calculate(j);
					if (2000000 - first < second - 2000000) {
						result = 2000000 - first;
						jans = j - 1;
					}
					else {
						result = second - 2000000;
						jans = j;
					}
					break;
				}
			}
			if (result < minval) {
				minval = result;
				answer = jans * i;
			}
			
		}
		System.out.println(answer);
	}
	
	public static int calculate(int number) {
		if (number == 1)
			return 1;
		else
			return number + (calculate(number-1));
	}

}
