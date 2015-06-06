import java.io.File;
import java.util.Scanner;


public class Q11 {

	
	public static void main(String[] args) throws Exception{
		File txt = new File("/Users/zihaowang/Desktop/numbers.txt");
		Scanner reader = new Scanner(txt);
		int map[][] = new int[20][20];
		for (int i = 0; i < 20; i++){
			String line = reader.nextLine();
			String sep[] = line.split(" ");
			for (int j = 0; j < 20; j++){
				map[i][j] = Integer.parseInt(sep[j]);
			}
		}
		int max = 0;
		for (int i = 0; i < 20; i++){
			for (int j = 0; j < 17; j++){
				int product = map[i][j] * map[i][j+1] * map[i][j+2] * map[i][j+3];
				if (product > max)
					max = product;
			}
		}
		for (int j = 0; j < 20; j++){
			for (int i = 0; i < 17; i++){
				int product = map[i][j] * map[i+1][j] * map[i+2][j] * map[i+3][j];
				if (product > max)
					max = product;
			}
		}
		for (int i = 0; i < 17; i++){
			for (int j = 0; j < 17; j++){
				int product = map[i][j] * map[i+1][j+1] * map[i+2][j+2] * map[i+3][j+3];
				if (product > max)
					max = product;
			}
		}
		for (int i = 0; i < 17; i++){
			for (int j = 3; j < 20; j++){
				int product = map[i][j] * map[i+1][j-1] * map[i+2][j-2] * map[i+3][j-3];
				if (product > max)
					max = product;
			}
		}
		System.out.println(max);
	}

}
