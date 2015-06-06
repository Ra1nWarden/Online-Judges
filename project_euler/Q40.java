
public class Q40 {


	public static void main(String[] args) {
		System.out.println(digit(1));
		System.out.println(digit(10));
		System.out.println(digit(100));
		System.out.println(digit(1000));
		System.out.println(digit(10000));
		System.out.println(digit(100000));
		System.out.println(digit(1000000));
	}
	public static double length(int length){
		return (Math.pow(10, length) - Math.pow(10, length-1)) * length;
	}
	
	public static int digit(double count){
		int size = 1;
		while(count > 0){
			count -= length(size);
			size++;
		}
		int result = size - 1;
		count += length(size - 1);
		int least = (int) Math.pow(10, result-1);
		for (int i = least; count > 0; i++){
			count -= (size - 1);
			result = i;
		}
		count += (size - 1);
		String ans = Integer.toString(result);
		
		return Integer.parseInt(ans.substring((int) (count-1), (int) count));
	}
}
