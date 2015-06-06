import java.util.ArrayList;


public class Q38 {

	public static void main(String[] args) {
		long timestart = System.currentTimeMillis();
		ArrayList<String> digit = new ArrayList<String>();
		for(int i = 9; i > 0; i--){
			digit.add(Integer.toString(i));
		}
		ArrayList<String> permutate = new ArrayList<String>();
		perm("", digit, permutate);
		int index = 0;
		while(true){
			if (test(permutate.get(index)))
				break;
			index++;
		}
		long timeend =System.currentTimeMillis();
		System.out.println(permutate.get(index));
		System.out.println("Time:" + (timeend-timestart));
	}

	public static void perm(String start, ArrayList<String> digitlist, ArrayList<String> numberlist){
		int size = digitlist.size();
		if(size == 1)
				numberlist.add(start+digitlist.get(0));
		else{
			for (int i = 0; i < digitlist.size(); i++){
				String first = digitlist.get(i);
				ArrayList<String> newlist = new ArrayList<String>();
				for (int j = 0; j < digitlist.size(); j++){
					newlist.add(digitlist.get(j));
				}
				newlist.remove(i);
				perm(start+first, newlist, numberlist);
			}
		}
	}
	
	public static boolean test(String str){
		boolean found = false;
		for(int i = 1; i <= 4; i++){
			int number = Integer.parseInt(str.substring(0, i));
			int product1 = number * 2;
			int product2 = number * 3;
			int product3 = number * 4;
			int product4 = number * 5;
			String product = Integer.toString(product1) + Integer.toString(product2) + Integer.toString(product3) + Integer.toString(product4);
			if (product.substring(0, 9-i).equals(str.substring(i))){
				found = true;
				break;
			}

		}
		return found;
	}
	
}
