import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Q42 {

	public static void main(String[] args) throws Exception {
		File txt = new File("/Users/zihaowang/Desktop/words.txt");
		Scanner reader = new Scanner(txt);
		String line = reader.nextLine();
		ArrayList<String> names = new ArrayList<String>();
		String[] splitted = line.split(",");
		for (int i = 0; i < splitted.length; i++)
			names.add(splitted[i].substring(1, splitted[i].length()-1));
		int count = 0;
		for (String one : names){
			int value = 0;
			for (int i = 0; i < one.length(); i++)
				value += one.charAt(i) - 64;
			if (test(value))
				count++;
		}
		System.out.println(count);
	}
	
	public static boolean test(int number){
		int half = (int) Math.sqrt(2*number);
		return (half * (half+1) == 2*number);
	}
}
