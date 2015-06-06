import java.util.ArrayList;
import java.util.Collections;


public class Q109 {

	public static void main(String[] args) {
		ArrayList<Integer> allposs = new ArrayList<Integer>();
		for(int i = 1; i <= 20; i++) {
			allposs.add(i);
			allposs.add(i * 2);
			allposs.add(i * 3);
		}
		allposs.add(25);
		allposs.add(50);
		Collections.sort(allposs);
		
		// Single shot with a double
		int result = 21;
		
		// Double shot
		for(int i = 2; i <= 40; i+=2) {
			for(int j = 0; j < allposs.size(); j++) {
				int added = allposs.get(j);
				if(added + i < 100)
					result++;
				else
					break;
			}
		}
		
		for(int i = 0; i < allposs.size(); i++) {
			int added = allposs.get(i);
			if (added < 50)
				result++;
			else
				break;
		}
		
		// Triple shot
		for(int i = 2; i <= 40;  i+= 2) {
			for(int j = 0; j < allposs.size(); j++) {
				int first = allposs.get(j);
				if(first + i < 100) {
					for(int k = j ; k < allposs.size(); k++) {
						int second = allposs.get(k);
						if(first + second + i < 100)
							result++;
						else
							break;
					}
				}
				else
					break;
			}
		}
		
		for(int j = 0; j < allposs.size(); j++) {
			int first = allposs.get(j);
			if(first + 50 < 100) {
				for(int k = j ; k < allposs.size(); k++) {
					int second = allposs.get(k);
					if(first + second + 50 < 100)
						result++;
					else
						break;
				}
			}
			else
				break;
		}
		
		System.out.println(result);

	}

}
