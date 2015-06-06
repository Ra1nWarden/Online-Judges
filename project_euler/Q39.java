import java.util.ArrayList;


public class Q39 {

	public static void main(String[] args) {
		ArrayList<Double> pairs = new ArrayList<Double>();
		for (int i = 2; i <= 1000; i+=2){
			double amount = 0;
			for (int j = 1; j < i; j++){
				if((Math.pow(i, 2) - 2*i*j) % 2 == 0)
					amount += pair(i-j, (Math.pow(i, 2) - 2*i*j) / 2);
			}
			pairs.add(amount);
		}
		double max = 0;
		int maxindex = 0;
		for (int i = 0; i < pairs.size(); i++){
			if (pairs.get(i) > max){
				max = pairs.get(i);
				maxindex = i;
			}
		}
		System.out.println((maxindex+1)*2);
	}
	
	public static double pair(int sum, double product){
		int count = 0;
		for (int i  = 1; i <= sum/2; i++){
			int one = i;
			int two = sum - i;
			if (one * two == product)
				count++;
		}
		return count;
	} 

}
