
public class Q78 {

	public static void main(String[] args) {
		int[] numbers = new int[100001];
		numbers[0] = 1;
		for (int i = 1; i <= 100000; i++){
			for (int j = i; j < 100001; j++){
				numbers[j] += numbers[j-i];
				numbers[j] %= 1000000;
				if (j == i){
					System.out.println(j + " " + numbers[j]);
					if(numbers[j] == 0)
						System.exit(0);
				}
			}
		}
		System.out.println("Not Found!");
	}

}
