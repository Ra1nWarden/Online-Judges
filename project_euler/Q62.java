import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;


public class Q62 {

	public static void main(String[] args) {
		int size = 1;
		while(true){
			ArrayList<BigInteger> list = generatelist(size);
			BigInteger result = findfive(list);
			if(!result.equals(new BigInteger("0"))){
				System.out.println(result);
				System.exit(0);
			}
			size++;
		}
	}
	
	public static ArrayList<BigInteger> generatelist(int length){
		ArrayList<BigInteger> result = new ArrayList<BigInteger>();
		BigInteger one = new BigInteger("1");
		while(true){
			BigInteger powered = one.pow(3);
			int currentlength = powered.toString().length();
			if(currentlength == length){
				result.add(powered);
			}
			if(currentlength > length)
				break;
			one = one.add(new BigInteger("1"));
		}
		return result;
	}
	
	public static BigInteger findfive(ArrayList<BigInteger> list){
		BigInteger result = new BigInteger("0");
		boolean found = false;
		for(int i = 0; i < list.size()-4; i++){
			BigInteger current = list.get(i);
			int count = 0;
			for(int j = i + 1; j < list.size(); j++){
				BigInteger compared = list.get(j);
				if(checkperm(current,compared))
					count++;
			}
			if(count == 4){
				found = true;
				result = current;
				break;
			}
		}
		return result;
	}
	
	public static boolean checkperm(BigInteger one, BigInteger two){
		String first = one.toString();
		String second = two.toString();
		int[] index = new int[first.length()];
		Arrays.fill(index, 0);
		boolean status = true;
		for(int i = 0; i < first.length(); i++){
			char current = first.charAt(i);
			boolean found = false;
			for(int j = 0; j < second.length(); j++){
				char compared = second.charAt(j);
				if(index[j] == 0 && compared == current){
					index[j] = 1;
					found = true;
					break;
				}
			}
			if(!found){
				status = false;
				break;
			}		
		}
		return status;
	}
	
	

}
