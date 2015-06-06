import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q22 {

	public static void main(String[] args) throws Exception {
		Scanner reader = new Scanner(new File("/Users/zihaowang/Desktop/names.txt"));
		String txt = reader.nextLine();
		String[] splitted = txt.split(",");
		ArrayList<String> list = new ArrayList<String>(); 
		for (int i = 0; i < splitted.length; i++){
			list.add(splitted[i].substring(1, splitted[i].length()-1));
		}
		ArrayList<String> sortedlist = new ArrayList<String>();
		while (!list.isEmpty()){
			for (int i = 0; i < list.size()-1; i++){
				String str1 = list.get(i);
				String str2 = list.get(i+1);
				if (bubblesort(str1, str2)){
					list.set(i, str2);
					list.set(i+1, str1);
				}
			}
			String last = list.get(list.size()-1);
			sortedlist.add(0, last);
			list.remove(last);
		}
		long sum = 0;
		for (int i = 0; i < sortedlist.size(); i++){
			String name = sortedlist.get(i);
			long score = 0;
			for (int j = 0; j < name.length(); j++){
				score += name.charAt(j) - 64;
			}
			sum += score * (i+1);
		}
		System.out.println(sum);
	}
	
	public static boolean bubblesort(String str1, String str2){
		if (str1.length() != str2.length()){
			int length1 = str1.length();
			int length2 = str2.length();
			if (length1 > length2){
				boolean same = true;
				boolean change = false;
				for (int i = 0; i < length2; i++){
					if (str1.charAt(i) != str2.charAt(i)){
						same = false;
						change = str1.charAt(i) > str2.charAt(i);
						break;
					}
				}
				if (same)
					change = true;
				return change;
			}
			else{
				boolean change = false;
				for (int i = 0; i < length1; i++){
					if (str1.charAt(i) != str2.charAt(i)){
						change = str1.charAt(i) > str2.charAt(i);
						break;
					}
				}
				return change;
			}
		}
		else{
			boolean change = false;
			for (int i = 0; i < str1.length(); i++){
				if (str1.charAt(i) != str2.charAt(i)){
					if (str1.charAt(i) > str2.charAt(i))
						change = true;
					break;
				}
			}
			return change;
		}	
	}
}
