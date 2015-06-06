import java.util.ArrayList;


public class Q33 {


	public static void main(String[] args) {
		ArrayList<int[]> map = new ArrayList<int[]>();
		for (int i = 10 ; i < 100; i++){
			int teni = i / 10;
			int onei = i % 10;
			ArrayList<Integer> numerator = new ArrayList<Integer>();
			for (int j = 10; j < i; j++){
				int tenj = j / 10;
				int onej = j % 10;
				if (tenj == teni || tenj == onei || onej == teni || onej == onei)
					numerator.add(j);
			}
			for (int one : numerator){
				String denominator = Integer.toString(i);
				String numeratorl = Integer.toString(one);
				double convert = one;
				double originalresult = convert/i;
				double changedresult = 0;
				if (denominator.charAt(0) == numeratorl.charAt(0) && (i % 10) != 0)
					changedresult = (convert % 10) / (i % 10);
				else if (denominator.charAt(0) == numeratorl.charAt(1) && (i % 10) != 0)
					changedresult = ((double) (one / 10)) / (i % 10);
				else if (denominator.charAt(1) == numeratorl.charAt(0) && (i / 10) != 0)
					changedresult = (convert % 10) / (i / 10);
				else if (denominator.charAt(1) == numeratorl.charAt(1) && (i / 10) != 0)
					changedresult = ((double) (one / 10)) / (i / 10);
				if (originalresult == changedresult){
					int[] match = new int[2];
					match[0] = one;
					match[1] = i;
					if (i % 10 != one % 10)
					map.add(match);
				}
			}
		}
		System.out.println(map);

	}

}
