import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q83 {

//	I give up on the dynamic programming algorithm. My thoughts are as follows:
//	1. Similar to the previous problems, start from the end (the bottom right number).
//	2. To find the minimum sum, calculate diagonal by diagonal.
//  3. Start with map[79][79] and the diagonal map[79][78], map[78][79]
//  4. Find the smallest sum from each point on the second last diagonal to any points on the last diagonal. 
//	(PROBLEM: IMPOSSIBLE TO FIND!Since there are too many options.)
//  5. Update the second last diagonal and run through the whole map to get the result at map[0][0]
//	public static void main(String[] args) throws Exception {
//		File txt = new File("/Users/zihaowang/Desktop/matrix.txt");
//		Scanner reader = new Scanner(txt);
//		int[][] map = new int[80][80];
//		int row = 0;
//		while(reader.hasNext()){
//			String[] currentline = reader.nextLine().split(",");
//			for(int i = 0; i < 80; i++){
//				map[row][i] = Integer.parseInt(currentline[i]);
//			}
//			row++;
//		}
//	}
//	
//	public static void calculate(int[] secdiag, int[] lastdiag) {
//		for(int i = 0; i < secdiag.length; i++) {
//			int minsum = Integer.MAX_VALUE;
//			for(int j = 0; j < lastdiag.length; j++) {
//				
//			}
//		}
//	}
	
	/*The following method implements A* algorithm. I think it is very helpful and powerful.
	 * Find out more at:
	 * http://www.policyalmanac.org/games/aStarTutorial.htm
	 */
	
	public static void main(String[] args) throws Exception {
		File txt = new File("/Users/zihaowang/Desktop/matrix.txt");
		Scanner reader = new Scanner(txt);
		Grid[][] map = new Grid[80][80];
		int[][] valmap = new int[80][80];
		int row = 0;
		int minval = Integer.MAX_VALUE;
		while(reader.hasNext()) {
			String[] currentline = reader.nextLine().split(",");
			for(int i = 0; i < 80; i++) {
				int currentint = Integer.parseInt(currentline[i]);
				valmap[row][i] = currentint;
				map[row][i] = new Grid(currentint, row, i);
				// NEVER underestimate the distance away from the current point to the final goal.
				// Hence, the minimum value from the gird is used.
				if (currentint < minval)
					minval = currentint;
			}
			row++;
		}
		for(int i = 0; i < 80; i++) {
			for(int j = 0; j < 80; j++){
				map[i][j].setDistanceaway(minval * (159 - i - j));
				map[i][j].setTotalvalue(map[i][j].getDistanceaway() + map[i][j].getMovementcost());
			}
		}
		ArrayList<Grid> closedlist = new ArrayList<Grid>();
		ArrayList<Grid> openlist = new ArrayList<Grid>();
		openlist.add(map[0][0]);
		Grid currentgrid = map[0][0];
		while (!closedlist.contains(map[79][79])) {
			openlist.remove(currentgrid);
			closedlist.add(currentgrid);
			ArrayList<Grid> neighbour = new ArrayList<Grid>();
			int currow = currentgrid.getRow();
			int curcol = currentgrid.getCol();
			if (currow + 1 < 80)
				neighbour.add(map[currow+1][curcol]);
			if (currow - 1 >= 0)
				neighbour.add(map[currow-1][curcol]);
			if (curcol + 1 < 80)
				neighbour.add(map[currow][curcol+1]);
			if (curcol - 1 >= 0)
				neighbour.add(map[currow][curcol-1]);
			for (Grid one : neighbour) {
				if (closedlist.contains(one))
					continue;
				else if (!openlist.contains(one)) {
					one.setParent(currentgrid);
					openlist.add(one);
				}
				else if (openlist.contains(one)) {
					if (one.getMovementcost() > currentgrid.getMovementcost() + valmap[one.getRow()][one.getCol()])
						one.setParent(currentgrid);
				}
			}	
			int next = Integer.MAX_VALUE;
			for(Grid one : openlist) {
				if (one.getTotalvalue() < next) {
					next = one.getTotalvalue();
					currentgrid = one;
				}
			}
		}
		int totalsum = 0;
		totalsum += valmap[79][79];
		Grid path = map[79][79];
		while (!(path.getRow() == 0  && path.getCol() == 0)) {
			path = path.getParent();
			totalsum += valmap[path.getRow()][path.getCol()];
			System.out.println(path.getRow() + " " + path.getCol());
		}
		System.out.println(totalsum);
	}
}
