import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Q59 {
    public static void main(String[] args) throws Exception{
    	File txt = new File("/Users/zihaowang/Desktop/cipher1.txt");
    	Scanner reader = new Scanner(txt);
    	String line = reader.nextLine();
    	System.out.println(line);
    	String[] splitted = line.split(",");
    	ArrayList<Integer> first = new ArrayList<Integer>();
    	ArrayList<Integer> second = new ArrayList<Integer>();
    	ArrayList<Integer> third = new ArrayList<Integer>();
    	for(int i = 0; i < splitted.length; i++){
    		int current = Integer.parseInt(splitted[i]);
    		if(i % 3 == 0)
    			first.add(current);
    		else if(i % 3 == 1)
    			second.add(current);
    		else if(i % 3 == 2)
    			third.add(current);
    	}
    	
    	int firstkey = findkey(first);
    	int secondkey = findkey(second);
    	int thirdkey = findkey(third);
    	
    	double totalsum = 0;
    	for(int one : first)
    		totalsum += cipher(one, firstkey);
    	for(int one : second)
    		totalsum += cipher(one, secondkey);
    	for(int one : third)
    		totalsum += cipher(one, thirdkey);
    	System.out.println(totalsum);	
  
    }
    
    public static double cipher(int code, int key){
    	String codeinbi = Integer.toBinaryString(code);
    	String keyinbi = Integer.toBinaryString(key);
    	while(codeinbi.length() != 7){
    		codeinbi = "0" + codeinbi;
    	}
    	while(keyinbi.length() != 7){
    		keyinbi = "0" + keyinbi;
    	}
    	String ans = "";
    	for(int i = 6; i >=0; i--){
    		if(codeinbi.charAt(i) != keyinbi.charAt(i))
    			ans = "1" + ans;
    		else
    			ans = "0" + ans;
    	}
    	double returnvalue = 0;
    	for(int i = 6; i >= 0; i--){
    		int digit = Integer.parseInt(ans.substring(i, i+1));
    		returnvalue += digit*Math.pow(2,6-i);
    	}
    	return returnvalue;
    }
    
    public static int findkey(ArrayList<Integer> list){
    	int maxcount = 0;
    	int maxkey = 0;
    	for(int i = 97; i <= 122; i++){
    		int count = 0;
    		for(int one: list){
    			if(cipher(one, i) == 32)
    				count++;
    		}
    		if(count>maxcount){
    			maxcount=count;
    			maxkey = i;
    		}
    	}
    	return maxkey;
    }
}
