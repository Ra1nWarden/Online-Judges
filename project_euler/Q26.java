import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;


public class Q26 {
	/*
	public static void main(String[] args) {
		ArrayList<Integer> recursion = new ArrayList<Integer>();
		for (double i = 2; i < 1000; i++){
			BigDecimal value = new BigDecimal(i);
			BigDecimal one  = new BigDecimal("1");
			BigDecimal calculated = one.divide(value, 10000, 5);
			String result = calculated.toString().substring(2);
			ArrayList<Character> digits = new ArrayList<Character>();
			int repeat = 0;
			for (int j = 0; j < result.length(); j++){
				char current = result.charAt(j);
				if (current != '0' && digits.contains(current)){
					int startposition = digits.indexOf(current);
					int endingposition = digits.size();
					int length = endingposition - startposition;
					if (endingposition + length < result.length() && result.substring(startposition, endingposition).equals(result.substring(endingposition, endingposition + length))){
						repeat = length;
						break;
					}
					else
						digits.add(current);
				}
				else
					digits.add(current);
			}
			recursion.add(repeat);
		}
		System.out.println(recursion);
		int max = 0;
		for (int one : recursion){
			if (one > max)
				max = one;
		}
		System.out.println(max);
		System.out.println(2+recursion.indexOf(max));
	}
	*/
	
	// Quote from http://projecteuler.net/thread=26;page=2
	public static void main(String[] args){
	      int max = 0;
	      int dMax = 0;
	      for(int d = 2; d < 1000; d++){
	         int r=10;					
	         ArrayList<Integer> rmndrs = new ArrayList<Integer>();		
	         int c = 0;			
	         while(!rmndrs.contains(r)){				
	            rmndrs.add(r);
	            r = 10 * (r%d);
	            c++;
	         }						
	         int cycleLength = c - rmndrs.lastIndexOf(r);			
	         if(cycleLength > max){
	            max = cycleLength;
	            dMax = d;
	         }
	      }
	      System.out.println(dMax);		
	   }
}
