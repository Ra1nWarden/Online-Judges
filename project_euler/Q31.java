
public class Q31 {

	public static void main(String[] args) {
		int remaining = 200;
		int count = 1;
		for (int a = 0; a <= 2; a++){
			for (int b = 0; remaining - b*50 - a*100 >= 0; b++){
				for (int c = 0; remaining - c*20 - b*50 - a*100 >=0; c++){
					for (int d = 0; remaining - d*10 - c*20 - b*50 - a*100 >= 0; d++){
						for (int e = 0; remaining - e*5 - d*10 - c*20 - b*50 - a*100 >= 0; e++){
							for (int f = 0; remaining - f*2 - e*5 - d*10 - c*20 - b*50 - a*100>= 0; f++){
								count++;
							}
						}
					}
				}
			}
		}
		System.out.println(count);
	}

}
