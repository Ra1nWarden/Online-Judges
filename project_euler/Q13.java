import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q13 {


	public static void main(String[] args) throws Exception{
		File txt = new File("/Users/zihaowang/Desktop/numbers.txt");
		Scanner reader = new Scanner(txt);
		ArrayList<String> numbers = new ArrayList<String>();
		while(reader.hasNextLine()){
			String line = reader.nextLine();
			numbers.add(line);
		}
		String totalsum = "";
		int forward = 0;
		for (int i = 49; i >= 0; i--){
			int sum = 0;
			for (int j = 0; j < 100; j++){
				String singlenumber = numbers.get(j);
				int digit = Integer.parseInt(singlenumber.substring(i, i+1));
				sum += digit;
			}
			sum += forward;
			int printdigit = sum % 10;
			totalsum = Integer.toString(printdigit) + totalsum;
			forward = sum / 10;
			if (i == 0){
				totalsum = Integer.toString(forward) + totalsum;
				System.out.println(totalsum);
				System.out.println(totalsum.substring(0,10));
				System.exit(0);
			}
		}
	}

}
