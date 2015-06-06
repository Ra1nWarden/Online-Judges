import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q96 {

	private static final Exception Exception = null;
	private static int totalsum;

	public static void main(String[] args) throws Exception {
		long start = System.currentTimeMillis();
		Scanner reader = new Scanner(new File("/Users/zihaowang/Desktop/sudoku.txt"));
		ArrayList<int[][]> allpuzzles = new ArrayList<int[][]>();
		totalsum = 0;
		while(reader.hasNextLine()) {
			reader.nextLine();
			int[][] currentpuzzle = new int[9][9];
			for (int i = 0; i < 9; i++) {
				String currentline = reader.nextLine();
				for (int j = 0; j < 9; j++)
					currentpuzzle[i][j] = Integer.parseInt(currentline.substring(j, j+1));
			}
			allpuzzles.add(currentpuzzle);
		}
		for (int i = 0; i < allpuzzles.size(); i++) {
			int[][] one = allpuzzles.get(i);
			Sudoku currentpuzzle = new Sudoku(one);
			currentpuzzle.findpossibilities();
			try {
				solve(currentpuzzle.getUnsolved(), currentpuzzle);
			}
			catch (Exception e) {
				continue;
			}
		}
		long end = System.currentTimeMillis();
		System.out.println(totalsum);
		System.out.println(end - start + " ms");
	}
	
	public static void solve(ArrayList<SudokuGrid> unsolved, Sudoku puzzle) throws Exception {
		if (unsolved.size() != 0) {
			SudokuGrid target = null;
			int minsize = Integer.MAX_VALUE;
			for (SudokuGrid one : unsolved) {
				if (one.getPossibilities().size() < minsize) {
					minsize = one.getPossibilities().size();
					target = one;
				}
			}
			for (int i = 0; i < target.getPossibilities().size(); i++) {
				int testvalue = target.getPossibilities().get(i);
				Sudoku newpuzzle = puzzle.clone();
				newpuzzle.set(testvalue, target);
				if(newpuzzle.check()) {
					ArrayList<SudokuGrid> newunsolved = new ArrayList<SudokuGrid>();
					for (SudokuGrid one : newpuzzle.getUnsolved()) {
						if (!one.equals(target))
							newunsolved.add(one);
					}
					solve(newunsolved, newpuzzle);
				}
			}
		}
		else {
			if (puzzle.validcheck()) {
				System.out.println(puzzle.toString());
				System.out.println(puzzle.getThree());
				totalsum += puzzle.getThree();
				throw Exception;
			}
		}
	}

}
