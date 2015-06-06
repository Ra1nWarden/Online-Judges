import java.util.ArrayList;


public class Q5 {

	public static void main(String[] args) {
		ArrayList<Integer> listofno = new ArrayList<Integer>();
		for (int i = 1; i <= 20; i++){
			listofno.add(i);
		}
		long finalresult = 1;
		for (int one : listofno){
			finalresult = Findscm(finalresult, one);
		}
		System.out.println(finalresult);
	}

	public static long Findlcd(long n1, long n2){
		long smaller, larger;
		if (n1 > n2){
			smaller = n2;
			larger = n1;
		}
		else{
			smaller = n1;
			larger = n2;
		}
		long result = 1;
		for (int i = 1; i <= smaller; i++){
			if (larger % i == 0 && smaller % i == 0)
				result = i;
		}
		return result;
	}
	
	public static long Findscm(long n1, long n2){
		return ((n1 * n2) / (Findlcd(n1, n2)));
	}
}
