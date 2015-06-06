import java.util.ArrayList;


public class Q41 {

	
	public static void main(String[] args) {
		ArrayList<String> digit = new ArrayList<String>();
		for(int i = 7; i > 0; i--){
			digit.add(Integer.toString(i));
		}
		ArrayList<String> permutate = new ArrayList<String>();
		perm("", digit, permutate);
		boolean found = false;
		String ans = "";
		for (int i = 0; i < permutate.size(); i++){
			if (isprime(permutate.get(i))){
				found = true;
				ans = permutate.get(i);
				break;
			}
		}
		if(found)
			System.out.println(ans);
		else
			System.out.println("Not found!");
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
	public static boolean isprime(String input){
		int number = Integer.parseInt(input);
		if (number == 1)
			return false;
		else if (number == 2)
			return true;
		else{
			boolean prime = true;
			for (int i = 2; i <= Math.sqrt(number); i++){
				if(number % i == 0){
					prime = false;
					break;
				}
			}
			return prime;
		}
	}
}
