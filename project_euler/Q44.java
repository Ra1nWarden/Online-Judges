import java.util.ArrayList;


public class Q44 {
	/*
	public static void main(String[] args) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(1);
		for (int i = 1; i < 10000; i++){
			int last = list.size() - 1;
			list.add(i * 3 + 1 + list.get(last));
		}
		
		for (int i = 0; i < 9999; i++){
			int small = list.get(i);
			for (int j = i + 1; j < 10000; j++){
				int large = list.get(j);
				if (list.contains(large - small) && list.contains(large + small))
					System.out.println(small + ", " + large);
			}
		}
		

	}
	*/
	
	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(1);
		for (int i = 1; i < 5000; i++){
			int last = list.size() - 1;
			int next = i * 3 + 1 + list.get(last);
			if (check(next, list) != Integer.MAX_VALUE){
				long end = System.currentTimeMillis();
				System.out.println(check(next, list) + " in " + (end -start)/1000 + "s");
			}
				
			list.add(next);
		}
		

	}
	
	public static int check(int sum, ArrayList<Integer> list){
		int diff = Integer.MAX_VALUE;
		for (int i = 0; i < list.size(); i++){
			int first = list.get(i);
			int second = sum - first;
			int difference = Math.abs(first - second);
			if (list.contains(second) && list.contains(difference) && difference < diff){
				diff = difference;
			}
		}
		return diff;
	}
	

}
