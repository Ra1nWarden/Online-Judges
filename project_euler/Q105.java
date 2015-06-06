import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;


public class Q105 {

	
	public static void main(String[] args) throws Exception {
		Scanner reader = new Scanner(new File("Sets.txt"));
		int sum = 0;
		while(reader.hasNextLine()) {
			String[] line = reader.nextLine().split(",");
			int[] array = new int[line.length];
			for(int i = 0; i < line.length; i++)
				array[i] = Integer.parseInt(line[i]);
			if(rule1check(array) && rule2check(array)) {
				int addsum = 0;
				for(int j = 0; j < array.length; j++) {
					addsum += array[j];
					System.out.print(array[j] + " ");
				}
				System.out.println(addsum);
				sum += addsum;
					
			}
		}
		System.out.println(sum);
	}
	
	public static boolean rule1check(int[] arrays) {
		Map<String, Integer> mapofsum = new TreeMap<String, Integer>(); 
		for(int i = 1; i < Math.pow(2, arrays.length); i++) {
			String key = Integer.toBinaryString(i);
			key = generate(key, arrays.length);
			int sum = 0;
			for(int j = 0; j < key.length(); j++) {
				if (key.charAt(j) == '1')
					sum += arrays[j];
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
	
	public static String generate(String str, int length) {
		while(str.length() < length)
			str = "0" + str;
		return str;
	
	}

}
