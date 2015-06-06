import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q67 {


	public static void main (String[] args) throws Exception{
		File txt = new File("/Users/zihaowang/Desktop/triangle.txt");
		Scanner reader = new Scanner(txt);
		ArrayList<String[]> numbers = new ArrayList<String[]>();
		while(reader.hasNext())
			numbers.add(reader.nextLine().split(" "));
		int size = numbers.size();
		String[] lastline = numbers.get(size-1);
		String[] secondlast = numbers.get(size-2);
		String[] ans = calculate(lastline, secondlast);
		for(int i = size - 3; i >= 0; i--){
			String[] currenttop = numbers.get(i);
			ans = calculate(ans, currenttop);
		}
		System.out.println(ans[0]);
	}
	
	public static String[] calculate(String[] bottom, String[] top){
		String[] result = new String[top.length];
		for(int i = 0; i < top.length; i++){
			int topint = Integer.parseInt(top[i]);
			int botint1 = Integer.parseInt(bottom[i]);
			int botint2 = Integer.parseInt(bottom[i+1]);
			int sum1 = topint + botint1;
			int sum2 = topint + botint2;
			if(sum1 > sum2)
				result[i] = Integer.toString(sum1);
			else
				result[i] = Integer.toString(sum2);
		}
		return result;
	}

}
