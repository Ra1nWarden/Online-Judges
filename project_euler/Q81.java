import java.io.File;
import java.util.Scanner;


public class Q81 {

	public static void main(String[] args) throws Exception {
		File txt = new File("/Users/zihaowang/Desktop/matrix.txt");
		Scanner reader = new Scanner(txt);
		int[][] map = new int[80][80];
		int row = 0;
		while(reader.hasNext()){
			String[] currentline = reader.nextLine().split(",");
			for(int i = 0; i < 80; i++){
				map[row][i] = Integer.parseInt(currentline[i]);
			}
			row++;
		}
		for(int i = 79; i >= 0; i--){
			for(int j = 79; j >= 0; j--){
				if (j+1 < 80 && i+1 < 80)
					map[i][j] += smaller(map[i][j+1], map[i+1][j]);
				else if(j+1 == 80 && i+1 < 80)
					map[i][j] += map[i+1][j];
				else if(j+1 < 80 && i+1 == 80)
					map[i][j] += map[i][j+1];
			}
		}
		System.out.println(map[0][0]);

	}
	
	public static int smaller(int one, int two){
		if(one > two)
			return two;
		else
			return one;
	}

}
