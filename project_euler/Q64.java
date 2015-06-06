
public class Q64 {

	public static void main(String[] args) {
		int oddperiod = 0;
		for(int i = 2; i <= 10000; i++){
			double squareroot = Math.sqrt(i);
			int wholenumber = (int) (Math.sqrt(i));
			if(squareroot != wholenumber){
				int period = findperiod(i, -wholenumber, 0, 1);
				if(period % 2 == 1)
					oddperiod++;
			}
		}
		System.out.println(oddperiod);
	}
	
	public static int[] findnext(int a, int b, int c, int d){
		int[] result = new int[5];
		result[0] = (int) ((Math.sqrt(c) + d) / (Math.sqrt(a) + b));
		result[3] = 0;
		result[4] = (int) (a - Math.pow(b, 2));
		result[1] = (int) (Math.pow(d,2)) * a;
		result[2] = d * (-b) - result[4] * result[0];
		simplify(result);
		return result;
	}
	
	public static int findperiod(int a, int b, int c, int d){
		int[] firstresult = findnext(a, b, c, d);
		int[] start = firstresult.clone();
		int count = 1;
		while(true){
			int[] nextresult = findnext(start[1], start[2], start[3], start[4]);
			if(checkequal(firstresult,nextresult))
				break;
			else{
				start = nextresult;
				count++;
			}
		}
		return count;
	}
	
	public static boolean checkequal(int[] first, int[] second){
		boolean status = true;
		for(int i = 0; i < first.length; i++){
			if(first[i] != second[i]){
				status = false;
				break;
			}
		}
		return status;
	}
	
	public static void simplify(int[] numbers){
		int numsqr = numbers[1];
		int numwho = numbers[2];
		int densqr = numbers[3];
		int denwho = numbers[4];
		int numsqrwho = findsqr(numbers[1]);
		int densqrwho = findsqr(numbers[3]);
		int smallest = denwho;
		if(numsqrwho < smallest && numsqrwho > 0)
			smallest = numsqrwho;
		if(numwho < smallest && numwho > 0)
			smallest = numwho;
		if(densqrwho < smallest && densqrwho > 0)
			smallest = densqrwho;
		if(denwho < smallest && denwho > 0)
			smallest = denwho;
		int divisor = 1;
		for(int i = 2; i <= smallest; i++){
			if(numwho % i == 0 && denwho % i == 0 && numsqrwho % i == 0 && densqrwho % i == 0)
				divisor = i;
		}
		numbers[1] /= Math.pow(divisor, 2);
		numbers[2] /= divisor;
		numbers[3] /= Math.pow(divisor, 2);
		numbers[4] /= divisor;
	}
	
	public static int findsqr(int number){
		int result = 0;
		for(int i = 1; i <= Math.sqrt(number); i++){
			if(number % (Math.pow(i, 2)) == 0)
				result = i;
		}
		return result;
	}

}
