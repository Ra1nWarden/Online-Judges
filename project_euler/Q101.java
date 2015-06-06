import java.util.ArrayList;
import java.util.List;

public class Q101 {
	
// Some insights on solving equations using matrices: http://www.intmath.com/matrices-determinants/1-determinants.php
	
//	public static void main(String[] args) {
//		List<Integer> series = new ArrayList<Integer>();
//		for(int i = 1; i <= 11; i++) {
//			int tobeadd = 1;
//			for(int j = 1; j <= 10; j++) {
//				if(j % 2 == 1)
//					tobeadd -= (int) Math.pow(i, j);
//				else
//					tobeadd += (int) Math.pow(i, j);
//			}
//			series.add(tobeadd);
//		}
//		int result = 1;
//		for(int i = 2; i <= 10; i++) {
//			int[][] grid = new int[i][i+1];
//			for(int j = 0; j < i; j++) {
//				for(int k = 0; k < i+1; k++) {
//					if(k != i)
//						grid[j][k] = (int) Math.pow(j+1, i-k);
//					else
//						grid[j][k] = series.get(j);
//				}
//			}
//			int[] coeff = generatecoeff(grid);
//			int sum = 0;
//			for(int j = 0; j < coeff.length; j++) {
//				int currentcoeff = coeff[j];
//				sum += currentcoeff * (int) Math.pow(i+1, i-j);
//			}
//			result += sum;
//		}
//		System.out.println(result);
//	}
//	
//	public static int determinant(int[][] grid) {
//		int side = grid.length;
//		if(side == 2)
//			return grid[0][0] * grid[1][1] - grid[0][1] * grid[1][0];
//		else {
//			int result = 0;
//			for(int i = 0; i < side; i++) {
//				int[][] newgrid = new int[side-1][side-1];
//				for(int j = 1; j < side; j++) {
//					for(int k = 0; k < side; k++) {
//						if(k == i)
//							continue;
//						if(k < i)
//							newgrid[j-1][k] = grid[j][k];
//						else
//							newgrid[j-1][k-1] = grid[j][k];
//					}
//				}
//				if(i % 2 == 0)
//					result += grid[0][i] * determinant(newgrid);
//				else
//					result -= grid[0][i] * determinant(newgrid);
//			}
//			return result;
//		}
//	}
//	
//	public static int[] generatecoeff(int[][] grid) {
//		int size = grid.length;
//		int determinant = determinant(cutgrid(grid, size));
//		int[] result = new int[size];
//		for(int i = 0; i < size; i++) {
//			int determinanttop = determinant(cutgrid(grid, i));
//			result[i] = determinanttop / determinant;
//		}
//		return result;
//	}
//	
//	public static int[][] cutgrid(int[][] grid, int col) {
//		int side = grid.length;
//		int[][] result = new int[side][side];
//		for(int i = 0; i < side; i++) {
//			for(int j = 0; j < side+1; j++) {
//				if(j == col)
//					continue;
//				if(j < col)
//					result[i][j] = grid[i][j];
//				else
//					result[i][j-1] = grid[i][j];
//			}
//		}
//		return result;
//	}
//
	
// http://mathworld.wolfram.com/LagrangeInterpolatingPolynomial.html
// Lagrange Interpolating Polynomial
// A formula for a polynomial that passes through n points.
	
	public static void main(String args[]) {
		List<Double> series = new ArrayList<Double>();
		for(int i = 1; i <= 11; i++) {
			double tobeadd = 1;
			for(int j = 1; j <= 10; j++) {
				if(j % 2 == 1)
					tobeadd -= Math.pow(i, j);
				else
					tobeadd += Math.pow(i, j);
			}
			series.add(tobeadd);
		}
		double result = 0;
		for(int i = 1; i <= 10; i++) {
			for(int j = 1; j <= i; j++) {
				result += pjx(j, i+1, series.get(j-1), i);
			}
		}
		System.out.println(result);
	}
	
	public static double pjx(int j, int x, double y, int n) {
		double result = y;
		for(int i = 1; i <= n; i++) {
			if (i != j)
				result = result * ((double)(x-i))/((double)(j-i));
		}
		return result;
	}
}
