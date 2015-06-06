import java.util.ArrayList;


public class Q37 {

	public static void main(String[] args) {
		int count = 11;
		ArrayList<String> target = new ArrayList<String>();
		ArrayList<String> numbers = new ArrayList<String>();
		numbers.add("1");
		numbers.add("3");
		numbers.add("7");
		while (count > 0){
			generate(numbers);
			for (String one : numbers){
				if (checkprop(one)){
					target.add(one);
					count--;
				}
			}
		}
		System.out.println(target);
		int sum = 0;
		for (String one : target)
			sum += Integer.parseInt(one);
		System.out.println(sum);
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
	
	public static boolean checkprop(String input){
		boolean status = true;
		for (int i = 0; i < input.length(); i++){
			if (!isprime(input.substring(i))){
				status = false;
				break;
			}
			if (!isprime(input.substring(0, input.length()-i))){
				status = false;
				break;
			}
		}
		return status;
	}
	
	public static void generate(ArrayList<String> numbers){
		int length = numbers.size();
		for (int i = 0; i < length; i++){
			String current = numbers.get(i);
			numbers.set(i, "1"+current);
			numbers.add("3"+current);
			numbers.add("2"+current);
			numbers.add("7"+current);
			numbers.add("5"+current);
			numbers.add("9"+current);
		}
		
		
	}
	
	
}
