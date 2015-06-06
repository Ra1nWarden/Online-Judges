import java.math.BigInteger;
import java.util.ArrayList;


public class Q66 {


	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 2; i <= 1000; i++){
			if(Math.sqrt(i) == (int) Math.sqrt(i))
				continue;
			else
				list.add(i);
		}
		BigInteger max = BigInteger.ZERO;
		int maxindex = 0;
		for(int i = 0; i < list.size(); i++){
			int currentint = list.get(i);
			int wholenumber = (int) Math.sqrt(currentint);
			ArrayList<Integer> sequence = new ArrayList<Integer>();
			findperiod(currentint, -wholenumber, 0, 1, sequence);
			BigInteger resultnum = result(sequence, wholenumber, currentint);
			if(resultnum.compareTo(max) == 1){
				max = resultnum;
				maxindex = i;
			}
		}
		System.out.println(list.get(maxindex));

	}
	
	public static BigInteger result(ArrayList<Integer> list, int wholenumber, int factor){
		BigInteger factorb = new BigInteger(Integer.toString(factor));
		BigInteger[] pair = new BigInteger[2];
		pair[0] = new BigInteger(Integer.toString(wholenumber));
		pair[1] = BigInteger.ONE;
		BigInteger[] nextpair= new BigInteger[2];
		BigInteger firstmultiply = new BigInteger(Integer.toString(list.get(0)));
		nextpair[0] = pair[0].multiply(firstmultiply).add(BigInteger.ONE);
		nextpair[1] = pair[1].multiply(firstmultiply);
		int factorcount = 1;
		int length = list.size();
		while(!nextpair[0].pow(2).subtract(nextpair[1].pow(2).multiply(factorb)).equals(BigInteger.ONE)){
			int index = factorcount % length;
			BigInteger multiply = new BigInteger(Integer.toString(list.get(index)));
			BigInteger[] third = new BigInteger[2];
			third[0] = nextpair[0].multiply(multiply).add(pair[0]);
			third[1] = nextpair[1].multiply(multiply).add(pair[1]);
			pair = nextpair;
			nextpair = third;
			factorcount++;
		}
		return nextpair[0];
	}
	
//	public static BigInteger[] next(int ith, ArrayList<Integer> list, int wholenumber){
//		BigInteger[] result = new BigInteger[2];
//		int length = list.size();
//		if(ith == 0){
//			result[1] = BigInteger.ONE;
//			result[0] = new BigInteger(Integer.toString(wholenumber));
//			return result;
//		}
//		else if(ith == 1){
//			BigInteger factor = new BigInteger(Integer.toString(list.get(0)));
//			result[0] = next(0, list, wholenumber)[0].multiply(factor).add(BigInteger.ONE);
//			result[1] = next(0, list, wholenumber)[1].multiply(factor);
//			return result;
//		}
//		else{
//			int remainder = (ith - 1) % length;
//			BigInteger factor = new BigInteger(Integer.toString(list.get(remainder)));
//			result[0] = next(ith-1, list, wholenumber)[0].multiply(factor).add(next(ith-2, list, wholenumber)[0]);
//			result[1] = next(ith-1, list, wholenumber)[1].multiply(factor).add(next(ith-2, list, wholenumber)[1]);
//			return result;
//		}
//	}
	
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
	
	public static void findperiod(int a, int b, int c, int d, ArrayList<Integer> list){
		int[] firstresult = findnext(a, b, c, d);
		list.add(firstresult[0]);
		int[] start = firstresult.clone();
		while(true){
			int[] nextresult = findnext(start[1], start[2], start[3], start[4]);
			if(checkequal(firstresult,nextresult))
				break;
			else{
				list.add(nextresult[0]);
				start = nextresult;
			}
		}
	
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
	
}
