import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;


public class Q111 {

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		BigInteger sum = BigInteger.ZERO;
		ArrayList<int[]> indicatorpos = new ArrayList<int[]>();
		int[] indicator = new int[10];
		Arrays.fill(indicator, 1);
		for(int i = 0; i < 10; i++) {
			int[] add = indicator.clone();
			add[i] = 0;
			indicatorpos.add(add);
		}
		ArrayList<int[]> nonrepeatdig = new ArrayList<int[]>();
		int[] nonrepeat = new int[1];
		for(int i = 0; i < 10; i++) {
			int[] add = nonrepeat.clone();
			add[0] = i;
			nonrepeatdig.add(add);
		}
		ArrayList<Integer> digitleft = new ArrayList<Integer>();
		for(int i = 0; i < 10; i++)
			digitleft.add(i);
		while(!digitleft.isEmpty()) {
			ArrayList<Integer> removeDig = new ArrayList<Integer>();
			for(int each : digitleft) {
				ArrayList<int[]> nonrepeatdigit = excludeDigit(nonrepeatdig, each);
				BigInteger subsum = BigInteger.ZERO;
				for(int[] combi : indicatorpos) {
					for(int[] eachnonrepeat : nonrepeatdigit) {
						int[] digits = new int[10];
						int index = 0;
						for(int i = 0; i < 10; i++) {
							if(combi[i] == 1)
								digits[i] = each;
							else {
								digits[i] = eachnonrepeat[index];
								index++;
							}
						}
						if(digits[0] != 0) {
							String numberinl = "";
							for(int i = 0; i < 10; i++)
								numberinl += Integer.toString(digits[i]);
							BigInteger currentno = new BigInteger(numberinl);
							if(currentno.isProbablePrime(10))
								subsum = subsum.add(currentno);
						}
					}
				}
				if(subsum.compareTo(BigInteger.ZERO) != 0)
					removeDig.add(each);
				sum = sum.add(subsum);
			}
			for(Integer each : removeDig)
				digitleft.remove(each);
			indicatorpos = generateNextCombi(indicatorpos);
			nonrepeatdig = generateNextNonRepeat(nonrepeatdig);
		}
		long end = System.currentTimeMillis();
		System.out.println(sum);
		System.out.println((end - start) + " ms");
	}
	
	
	public static ArrayList<int[]> generateNextCombi(ArrayList<int[]> combi) {
		ArrayList<int[]> result = new ArrayList<int[]>();
		for(int[] each : combi) {
			int index = 0;
			for(int i = 9; i >= 0; i--) {
				if(each[i] == 0) {
					index = i+1;
					break;
				}
			}
			if(index < 10) {
				for(int i = index; i < 10; i++) {
					int[] add = each.clone();
					add[i] = 0;
					result.add(add);
				}
			}
		}
		return result;
	}
	
	public static ArrayList<int[]> generateNextNonRepeat(ArrayList<int[]> nonrepeat) {
		int newsize = nonrepeat.get(0).length + 1;
		ArrayList<int[]> result = new ArrayList<int[]>();
		for(int[] each : nonrepeat) {
			int[] add = new int[newsize];
			for(int i = 0; i < each.length; i++)
				add[i] = each[i];
			for(int i = 0; i < 10; i++) {
				int[] tobeadd = add.clone();
				tobeadd[newsize - 1] = i;
				result.add(tobeadd);
			}
		}
		return result;
	}
	
	public static ArrayList<int[]> excludeDigit(ArrayList<int[]> nonrepeat, int digit) {
		ArrayList<int[]> result = new ArrayList<int[]>();
		outerloop:
		for(int[] each : nonrepeat) {
			for(int i = 0; i < each.length; i++) {
				if(each[i] == digit)
					continue outerloop;
			}
			result.add(each);
		}
		return result;
	}

}
