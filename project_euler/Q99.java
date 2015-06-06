import java.io.File;
import java.util.Scanner;



public class Q99 {

	public static void main(String[] args) throws Exception {
		Scanner reader = new Scanner(new File("/Users/zihaowang/Desktop/base_exp.txt"));
		int line = 1;
		double max = Double.MIN_VALUE;
		int maxline = 0;
		while(reader.hasNext()) {
			String[] currentline = reader.nextLine().split(",");
			int base = Integer.parseInt(currentline[0]);
			int exp = Integer.parseInt(currentline[1]);
			double result = calc(base, exp);
			if (result > max) {
				max = result;
				maxline = line;
			}
			line++;
		}
		System.out.println(maxline);
	}
	
	public static double calc(int base, int exp) {
		return exp * Math.log10(base);
	}

}
