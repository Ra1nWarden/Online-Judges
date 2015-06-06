import java.io.File;
import java.util.Scanner;


public class Q102 {
	
	public static void main(String[] args) throws Exception {
		Scanner reader = new Scanner(new File("/Users/zihaowang/Desktop/triangles.txt"));
		int count = 0;
		while(reader.hasNext()) {
			String[] line = reader.nextLine().split(",");
			int[] numbers = new int[6];
			for(int i = 0; i < 6; i++)
				numbers[i] = Integer.parseInt(line[i]);
			if(check(numbers))
				count++;
		}
		System.out.println(count);
	}
	
	// This method of finding squares could be found at : http://en.wikipedia.org/wiki/Triangle#Using_coordinates
	public static double square(int[] coords) {
		double first = (coords[0] - coords[4]) * (coords[3] - coords[1]);
		double second = (coords[0] - coords[2]) * (coords[5] - coords[1]);
		return 0.5 * Math.abs(first - second);
	}
	
	public static boolean check(int[] coords) {
		int[] first = coords.clone();
		first[0] = 0;
		first[1] = 0;
		double firstarea = square(first);
		int[] second = coords.clone();
		second[2] = 0;
		second[3] = 0;
		double secondarea = square(second);
		int[] third = coords.clone();
		third[4] = 0;
		third[5] = 0;
		double thirdarea = square(third);
		double total = square(coords);
		return total == (firstarea + secondarea + thirdarea);
	}

}
