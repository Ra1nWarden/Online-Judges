import java.math.BigInteger;
import java.util.ArrayList;


public class Q43 {

	public static void main(String[] args) {
		ArrayList<String> lastthree = new ArrayList<String>();
		for (int i = 100; i < 1000; i++){
			if (testpand(i) && i % 17 == 0)
				lastthree.add(Integer.toString(i));
		}	
		nextlevel(lastthree, 13);
		nextlevel(lastthree, 11);
		nextlevel(lastthree, 7);
		nextlevel(lastthree, 5);
		nextlevel(lastthree, 3);
		nextlevel(lastthree, 2);
	
		ArrayList<String> result = new ArrayList<String>();
		for (String one : lastthree){
			boolean status = true;
			boolean[] index = new boolean[10];
			for (int i = 0; i < 9; i++){
				char single = one.charAt(i);
				if (!index[single-48])
					index[single-48] = true;
				else{
					status =false;
					break;
				}
			}
			if (status){
				String first = "";
				for (int j = 0; j < index.length; j++){
					if (!index[j]){
						first = Integer.toString(j);
						break;
					}
				}
				result.add(first+one);
			}
		}
		BigInteger sum = new BigInteger("0");
		for (String one : result){
			BigInteger tobeadd = new BigInteger(one);
			sum = sum.add(tobeadd);
		}
		System.out.println(sum);
	}
	
	public static boolean testpand(int number){
		String numberinl = Integer.toString(number);
		return (!(numberinl.charAt(0) == numberinl.charAt(1) || numberinl.charAt(0) == numberinl.charAt(2) || numberinl.charAt(1) == numberinl.charAt(2)));
	}
	
	public static void nextlevel(ArrayList<String> list, int divisor){
		int size = list.size();
		for (int i = 0; i < size; i++){
			String current = list.get(i).substring(0, 2);
			for (int j = 0; j < 10; j++){
				int number = j * 100 + Integer.parseInt(current);
				if (number % divisor == 0)
					list.add(Integer.toString(j) + current  + list.get(i).substring(2));
			}
		}
		for (int i = 0; i < size; i++){
			list.remove(0);
		}
	}
}
