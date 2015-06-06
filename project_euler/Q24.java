import java.util.ArrayList;


public class Q24 {

	public static void main(String[] args) {
		int target = 1000000;
		int index = 9;
		ArrayList<Integer> indexlist = new ArrayList<Integer>();
		while (target > 0){
			int reduce = factorial(index);
			for (int i = 1; i > 0; i++){
				if (i * reduce > target){
					indexlist.add(i-1);
					target -= reduce * (i-1);
					break;
				}
			}
		index--;
		}
		
		System.out.println(indexlist);
		ArrayList<Integer> numberlist = new ArrayList<Integer>();
		for (int i = 0; i < 10; i++)
			numberlist.add(i);
		String answer = "";
		for (int i = 0; i < indexlist.size(); i++){
			int singleindex = indexlist.get(i);
			int digit = numberlist.get(singleindex);
			answer += Integer.toString(digit);
			numberlist.remove(singleindex);
		}
		System.out.println(answer);
	}
	
	public static int factorial(int number){
		if (number == 0 || number == 1)
			return 1;
		else return number*factorial(number-1);
	}

}
