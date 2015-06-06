import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q18 {

	public static void main(String[] args) throws Exception{
		File text = new File("/Users/zihaowang/Desktop/numbers.txt");
		Scanner reader = new Scanner(text);
		ArrayList<ArrayList> triangle = new ArrayList<ArrayList>();
		while (reader.hasNextLine()){
			String line = reader.nextLine();
			String[] lineinstring = line.split(" ");
			ArrayList<Integer> lineinint = new ArrayList<Integer>();
			for (int i = 0 ; i < lineinstring.length ; i++){
				lineinint.add(Integer.parseInt(lineinstring[i]));
			}
			triangle.add(lineinint);
		}
		ArrayList<boolean[]> routes = new ArrayList<boolean[]>();
		boolean[] oneroute = new boolean[14];
		routes.add(oneroute);
		for (int i = 0; i < 14; i++){
			int size = routes.size();
			for (int j = 0; j < size; j++){
				boolean[] current = routes.get(j);
				boolean[] changed = current.clone();
				changed[i] = true;
				routes.add(changed);
			}
		}
		int max = 0;
		for (int j = 0; j < routes.size(); j++){
			int sum = 75;
			int index = 0;
			boolean[] currentroute = routes.get(j);
			for (int i = 0; i < 14; i++){
				if (currentroute[i])
					index++;
				int add = (Integer) triangle.get(i+1).get(index);
				sum += add;
			}
			if (sum > max)
				max = sum;
		}
		System.out.println(max);
	}

}
