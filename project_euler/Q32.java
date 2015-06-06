import java.util.ArrayList;


public class Q32 {

	public static void main(String[] args) {
		ArrayList<String> allperm = new ArrayList<String>();
		perm("", "123456789", allperm);
		ArrayList<Integer> product = new ArrayList<Integer>();
		for (String one : allperm){
			int calculated = Integer.parseInt(one.substring(0, 3)) * Integer.parseInt(one.substring(3, 5));
			int last = Integer.parseInt(one.substring(5));
			if (calculated == last && !product.contains(last))
				product.add(last);
			int calculated2 = Integer.parseInt(one.substring(0, 1)) * Integer.parseInt(one.substring(1, 5));
			if (calculated2 == last && !product.contains(last))
				product.add(last);
		}
		int sum = 0;
		for (int one : product)
			sum += one;
		System.out.println(sum);
	}
	
	public static void perm(String beginstr, String original, ArrayList<String> list){
		if (original.length() == 2){
			list.add(beginstr + original);
			String start = original.substring(0, 1);
			String end = original.substring(1, 2);
			String add = end + start;
			list.add(beginstr + add);
		}
		else {
			for (int i = 0; i < original.length(); i++){
				String beginstradd = original.substring(i, i+1);
				String tobesorted = original.substring(0, i) + original.substring(i+1);
				perm(beginstr+beginstradd, tobesorted, list);
			}
		}
	}

}
