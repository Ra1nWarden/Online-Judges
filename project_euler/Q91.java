import java.util.ArrayList;


public class Q91 {
	
	public static void main(String args[]) {
		int size = 50;
		ArrayList<GridPoint> points = new ArrayList<GridPoint>();
		for (int y = 0; y <= size; y++) {
			for (int x = 0; x <= size; x++) {
				points.add(new GridPoint(x, y));
			}
		}
		int count = 0;
		for (int i = 1; i < points.size() - 1; i ++) {
			GridPoint p1 = points.get(i);
			for (int j = i + 1; j < points.size(); j++) {
				GridPoint p2 = points.get(j);
				if (p1.check(p2)) {
					System.out.println(p1 + " " + p2);
					count++;
				}
			}
		}
		System.out.println(count);
	}

}
