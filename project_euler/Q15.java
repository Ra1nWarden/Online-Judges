
public class Q15 {

	public static void main(String[] args) {
		long map[][] = new long[21][21];
		for (int i = 0; i < 21; i++){
			map[0][i] = 1;
			map[i][0] = 1;
		}
		for (int i = 1; i < 21; i++){
			for (int j = 1; j < 21; j++){
				map[i][j] = map[i-1][j] + map[i][j-1];
			}
		}
		System.out.println(map[20][20]);

	}

}
