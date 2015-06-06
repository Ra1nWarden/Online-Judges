import java.util.ArrayList;
import java.util.Collections;


public class Q93 {
	
	public static void main(String args[]) {
		long start = System.currentTimeMillis();
		ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i <= 6; i++) {
			for (int j = i+1; j <= 7; j++) {
				for (int k = j+1; k <= 8; k++) {
					for (int l = k+1; l <= 9; l++) {
						ArrayList<Integer> tobeadded = new ArrayList<Integer>();
						tobeadded.add(i);
						tobeadded.add(j);
						tobeadded.add(k);
						tobeadded.add(l);
						list.add(tobeadded);
					}
				}
			}
		}
		ArrayList<Integer> max = new ArrayList<Integer>();
		int maxlength = 0;
		for (int i = 0; i < list.size(); i++) {
			ArrayList<Integer> currentcombi = list.get(i);
			ArrayList<ArrayList<Integer>> allperm = new ArrayList<ArrayList<Integer>>();
			perm(new ArrayList<Integer>(), currentcombi, allperm);
			int currentlength = find(allperm);
			if (currentlength > maxlength) {
				maxlength = currentlength;
				max = currentcombi;
			}
		}
		long end = System.currentTimeMillis();
		System.out.println(max);
		System.out.println(maxlength);
		System.out.println(end - start + " ms");
	}
	
	public static void perm(ArrayList<Integer> start, ArrayList<Integer> numberlist, ArrayList<ArrayList<Integer>> lists) {
		if (numberlist.size() == 1) {
			start.add(numberlist.get(0));
			lists.add(start);
		}
		else {
			for (int i = 0; i < numberlist.size(); i++) {
				ArrayList<Integer> newstart = new ArrayList<Integer>();
				for (int one : start)
					newstart.add(one);
				newstart.add(numberlist.get(i));
				ArrayList<Integer> newlist = new ArrayList<Integer>();
				for (int j = 0; j < numberlist.size(); j++){
					if (i != j)
						newlist.add(numberlist.get(j));
				}
				perm(newstart, newlist, lists);
			}
		}
	}
	
	// 1 = +
	// 2 = -
	// 3 = *
	// 4 = /
	
	// 1 = a a a a
	// 2 = a (a a) a
	// 3 = a a (a a)
	// 4 = a (a (a a))
	// 5 = a ((a a) a)
	
	public static ArrayList<Integer> calculate(ArrayList<Integer> currentperm) {
		ArrayList<int[]> operations = new ArrayList<int[]>();
		for (int i = 1; i < 5; i++) {
			for (int j = 1; j < 5; j++) {
				for (int k = 1; k < 5; k++) {
					for (int l = 1; l < 6; l++) {
						int[] operation = {i, j, k, l};
						operations.add(operation);
					}
				}
			}
		}
		int first = currentperm.get(0);
		int second = currentperm.get(1);
		int third = currentperm.get(2);
		int fourth = currentperm.get(3);
		ArrayList<Integer> answer = new ArrayList<Integer>();
		for (int i = 0; i < operations.size(); i++) {
			double ans = 0;
			int[] curoper = operations.get(i);
			int operate = curoper[3];
			switch(operate) {
				case 1: 
					ans = calc(first, second, curoper[0]);
					ans = calc(ans, third, curoper[1]);
					ans = calc(ans, fourth, curoper[2]);
					break;
				case 2:
					ans = calc(second, third, curoper[1]);
					ans = calc(first, ans, curoper[0]);
					ans = calc(ans, fourth, curoper[2]);
					break;
				case 3:
					ans = calc(third, fourth, curoper[2]);
					ans = calc(calc(first, second, curoper[0]), ans, curoper[1]);
					break;
				case 4:
					ans = calc(third, fourth, curoper[2]);
					ans = calc(second, ans, curoper[1]);
					ans = calc(first, ans, curoper[0]);
					break;
				case 5:
					ans = calc(second, third, curoper[1]);
					ans = calc(ans, fourth, curoper[2]);
					ans = calc(first, ans, curoper[0]);
					break;
			}
			if ((int) ans == ans && !answer.contains((int) ans) && ans > 0)
				answer.add((int) ans);
		}
		return answer;
	}
	
	public static int find(ArrayList<ArrayList<Integer>> allperm) {
		ArrayList<Integer> allpossible = new ArrayList<Integer>();
		for (ArrayList<Integer> one : allperm) {
			ArrayList<Integer> currentresult = calculate(one);
			for (int each : currentresult){
				if (!allpossible.contains(each))
					allpossible.add(each);
			}
		}
		Collections.sort(allpossible);
		int result = 0;
		for (int i = 0; i < allpossible.size(); i++) {
			if (allpossible.get(i) != i + 1) {
				result = i;
				break;
			}
		}
		return result;
	}
	
	public static double calc(double a, double b, int oper) {
		double ans = Math.PI;
		switch (oper) {
			case 1:
				ans = a + b;
				break;
			case 2:
				ans =  a - b;
				break;
			case 3:
				ans =  a * b;
				break;
			case 4:
				if (b != 0)
					ans = a / b;
				break;
		}
		return ans;
	}

}
