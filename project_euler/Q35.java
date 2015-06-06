import java.util.ArrayList;


public class Q35 {

	public static void main(String[] args) {
		ArrayList<Integer> primelist = new ArrayList<Integer>();
		primelist.add(2);
		for (int i = 3; i < 1000000; i++){
			boolean prime = true;
			for (int one : primelist){
				if (one > Math.sqrt(i))
					break;
				if (i % one == 0){
					prime = false;
					break;
				}
			}
			if (prime)
				primelist.add(i);
		}
		int count = 0;
		for (int one : primelist){
			String oneinl= Integer.toString(one);
			boolean circular = true;
			for (int i = 0; i < oneinl.length(); i++){
				int newint = Integer.parseInt(oneinl.substring(i)+oneinl.substring(0, i));
				if (!primelist.contains(newint)){
					circular = false;
					break;
				}
			}
			if (circular)
				count++;
		}
		System.out.println(count);
	}
}
