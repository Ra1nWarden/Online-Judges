import java.io.File;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;


public class Q98 {

	public static void main(String[] args) throws Exception {
		long start = System.currentTimeMillis();
		Scanner reader = new Scanner(new File("/Users/zihaowang/Desktop/words.txt"));
		String[] rawline = reader.nextLine().split(",");
		String[] line = new String[rawline.length];
		for(int i = 0; i < rawline.length; i++)
			line[i] = rawline[i].substring(1, rawline[i].length()-1);
		boolean[] mark = new boolean[line.length];
		Arrays.fill(mark, true);
		ArrayList<ArrayList<String>> selected = new ArrayList<ArrayList<String>>();
		for (int i = 0; i < line.length; i++) {
			if (mark[i]) {
				String currentstr = line[i];
				mark[i] = false;
				ArrayList<String> group = new ArrayList<String>();
				group.add(currentstr);
				for (int j = i+1; j < line.length; j++) {
					String compare = line[j];
					if (checkchar(currentstr, compare)) {
						group.add(compare);
						mark[j] = false;
					} 
				}
				if (group.size() > 1)
					selected.add(group);
			}
		}
		Collections.sort(selected, new Comparator<ArrayList<String>>() {
			@Override
			public int compare(ArrayList<String> o1, ArrayList<String> o2) {
				int first = ((ArrayList<String>) o1).get(0).length();
				int second = ((ArrayList<String>) o2).get(0).length();
				return second - first;
			}
		});
		for (int i = 0; i < selected.size(); i++) {
			int square = findsquare(selected.get(i));
			if(square != 0) {
				long end = System.currentTimeMillis();
				System.out.println(square);
				System.out.println(end - start + " ms");
				break;
			}
		}

	}
	
	public static boolean checkchar(String first, String second) {
		if (first.length() == second.length()) {
			boolean[] mark = new boolean[second.length()];
			Arrays.fill(mark, true);
			boolean result = true;
			for (int i = 0; i < first.length(); i++) {
				char firstchar = first.charAt(i);
				boolean currentcheck = false;
				for (int j = 0; j < second.length(); j++) {
					if(mark[j]) {
						char secondchar = second.charAt(j);
						if (firstchar == secondchar) {
							mark[j] = false;
							currentcheck = true;
							break;
						}
					}
				}
				if (!currentcheck) {
					result = false;
					break;
				}
			}
			return result;
		}
		else
			return false;
	}
	
	public static int findsquare(ArrayList<String> words) {
		int length = words.get(0).length();
		int start = (int) (Math.ceil(Math.sqrt(Math.pow(10, length-1))));
		int end = (int) (Math.floor(Math.sqrt(Math.pow(10, length))));
		ArrayList<Integer> allsquares = new ArrayList<Integer>();
		for (int i = end; i >= start; i--)
			allsquares.add((int) Math.pow(i, 2));
		for (int i = 0; i < allsquares.size(); i++) {
			int currentsquare = allsquares.get(i);
			for (int j = 0; j < words.size(); j++) {
				String currentword = words.get(j);
				TreeMap<Character, Character> map = match(currentword, currentsquare);
				if (map != null) {
					outerloop:
					for (int k = 0; k < words.size(); k++) {
						if (k  != j) {
							String tobecompared = words.get(k);
							String converted = "";
							for (int l = 0; l < tobecompared.length(); l++) {
								if(l == 0) {
									char firstdigit = map.get(tobecompared.charAt(0));
									if (firstdigit == '0')
										continue outerloop;
								}
								converted += map.get(tobecompared.charAt(l));
							}
							int numberconverted = Integer.parseInt(converted);
							if (allsquares.contains(numberconverted))
								return currentsquare;
						}
					}
				}
			}
		}
		return 0;
	}
	
	public static TreeMap<Character, Character> match(String word, int number) {
		TreeMap<Character, Character> result = new TreeMap<Character, Character>();
		String numberinl = Integer.toString(number);
		for (int i = 0; i < word.length(); i++) {
			char wordchar = word.charAt(i);
			char numberchar = numberinl.charAt(i);
			if (result.containsKey(wordchar)) {
				if (result.get(wordchar) != numberchar)
					return null;
			}
			else
				result.put(wordchar, numberchar);
		}
		Set<Character> keyset = result.keySet();
		Set<Character> valueset = new TreeSet<Character>();
		for (Character one : keyset)
			valueset.add(result.get(one));
		if (keyset.size() != valueset.size())
			return null;
		else
			return result;
	}
	


}
