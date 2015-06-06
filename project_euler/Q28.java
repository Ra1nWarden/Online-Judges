
public class Q28 {

	public static void main(String[] args) {
		int sum = 1;
		for (int i = 2; i <= 501; i ++){
			sum += lastdigit(i) * 4 - 6 * (2 * i - 2);
		}
		System.out.println(sum);

	}
	public static int lastdigit(int number){
		if (number == 1)
			return 1;
		else return (lastdigit(number-1) + (2*number-2) * 4);
	}

}
