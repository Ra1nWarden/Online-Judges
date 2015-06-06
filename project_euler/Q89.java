import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q89 {
	
	private static ArrayList<Character> orderlist = new ArrayList<Character>();
	private static ArrayList<Integer> valuelist = new ArrayList<Integer>();
	
	public Q89() {
		orderlist.add('I');
		orderlist.add('V');
		orderlist.add('X');
		orderlist.add('L');
		orderlist.add('C');
		orderlist.add('D');
		orderlist.add('M');
		
		valuelist.add(1);
		valuelist.add(5);
		valuelist.add(10);
		valuelist.add(50);
		valuelist.add(100);
		valuelist.add(500);
		valuelist.add(1000);
		
	}
	
	public static void main(String args[]) throws Exception {
		long starttime = System.currentTimeMillis();
		Q89 start = new Q89();
		Scanner reader = new Scanner(new File("/Users/zihaowang/Desktop/roman.txt"));
		ArrayList<Integer> converted = new ArrayList<Integer>();
		int originallength = 0;
		while (reader.hasNext()) {
			String line = reader.nextLine();
			originallength += line.length();
			converted.add(calculate(line));
		}
		System.out.println(converted);
		ArrayList<String> convertedRom = new ArrayList<String>();
		int finallength = 0;
		for (int one : converted) {
			convertedRom.add(convert(one));
			finallength += convert(one).length();
		}
		long end = System.currentTimeMillis();
		System.out.println(convertedRom);
		System.out.println(originallength - finallength);
		System.out.println(end - starttime + "ms");
	}

	public static boolean checkorder(char first, char second) {
		return (orderlist.indexOf(first) >= orderlist.indexOf(second));
	}
	
	public static int calculate(String line) {
		int sum = 0;
		for(int i = 0; i < line.length(); i++) {
			int index = orderlist.indexOf(line.charAt(i));
			if (i == line.length() - 1)
				sum += valuelist.get(index);
			else if (checkorder(line.charAt(i), line.charAt(i+1))) 
				sum += valuelist.get(index);
			else {
				int number = valuelist.get(index+1) - valuelist.get(index);
				sum += number;
				i++;
			}
		}
		return sum;
		
	}
	
	public static String convert(int number) {
		int power = 0;
		ArrayList<Integer> digit = new ArrayList<Integer>();
		String ans = "";
		while (number != 0) {
			digit.add(number % 10);
			number = number / 10;
		}
		for (int i = 0; i < digit.size(); i++) {
			int currentdig = digit.get(i);
			if (i == 3){
				for (int j= 0; j < currentdig; j++) {
					ans = 'M' + ans;
				}
			}
			else {
				if (currentdig == 0)
					continue;
				else if (currentdig == 4) {
					ans = orderlist.get(2 * i + 1) + ans;
					ans = orderlist.get(2 * i) + ans;
				}
				else if (currentdig < 5) {
					for (int j = 0 ; j < currentdig; j++) {
						ans = orderlist.get(2 * 1) + ans;
					} 
				}
				else if (currentdig < 9) {
					ans = orderlist.get(2 * i + 1) + ans;
					for(int j= 0; j < currentdig - 5; j++){
						ans = orderlist.get(2 * i) + ans;
					}
				}
				else if (currentdig == 9) {
					ans = orderlist.get(2 * (i+1)) + ans; 
					ans = orderlist.get(2 * i) + ans;
				}
			}
		}
		return ans;
	}
	
}
