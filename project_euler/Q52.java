
public class Q52 {


	public static void main(String[] args) {
		for (int i = 1; i > 0; i++){
			if(checkdigit(i,2*i)){
				if(checkdigit(i,3*i)){
					if(checkdigit(i,4*i)){
						if(checkdigit(i,5*i)){
							if(checkdigit(i,6*i)){
								System.out.println(i);
								System.exit(0);
							}
						}
					}
				}
			}
		}

	}
	
	public static boolean checkdigit(int number1, int number2){
		String number1inl = Integer.toString(number1);
		String number2inl = Integer.toString(number2);
		if (number1inl.length() != number2inl.length())
			return false;
		else {
			boolean status = true;
			for (int i = 0; i < number1inl.length(); i++){
				String current = number1inl.substring(i, i+1);
				if (!number2inl.contains(current)){
					status = false;
					break;
				}
			}
			return status;
		}
	}

}
