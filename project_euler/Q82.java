import java.io.File;
import java.util.Scanner;


public class Q82 {

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
		
		int[][] converted = new int[80][80];
		for(int i = 0; i < 80; i++){
			converted[i] = convert(map, i);
		}
		
		for(int i = 78; i >=0; i--){
			calculate(converted[i], converted[i+1]);
		}
		
		int finalresult = Integer.MAX_VALUE;
		for(int i = 0; i < 80; i++){
			if(converted[0][i] < finalresult)
				finalresult = converted[0][i];
		}
		System.out.println(finalresult);
	}
	
	public static int[] convert(int[][] map, int col){
		int[] result = new int[80];
		for(int i = 0; i < 80; i++){
			result[i] = map[i][col]; 
		}
		return result;
	}
	
	public static void calculate(int[] secondlastcol, int[] lastcol){
		int[] tobeadded = new int[80];
		for(int i = 0; i < 80; i++){
			int minvalue = Integer.MAX_VALUE;
			for(int j = 0; j < 80; j++){
				int sum = 0;
				if(j > i){
					for(int k = i+1; k <= j; k++){
						sum += secondlastcol[k];
					}
					sum += lastcol[j];
				}
				else if (j == i)
					sum += lastcol[j];
				else{
					for(int k = i-1; k >= j; k--){
						sum += secondlastcol[k];
					}
					sum += lastcol[j];
				}
				if (sum < minvalue)
					minvalue = sum;
			}
			tobeadded[i] = minvalue;
		}
		for(int i = 0; i < 80; i++)
			secondlastcol[i] += tobeadded[i];
	}

}
