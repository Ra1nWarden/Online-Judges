import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q79 {

	public static void main(String[] args) throws Exception {
		File txt = new File("/Users/zihaowang/Desktop/keylog.txt");
		Scanner reader = new Scanner(txt);
		ArrayList<Integer> list = new ArrayList<Integer>();
		while(reader.hasNextLine()){
			int number = Integer.parseInt(reader.nextLine());
			if(!list.contains(number)){
				list.add(number);
				System.out.println(number);
			}
		}

	}
	// This problem could be solved by hand. However, some of the most significant properties are listed below:
	// Firstly, there is a ALGORITHM to solve this if all digits are unique and enough combinations are gathered. Check out http://projecteuler.net/thread=79
	// Basically, it is saying that in the array of three digit numbers, the first digit of the passcode never appears on the second digit.
	// All digits that are in the passcode are in the array.
	// After finding out the rejection list(all second digits in the array of numbers)
	// Go through the list again for the first digit, if the digit is not in the rejection list, it could be the first digit. 
	// After finding out the first digit, remove this digit from all numbers in the array.
	// Repeat this process until the digit list is empty.

}
