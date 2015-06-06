import java.util.ArrayList;
import java.util.Arrays;


public class Q60 {

	public static void main(String[] args) {
		boolean[] numbers = new boolean[20000];
		Arrays.fill(numbers, true);
		numbers[0] = false;
		for(int i = 1; i < 20000; i++){
			if(numbers[i]){
				int gap = i+1;
				for(int j = i+gap; j < 20000; j+=gap)
					numbers[j] = false;
			}
		}

		ArrayList<Integer> prime = new ArrayList<Integer>();
		for(int i = 0; i < 20000; i++){
			if(numbers[i]){
				prime.add(i+1);
			}
		}

		ArrayList<Integer> r1 = new ArrayList<Integer>();
		r1.add(3);
		ArrayList<Integer> r2 = new ArrayList<Integer>();
		r2.add(3);
		for(int one : prime){
			if(one % 3 == 1)
				r1.add(one);
			if(one % 3 == 2)
				r2.add(one);
		}

		ArrayList<ArrayList> matchr1 = new ArrayList<ArrayList>();
		for(int i = 0; i < r1.size(); i++)
			matchr1.add(search(i, r1, prime));
		ArrayList<ArrayList> matchr2 = new ArrayList<ArrayList>();
		for(int i = 0; i < r2.size(); i++)
			matchr2.add(search(i, r2, prime));

		for(int a = 0; a < matchr1.size(); a++){
			int firstprime = r1.get(a);
			int indexfirst = r1.indexOf(firstprime);
			ArrayList<Integer> match1 = matchr1.get(indexfirst);
			for(int b = 0; b < match1.size(); b++){
				int secondprime = match1.get(b);
				int indexsecond = r1.indexOf(secondprime);
				ArrayList<Integer> match2 = matchr1.get(indexsecond);
				for(int c = 0; c < match2.size(); c++){
					int thirdprime = match2.get(c);
					if(!match1.contains(thirdprime))
						continue;
					else{
						int indexthird = r1.indexOf(thirdprime);
						ArrayList<Integer> match3 = matchr1.get(indexthird);
						for(int d = 0; d < match3.size(); d++){
							int fourthprime = match3.get(d);
							if(!(match1.contains(fourthprime) && match2.contains(fourthprime)))
								continue;
							else{
								int indexfourth = r1.indexOf(fourthprime);
								ArrayList<Integer> match4 = matchr1.get(indexfourth);
								for(int e = 0; e< match4.size(); e++){
									int five = match4.get(e);
									if(!(match1.contains(five) && match2.contains(five) && match3.contains(five)))
										continue;
									else{
										int sum = firstprime +  secondprime +  thirdprime +  fourthprime +  five;
										System.out.println(sum);
									}
								}
							}
						}
					}
				}
			}
		}

		for(int a = 0; a < matchr2.size(); a++){
			int firstprime = r2.get(a);
			int indexfirst = r2.indexOf(firstprime);
			ArrayList<Integer> match1 = matchr2.get(indexfirst);
			for(int b = 0; b < match1.size(); b++){
				int secondprime = match1.get(b);
				int indexsecond = r2.indexOf(secondprime);
				ArrayList<Integer> match2 = matchr2.get(indexsecond);
				for(int c = 0; c < match2.size(); c++){
					int thirdprime = match2.get(c);
					if(!match1.contains(thirdprime))
						continue;
					else{
						int indexthird = r2.indexOf(thirdprime);
						ArrayList<Integer> match3 = matchr2.get(indexthird);
						for(int d = 0; d < match3.size(); d++){
							int fourthprime = match3.get(d);
							if(!(match1.contains(fourthprime) && match2.contains(fourthprime)))
								continue;
							else{
								int indexfourth = r2.indexOf(fourthprime);
								ArrayList<Integer> match4 = matchr2.get(indexfourth);
								for(int e = 0; e< match4.size(); e++){
									int five = match4.get(e);
									if(!(match1.contains(five) && match2.contains(five) && match3.contains(five)))
										continue;
									else{
										int sum = firstprime +  secondprime +  thirdprime +  fourthprime +  five;
										System.out.println(sum);
									}

								}
							}
						}
					}
				}
			}
		}
	}

	public static boolean check(int number1, int number2, ArrayList<Integer> primes){
		String number1l = Integer.toString(number1);
		String number2l = Integer.toString(number2);
		double firstcombi = Double.parseDouble(number1l+number2l);
		double secondcombi = Double.parseDouble(number2l+number1l);
		return (isprime(firstcombi, primes) && isprime(secondcombi, primes));
	}

	public static ArrayList<Integer> search(int index, ArrayList<Integer> primelist, ArrayList<Integer> prime){
		ArrayList<Integer> result = new ArrayList<Integer>();
		int number = primelist.get(index);
		for(int i = index+1; i < primelist.size(); i++){
			int currenttest = primelist.get(i);
			if(check(number, currenttest, prime))
				result.add(currenttest);
		}
		return result;
	}

	public static boolean isprime(double number, ArrayList<Integer> primes){
		boolean status = true;
		for(int i = 0; i< primes.size(); i++){
			int currentprime = primes.get(i);
			if(currentprime > Math.sqrt(number))
				break;
			else if(number % currentprime == 0){
				status = false;
				break;
			}
		}
		return status;
	}

}
