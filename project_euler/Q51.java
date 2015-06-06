import java.util.ArrayList;
import java.util.Arrays;


public class Q51 {

	public static void main(String[] args) {
		boolean[] primestatus = new boolean[1000000];
		Arrays.fill(primestatus, true);
		primestatus[0] = false;
		primestatus[999999] = false;
		int scanindex = 1;
		while (scanindex < 1000000){
			if (primestatus[scanindex]){
				int diff = scanindex + 1;
				for (int j = 2; j * diff < 1000000; j++)
					primestatus[j * diff-1] = false;
			}
			scanindex++;
		}
		ArrayList<Integer> prime = new ArrayList<Integer>();
		for (int i  = 0; i < 1000000; i++){
			if(primestatus[i] && i+1 > 9999)
				prime.add(i+1);
		}
		boolean found = false;
		for (int i = 0; i < prime.size(); i++){
			int currentprime = prime.get(i);
			if (count(currentprime, 0) == 3)
				found = replace(currentprime, 0, prime);
			else if (count(currentprime, 1) == 3)
				found = replace(currentprime, 1, prime);
			else if (count(currentprime, 2) == 3)
				found = replace(currentprime, 2, prime);
			if (found){
				System.out.println(currentprime);
				System.exit(0);
			}
		}
		
	}
	
	public static boolean replace(int number, int digit, ArrayList<Integer> primelist){
		String numberinl = Integer.toString(number);
		char character = (char) (digit + 48);
		int index1 = numberinl.indexOf(character);
		int index2 = numberinl.indexOf(character, index1+1);
		int index3 = numberinl.indexOf(character, index2+1);
		int error = 2 - digit;
		int currenterror = 0;
		for (int i = digit+1; i < 10; i++){
			String changed = numberinl.substring(0, index1) + Integer.toString(i) + numberinl.substring(index1+1, index2) + Integer.toString(i) + numberinl.substring(index2+1, index3) + Integer.toString(i) +numberinl.substring(index3+1);
			if (!primelist.contains(Integer.parseInt(changed)))
				currenterror++;
			if (currenterror > error)
				break;
		}
		return (!(currenterror > error));
	}
	
	public static int count(int number, int digit){
		String numberinl = Integer.toString(number);
		int count = 0;
		for (int i = 0; i < numberinl.length(); i++){
			if (Integer.parseInt(numberinl.substring(i, i+1)) == digit)
				count++;
		}
		return count;
	}

}
