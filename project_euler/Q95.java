import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.TreeMap;


// Lessons learnt from this problem: sometimes when I try to speed up the process, it actually slows it down.
// For example, in this problem, initially I tried to eliminate all prime numbers.
// However, there are simply too many of them which consumes a lot of time when I call primelist.contains()
// Hence, it is actually faster when I just ignore this "boost".
public class Q95 {

	private TreeMap<Integer, Integer> map = new TreeMap<Integer, Integer>();

	public Q95() {
		for(int i = 1; i <= 1000000; i++) {
			int nextresult = findnext(i);
			map.put(i, nextresult);
		}
	}

	public static void main(String[] args) {
		Q95 start = new Q95();
		List<Integer> result = new ArrayList<Integer>();
		for (int i = 2; i < 1000000; i++) {
			List<Integer> current = find(i, start.map);
			int repeated = current.get(current.size() - 1);
			int index = current.indexOf(repeated);
			current = current.subList(index, current.size() - 1);
			if (current.size() > result.size()) {
				result = current;
				System.out.println(result);
			}
			System.out.println(i);
		}
		Collections.sort(result);
		System.out.println(result.get(0));
	}

	public static int findnext(int number) {
		int sum = 1;
		for(int i = 2; i <= Math.sqrt(number); i++) {
			if(number % i == 0) {
				sum += i;
				if ( i != number / i)
					sum += number / i;
			}
		}
		return sum;
	}

	public static ArrayList<Integer> find(int number, TreeMap<Integer, Integer> map) {
		ArrayList<Integer> chain = new ArrayList<Integer>();
		chain.add(number);
		int next = (Integer) map.get(number);
		outerloop:
		while(!chain.contains(next) && next < 1000000) {
			chain.add(next);
			next = (Integer) map.get(next);
			if (next > 1000000 || next == 1) {
				chain.clear();
				break outerloop;
			}
		}
		chain.add(next);
		return chain;
	}

}
