import java.util.ArrayList;
import java.util.Arrays;


public class Q49 {

	public static void main(String[] args) {
		boolean[] primestatus = new boolean[10000];
		Arrays.fill(primestatus, true);
		primestatus[0] = false;
		primestatus[9999] = false;
		int scanindex = 1;
		while (scanindex < 10000){
			if (primestatus[scanindex]){
				int diff = scanindex + 1;
				for (int j = 2; j * diff < 10000; j++)
					primestatus[j * diff-1] = false;
			}
			scanindex++;
		}
		ArrayList<Integer> prime = new ArrayList<Integer>();
		for (int i  = 0; i < 10000; i++){
			if(primestatus[i] && i+1 >= 1000)
				prime.add(i+1);
		}
		for (int i = 0; i < prime.size()-1; i ++){
			int currentprime = prime.get(i);
			for (int j = i+1; j< prime.size(); j++){
				int nextprime = prime.get(j);
				int diff = nextprime - currentprime;
				int third = nextprime + diff;
				if (diff % 2 == 0 && prime.contains(third)){
					if (check(currentprime,nextprime) && check(currentprime,third) && check(nextprime,third))
						System.out.println(currentprime + " " + nextprime + " " + third);
				}
					
			}
		}
	}
	
	public static boolean check(int first, int second){
		String firstinl = Integer.toString(first);
		String secondinl = Integer.toString(second);
		boolean status = true;
		for (int i  = 0; i < 4; i++){
			if (secondinl.indexOf((int) firstinl.charAt(i)) == -1 ){
				status = false;
				break;
			}
		}
		if(status){
			for (int i  = 0; i < 4; i++){
				if (firstinl.indexOf((int) secondinl.charAt(i)) == -1 ){
					status = false;
					break;
				}
			}
		}
		return status;
	}

}
