import java.util.ArrayList;


public class Q47 {

	public static void main(String[] args) {
		for (double i = 16; i > 0; i++){
			if (noofprimefac(i) == 4 && noofprimefac(i+1) == 4 && noofprimefac(i+2) == 4 && noofprimefac(i+3) == 4){
				System.out.println(i);
				System.exit(0);
			}
		}
	}
	
	public static int noofprimefac(double number){
		ArrayList<Double> primefact = new ArrayList<Double>();
		while (number != 1){
			for (double i = 2; i <= Math.sqrt(number) || i ==2; i++){
				if (number % i == 0){
					if (!primefact.contains(i))
						primefact.add(i);
					number = number / i;
					break;
				}
				if (Math.sqrt(number) - i < 1 && number % i != 0){
					if (!primefact.contains(number))
						primefact.add(number);
					number = 1;
				}
			}
		}
		return primefact.size();
	}

}
