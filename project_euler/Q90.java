import java.util.ArrayList;


public class Q90 {

	public static void main(String args[]) {
		ArrayList<int[]> list = new ArrayList<int[]>();
		for (int i = 0; i <= 4; i++) {
			for (int j = i+1; j <= 5; j++) {
				for (int k = j+1; k <=6; k++) {
					for (int l = k+1; l <=7; l++) {
						for (int m = l+1; m <=8; m++) {
							for (int n = m+1; n <=9; n++) {
								int[] tobeadded = {i,j,k,l,m,n};
								list.add(tobeadded);
							}
						}
					}
				}
			}
		}
		int count = 0;
		for (int i = 0; i < list.size() - 1; i++) {
			for (int j = i + 1; j < list.size(); j++) {
				int[] firstarray = list.get(i);
				int[] secondarray = list.get(j);
				if (checkvalid(firstarray, secondarray)) {
					count++;
					System.out.println(print(firstarray));
					System.out.println(print(secondarray));
				}	
			}
		}
		System.out.println(count);
	}
	
	public static boolean check(int[] array1, int[] array2, int doubledigit) {
		int ten = doubledigit / 10;
		int one = doubledigit % 10;
		if (one == 6 || one == 9) {
			boolean found = false;
			if (contain(array1, 6) || contain(array1, 9)) {
				if(!found)
					found =  contain(array2, ten);
			}
			if (contain(array2, 6) || contain(array2, 9)) {
				if(!found)
					found = contain(array1, ten);
			}
			return found;
		}
		else {
			boolean found = false;
			if (contain(array1, ten))
				if(!found)
					found = contain(array2, one);
			if (contain(array1, one))
				if(!found)
					found = contain(array2, ten);
			return found;
		}
	}
	
	public static boolean checkvalid(int[] array1, int[] array2) {
		int[] doublelist = {1, 4, 9, 16, 25, 36, 49, 81};
		boolean result = true;
		for (int i = 0; i < doublelist.length; i++) {
			if (!check(array1, array2, doublelist[i])) {
				result = false;
				break;
			}
		}
		return result;
	}
	
	public static String print(int[] array) {
		String result = "";
		for (int i = 0; i < array.length; i++) {
			result += Integer.toString(array[i]);
		}
		return result;
	}
	
	public static boolean contain(int[] array, int number) {
		boolean found = false;
		for (int i = 0; i < array.length; i++) {
			if (array[i] == number) {
				found = true;
				break;
			}
		}
		return found;
	}
}
