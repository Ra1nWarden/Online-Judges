import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Map;
import java.util.TreeMap;


public class Q103 {

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int[] set = {20, 31, 38, 39, 40, 42, 45};
		ArrayList<int[]> changes = new ArrayList<int[]>();
		int[] change = new int[7];
		Arrays.fill(change, 0);
		changes.add(change);
		for(int i = 0 ; i < 7; i++) {
			ArrayList<int[]> copy = (ArrayList<int[]>) changes.clone();
			for(int[] one : copy) {
				int[] cloned = one.clone();
				for(int j = 1; j < 7; j++) {
					int[] doublecloned = cloned.clone();
					doublecloned[i] = j;
					changes.add(doublecloned);
				}
			}
		}
		for(int[] one : changes) {
			int[] test = set.clone();
			for(int i = 0; i < 7; i++)
				test[i] += (one[i] - 3);
			if(rule1check(test) && rule2check(test)) {
				String printresult = "";
				for(int j = 0; j < test.length; j++)
					printresult += Integer.toString(test[j]);
				System.out.println(printresult);
				long end = System.currentTimeMillis();
				System.out.println(end - start + " ms");
				System.exit(0);
			}
		}
		

	}
	
	public static boolean rule1check(int[] arrays) {
		Map<String, Integer> mapofsum = new TreeMap<String, Integer>(); 
		for(int i = 1; i < Math.pow(2, arrays.length); i++) {
			String key = Integer.toBinaryString(i);
			int sum = 0;
			for(int j = 0; j < key.length(); j++) {
				if (key.charAt(j) == '1')
					sum += arrays[j + 7 - key.length()];
			}
			for(String each : mapofsum.keySet()) {
				if(mapofsum.get(each) == sum) {
					if((Integer.parseInt(each, 2) & Integer.parseInt(key, 2)) == 0)
						return false;
				}
			}
			mapofsum.put(key, sum);
		}
		return true;
	}
	
	public static boolean rule2check(int[] arrays) {
		ArrayList<Integer> listofno = new ArrayList<Integer>();
		for(int i = 0; i < arrays.length; i++)
			listofno.add(arrays[i]);
		Collections.sort(listofno);
		int sum1 = listofno.get(0);
		int sum2 = 0;
		for(int i = 0; i < listofno.size() / 2; i++) {
			sum1 += listofno.get(i+1);
			sum2 += listofno.get(listofno.size() - 1 - i);
			if(sum1 <= sum2)
				return false;
		}
		return true;
	}

}
