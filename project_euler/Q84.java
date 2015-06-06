import java.util.Arrays;
import java.util.Random;


public class Q84 {
	
	public static void main(String[] args) throws Exception {
		Monopoly game = new Monopoly();
		Random dice1 = new Random();
		Random dice2 = new Random();
		int doublecount = 0;
		int[] gridcount = new int[40];
		Arrays.fill(gridcount, 0);
		for(int i = 0; i <1000000; i++){
			int first = dice1.nextInt(4) + 1;
			int second = dice2.nextInt(4) + 1;
			if (first == second)
				doublecount++;
			else
				doublecount = 0;
			
			if (doublecount == 3) {
				game.setCurrentpo(10);
				gridcount[10]++;
				doublecount = 0;
			}
			else {
				int nextpo = game.advance(first + second);
				gridcount[nextpo]++;
			}
		}
		for(int i = 0; i < 40; i++){
			System.out.println(i + " " + gridcount[i]);
		}
	}

}
