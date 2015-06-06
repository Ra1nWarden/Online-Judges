import java.util.ArrayList;


public class Q19 {

	public static void main(String[] args) {
		Year nineteenhundred = new Year(1900, 1);
		int firstdayofnext = nineteenhundred.getNextfirstday();
		ArrayList<Year> nineteenth = new ArrayList<Year>();
		for (int i = 1; i < 101; i++){
			Year currentyear = new Year(1900+i, firstdayofnext);
			nineteenth.add(currentyear);
			firstdayofnext = currentyear.getNextfirstday();
		}
		int sum = 0;
		for (Year one : nineteenth){
			sum += one.numberofsunday();
		}
		System.out.println(sum);
	}

}
