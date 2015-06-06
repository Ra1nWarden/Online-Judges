import java.util.ArrayList;
import java.util.Arrays;


public class Q61 {

	public static void main(String[] args) {
		ArrayList<int[]> resultlist = new ArrayList<int[]>();
		int[] initialize = new int[6];
		for(int i = 0; i < 6; i++){
			resultlist.add(initialize);
		}
		for(int a = 10 ; a < 100; a++){
			for(int b = 10; b < 100; b++){
				int number = a*100 + b;
				if(check(number)){
					resultlist.set(0, checkresult(number));
					for(int c = 10; c < 100; c++){
						number = 100*b+c;
						if(check(number)){
							resultlist.set(1, checkresult(number));
							for(int d = 10; d < 100; d++){
								number = c * 100 + d;
								if(check(number)){
									resultlist.set(2, checkresult(number));
									for(int e = 10; e < 100; e++){
										number = 100*d + e;
										if(check(number)){
											resultlist.set(3, checkresult(number));
											for(int f = 10; f < 100; f++){
												number = e*100 + f;
												int anotherno = f*100 + a;
												if(check(number) && check(anotherno)){
													resultlist.set(4, checkresult(number));
													resultlist.set(5, checkresult(anotherno));
													if(checkfinal(resultlist))
														System.out.println(a + " " + b + " " + c + " " + d + " " + e + " " + f );
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	public static boolean checkfinal(ArrayList<int[]> resultlist){
		int[][] map = new int[6][6];
		boolean status = false;
		outerloop:
		for(int a = 0; a < 6; a++){
			for(int b = 0; b < 6; b++){
				if(b==a)
					continue;
				else{
					for(int c = 0; c < 6; c++){
						if(c == a || c == b)
							continue;
						else{
							for(int d = 0; d < 6; d++){
								if(d == a || d == b || d == c)
									continue;
								else{
									for(int e = 0; e < 6; e++){
										if(e == a || e == b || e == c || e == d)
											continue;
										else{
											for(int f = 0; f < 6; f++){
												if(f == a || f == b || f == c || f == d || f == e)
													continue;
												else{
													map[0] = resultlist.get(a);
													map[1] = resultlist.get(b);
													map[2] = resultlist.get(c);
													map[3] = resultlist.get(d);
													map[4] = resultlist.get(e);
													map[5] = resultlist.get(f);
													boolean found = true;
													for(int i = 0; i < 6; i++){
														if(map[i][i] == 0){
															found = false;
															break;
														}
													}
													if(found){
														status = true;
														break outerloop;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return status;
	}
	
	public static boolean check(int number){
		boolean status = true;
		if(!checktri(number)){
			if(!checksqu(number)){
				if(!checkpen(number)){
					if(!checkhex(number)){
						if(!checkhep(number)){
							if(!checkoct(number))
								status = false;
						}
					}
				}
			}
		}
		return status;
	}
	
	public static int[] checkresult(int number){
		int[] result = new int[6];
		Arrays.fill(result, 0);
		if(checktri(number))
			result[0] = 1;
		if(checksqu(number))
			result[1] = 1;
		if(checkpen(number))
			result[2] = 1;
		if(checkhex(number))
			result[3] = 1;
		if(checkhep(number))
			result[4] = 1;
		if(checkoct(number))
			result[5] = 1;
		return result;
	}
	
	
	public static boolean checktri(int number){
		boolean found = false;
		for(int i = 45; i <= 447; i++ ){
			if(i*(i+1)/2 == number){
				found = true;
				break;
			}
		}
		return found;
	}
	
	public static boolean checksqu(int number){
		boolean found = false;
		for(int i = 32; i <= 99; i++ ){
			if(i*i == number){
				found = true;
				break;
			}
		}
		return found;
	}
	
	public static boolean checkpen(int number){
		boolean found = false;
		for(int i = 26; i > 0; i++ ){
			int result = i*(3*i-1)/2;
			if(result >= 10000)
				break;
			else if(result == number){
				found = true;
				break;
			}
		}
		return found;
	}
	
	public static boolean checkhex(int number){
		boolean found = false;
		for(int i = 23; i > 0; i++ ){
			int result = i*(2*i-1);
			if(result >= 10000)
				break;
			else if(result == number){
				found = true;
				break;
			}
		}
		return found;
	}
	
	public static boolean checkhep(int number){
		boolean found = false;
		for(int i = 21; i > 0; i++ ){
			int result = i*(5*i-3)/2;
			if(result >= 10000)
				break;
			else if(result == number){
				found = true;
				break;
			}
		}
		return found;
	}
	
	public static boolean checkoct(int number){
		boolean found = false;
		for(int i = 19; i > 0; i++ ){
			int result = i*(3*i-2);
			if(result >= 10000)
				break;
			else if(result == number){
				found = true;
				break;
			}
		}
		return found;
	}

}
