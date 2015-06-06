import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q8 {

	
	public static void main(String[] args) throws Exception {
		File text = new File("/Users/zihaowang/Desktop/text.txt");
		Scanner filereader = new Scanner(text);
		String number = filereader.nextLine();
		ArrayList<Integer> digit = new ArrayList<Integer>();
		for (int i = 0; i < 1000; i++){
			String singledigit = number.substring(i, i+1);
			digit.add(Integer.parseInt(singledigit));
		}
		int result = 1;
		for (int i = 0; i < digit.size() - 5; i++){
			int product = digit.get(i) * digit.get(i+1) * digit.get(i+2) * digit.get(i+3) * digit.get(i+4);
			if (product > result)
				result = product;
		}
		System.out.println(result);
	}

}
