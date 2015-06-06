import java.util.ArrayList;
import java.util.Arrays;


public class Q50 {

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
			if(primestatus[i])
				prime.add(i+1);
		}
		int maxlength = 21;
		int maxvalue = 953;
		int testlength = 22;
		int testsum = 0;
		while(testsum < 1000000){
			for (int i = 0; i < prime.size()-testlength; i++){
				int sum = 0;
				for (int j = 0; j < testlength; j++)
					sum += prime.get(i+j);
				if (sum >= 1000000)
					break;
				else if (prime.contains(sum)){
					maxlength = testlength;
					maxvalue = sum;
				}
			}
			testlength++;
			testsum = 0;
			for (int i  = 0; i < testlength; i++){
				testsum += prime.get(i);
			}
		}
		System.out.println(maxlength);
		System.out.println(maxvalue);
	}

}
